#include <string.h>
#include "stm32g4xx_hal.h"
#include "stm32g_can.h"

/*

*/
static void (*can_rcv_cb)(const can_msg_t *message);
// static uint16_t RxBufferIdx = 0;
static FDCAN_HandleTypeDef *fdcan_handle;

/**
 * @brief Initialize CAN
 * @param handle: pointer to FDCAN handle
 * @param receive_callback: pointer to user defined callback function to be called when a CAN message is received
 * @return True: if initialization was successful, false otherwise

Remebers what perpiferals and function to call when CAN is used and to enable intrrupts 
*/
bool stm32g4_can_init(FDCAN_HandleTypeDef *handle,
					  void (*receive_callback)(const can_msg_t *message)) {
	// bind user callback function and fdcan handle
	can_rcv_cb = receive_callback;
	fdcan_handle = handle;

	// Enable new message interrupts on Rx FIFO0
	if (HAL_FDCAN_ActivateNotification(handle, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
		// Error_Handler();
		// TODO: report error to log
	}

	return HAL_FDCAN_Start(handle) == HAL_OK;
}


/**
 * @brief CAN RX FIFO callback function when a new CAN message arrives
 * @param hfdcan: pointer to FDCAN handle
 * @param RxFifo0ITs: interrupt status flags for Rx FIFO0
 * @returns void (techically stores the new CAN message to read)

When a new CAN message is recived this fucntions checks if its a new message, and take that
out of the FIFO and store in a strct for the user to then read the message data and ID. 
Then it calls the user defined callback function to process the message
*/

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
	// variables to store Rx data
	FDCAN_RxHeaderTypeDef RxHeader;
	uint8_t RxData[8];

	// Check is there a new CAN message
	if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
		/* Retreive Rx messages from RX FIFO0 */
		if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK) {
			/* Reception Error */
			// Error_Handler();
			// TODO: handle reception error
		}

		/*if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
		   Notification Error
		  Error_Handler();
		}*/
	}
	can_msg_t rcvd_msg;
	rcvd_msg.data_len = RxHeader.DataLength; // For CAN 2.0 message FDCAN_DLC equals to actual length
	rcvd_msg.sid = RxHeader.Identifier;
	memcpy(rcvd_msg.data, RxData, rcvd_msg.data_len);
	can_rcv_cb(&rcvd_msg);
}


/**
 * @brief Send a CAN message
 * @param message: pointer to CAN message struct containing the ID, data length and data to be sent
 * @return true if message was successfully added to Tx FIFO, false otherwise

 * Checks if the BUS has entered an off states, if it isnt then it creates a TX header of a 29-bit ID 
 * CAN message and adds the message to TX FIFO to be sent 


*/
bool stm32g4_can_send(const can_msg_t *message) {
	// Reinit the CAN module if a bus off state was detected
	FDCAN_ProtocolStatusTypeDef protocolStatus = {};
	HAL_FDCAN_GetProtocolStatus(fdcan_handle, &protocolStatus);
	if (protocolStatus.BusOff) {
		CLEAR_BIT(fdcan_handle->Instance->CCCR, FDCAN_CCCR_INIT);
	}

	FDCAN_TxHeaderTypeDef TxHeader;
	uint8_t TxData[8] = {0};

	TxHeader.IdType = FDCAN_EXTENDED_ID;
	TxHeader.TxFrameType = FDCAN_DATA_FRAME;
	TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
	TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
	TxHeader.DataLength =
		message->data_len; // For CAN 2.0 message FDCAN_DLC equals to actual length
	TxHeader.MessageMarker = 0;
	TxHeader.Identifier = message->sid;

	memcpy(TxData, message->data, message->data_len);

	if (HAL_FDCAN_AddMessageToTxFifoQ(fdcan_handle, &TxHeader, TxData) != HAL_OK) {
		return false;
	}
	return true;
}

/**
 * @brief Check if CAN is ready to send a message
 * @return true if there is space in the Tx FIFO to add a new message, false otherwise
 */
bool stm32g4_can_send_rdy(void) {
	return HAL_FDCAN_GetTxFifoFreeLevel(fdcan_handle) > 0;
}

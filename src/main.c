
#include "main.h"
#include "system_clock_config.h"
#include "mx_adc_init.h"
#include "mx_spi_init.h"
#include "mx_tim1_init.h"
#include "mx_fdcan1_init.h"
#include "GPIO_init.h"
#include "blinky_flick.h"
#include "SPI_ADC.h"
#include "stm32g4xx_hal_fdcan.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"
#include "can.h"
#include "stm32g_can.h"
#include "can_storage.h"
#include "CAN_shortcuts.h"
#include "SPI.h"
 

int main(void) {

    // Initazaltion code dont touch
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_TIM1_Init();
    MX_FDCAN1_Init();
    MX_SPI1_Init();

    // SPI_ADC_INIT(); // To test
    
    // Initialize CAN with receive callback
    stm32g4_can_init(&hfdcan1, my_recive_callback); 

    
    while (1) {
         SPI_SendCommand(0x63);
      
        // blinky_flick();
        // HAL_Delay(10);
        // SPI_SendCommand(DEBUG_SPI_ADC);

        // can_msg_t msg;
        // msg.sid = can_sid_test;
        // msg.data_len = can_data_len_test;
        // msg.data[0] = can_data_test;

        // if (stm32g4_can_send_rdy()){
        //     bool ok = stm32g4_can_send(&msg);
        //     if (!ok) {
        //         // Handle transmission error
        //         Error_Handler();
        //     }
        // }
        
        
    }
     
    
 

    return 0;



}

void Error_Handler(void) {
    // Signal error by toggling LED rapidly
    while (1) {
        HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
        HAL_Delay(100);  
        HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
        HAL_Delay(100);
    }
}


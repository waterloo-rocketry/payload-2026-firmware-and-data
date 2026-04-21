#include "SPI_ADC.h"
#include "SPI.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"

extern SPI_HandleTypeDef hspi1;

uint8_t WRITE_FAST_COMMAND = (ADC_DEVICE_ADRESS << 6) | (Fast_Command<< 2) | (Incremental_Write);
// uint8_t WRITE_TO_REGISTER_0 = (ADC_DEVICE_ADRESS << 6) | (REG_CONFIG0 << 2) | Incremental_Write; // 
// uint8_t WRITE_TO_REGISTER_1 = (ADC_DEVICE_ADRESS << 6) | (REG_CONFIG1 << 2) | Incremental_Write; // 
// uint8_t WRITE_TO_REGISTER_2 = (ADC_DEVICE_ADRESS << 6) | (REG_CONFIG2 << 2) | Incremental_Write; // 
uint8_t WRITE_TO_REGISTER_3 = (ADC_DEVICE_ADRESS << 6) | (REG_CONFIG3 << 2) | Incremental_Write; //     
uint8_t WRITE_TO_REGISTER_IRQ = (ADC_DEVICE_ADRESS << 6) | (REG_IRQ << 2) | Incremental_Write; //

/**
 * @brief Initialize SPI ADC
 * @returns void 
 */
void SPI_ADC_INIT(void) {


// CONFIG0-2 has not values changed, possible removable for optimization? (all 8 bits)
// #define CONFIG0_VALUE = 0x0; 
// #define CONFIG1_VALUE = 0xC; 
// #define CONFIG2_VALUE = 0xB;

uint8_t CONFIG3_VALUE = 0x40;
uint8_t IRQ = 0x77;

// Start communcation with ADC

PULL_ADC_CS_LOW();
SPI_SendCommand(WRITE_TO_REGISTER_3);
SPI_SendCommand(CONFIG3_VALUE);
PULL_ADC_CS_HIGH();

PULL_ADC_CS_LOW();
SPI_SendCommand(WRITE_TO_REGISTER_IRQ);
SPI_SendCommand(IRQ);
PULL_ADC_CS_HIGH();

}

void START_SPI_Sample(void) {
    SPI_SendCommand(WRITE_FAST_COMMAND);
    

}
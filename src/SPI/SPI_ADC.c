
#include "SPI_ADC.h"
#include "stdint.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"
#include "stdint.h"

extern SPI_HandleTypeDef hspi1;


void SPI_ADC_SendCommand(uint8_t cmd) {
    HAL_StatusTypeDef status;
    uint8_t data = cmd;
    status = HAL_SPI_Transmit(&hspi1, (uint8_t *)&data, sizeof(data), 1000);
    
    if (status != HAL_OK) {
        // Handle error
    }
}
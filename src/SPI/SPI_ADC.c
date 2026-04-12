
#include "SPI_ADC.h"
#include "stdint.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"
#include "stdint.h"
#include "main.h"


extern SPI_HandleTypeDef hspi1;


void SPI_ADC_SendCommand(uint8_t cmd) {
    HAL_StatusTypeDef status;
    uint8_t data = cmd;
    
    // Turn LED on before transmission
    HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_RESET);
    
    status = HAL_SPI_Transmit(&hspi1, (uint8_t *)&data, sizeof(data), 1000);
    
    // Turn LED off after transmission
    HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);
    
    if (status != HAL_OK) {
        // Handle error
        Error_Handler();
    }
}
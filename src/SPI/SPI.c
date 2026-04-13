#include "stdint.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"
#include "stdint.h"
#include "main.h"
#include "SPI.h"

extern SPI_HandleTypeDef hspi1;


void SPI_SendCommand(uint8_t cmd) {
    HAL_StatusTypeDef status;
    uint8_t data = cmd;
    
    // Turn LED on before transmission
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_Delay(1000); // Short delay to ensure LED state is visible before transmission
    
    status = HAL_SPI_Transmit(&hspi1, (uint8_t *)&data, sizeof(data), 1000);

    // Turn LED off after transmission
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    
    if (status != HAL_OK) {
        // Handle error
        Error_Handler();
    } 
}

void SPI_ReceiveData(uint8_t *buffer, uint16_t size) {
    HAL_StatusTypeDef status;
    
    // Turn LED on before reception
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_Delay(1000); 
    
    status = HAL_SPI_Receive(&hspi1, buffer, size, 1000);

    // Turn LED off after reception
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    
    if (status != HAL_OK) {
        // Handle error
        Error_Handler();
    } 
}






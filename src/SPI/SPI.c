#include "stdint.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"
#include "stdint.h"
#include "main.h"
#include "SPI.h"
#include "blinky_flick.h"

extern SPI_HandleTypeDef hspi1;


void SPI_SendCommand(uint8_t cmd) {
    HAL_StatusTypeDef status;
    uint8_t data = cmd;
    
    // Turn LED on before transmission
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_Delay(10); // Short delay to ensure LED state is visible before transmission
    
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
    HAL_Delay(10); 
    
    status = HAL_SPI_Receive(&hspi1, buffer, size, 1000);

    // Turn LED off after reception
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    
    if (status != HAL_OK) {
        // Handle error
        Error_Handler();
    } 
}



// Functions to control chip select lines for ADC,DAC and SD card 
// High is no communcation, low is communcation, by default all CS lines are high 


void Pull_ADC_CS_LOW(void) {
    HAL_GPIO_WritePin(SPI_CS_ADC_GPIO_Port, SPI_CS_ADC_Pin, GPIO_PIN_RESET);
    blinky_flick_fast_L2();
}

void Pull_ADC_CS_HIGH(void) {
    HAL_GPIO_WritePin(SPI_CS_ADC_GPIO_Port, SPI_CS_ADC_Pin, GPIO_PIN_SET);
    blinky_flick_fast_L2();
}

void Pull_DAC_CS_LOW(void) {
    HAL_GPIO_WritePin(CS_DAC_GPIO_Port, CS_DAC_Pin, GPIO_PIN_RESET);
    blinky_flick_fast_L2();
}

void Pull_DAC_CS_HIGH(void) {
    HAL_GPIO_WritePin(CS_DAC_GPIO_Port, CS_DAC_Pin, GPIO_PIN_SET);
    blinky_flick_fast_L2();
}

void Pull_SD_CS_LOW(void) {
    HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET);
    blinky_flick_fast_L2();
}

void Pull_SD_CS_HIGH(void) {
    HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);
    blinky_flick_fast_L2();
}

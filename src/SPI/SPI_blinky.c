#include "SPI_ADC.h"
#include "main.h"
#include "stm32g4xx_hal.h"

void SPI_BLINKY(void) {
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET); 
    HAL_Delay(500);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
}

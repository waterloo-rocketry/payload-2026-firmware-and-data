#include "main.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_gpio.h"
#include "main.h"



void blinky_flick(void) {
    while (1) {
        // toggle LED
        switch (HAL_GPIO_ReadPin(LED2_GPIO_Port, LED2_Pin)) {
            case GPIO_PIN_RESET:
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
                break;
            case GPIO_PIN_SET:
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
                break;
        }
        HAL_Delay(500);
    }
}
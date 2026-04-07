
#include "main.h"
#include "system_clock_config.h"
#include "mx_adc_init.h"
#include "mx_spi_init.h"
#include "mx_tim1_init.h"
#include "mx_fdcan1_init.h"
#include "GPIO_init.h"

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_SPI1_Init();
    MX_TIM1_Init();
    MX_FDCAN1_Init();

    // pull down on LED
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);

    while (1) {
        // toggle LED
        switch (HAL_GPIO_ReadPin(LED1_GPIO_Port, LED1_Pin)) {
            case GPIO_PIN_RESET:
                HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
                break;
            case GPIO_PIN_SET:
                HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
                break;
        }
        HAL_Delay(500);
    }


    return 0;



}

void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* USER CODE END Error_Handler_Debug */
}


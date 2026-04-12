
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
#include "stm32g_can.h"


int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_SPI1_Init();
    MX_TIM1_Init();
    MX_FDCAN1_Init();
    
    // Initialize CAN with receive callback
    stm32g4_can_init()

    while (1) {
        // blinky_flick();
        HAL_Delay(1000);
        SPI_ADC_SendCommand(DEBUG_SPI_ADC);
        
    }
     
    
 

    return 0;



}

void Error_Handler(void) {
    // Signal error by toggling LED rapidly
    while (1) {
        HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
        HAL_Delay(100);  
    }
}


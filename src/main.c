
#include "main.h"
#include "system_clock_config.h"
#include "mx_adc_init.h"
#include "mx_spi_init.h"
#include "mx_tim1_init.h"
#include "mx_fdcan1_init.h"
#include "GPIO_init.h"
#include "blinky_flick.h"
#include "SPI_ADC.h"

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_SPI1_Init();
    MX_TIM1_Init();
    MX_FDCAN1_Init();
    

    while (1) {
        // blinky_flick();
        HAL_Delay(1000);
        SPI_ADC_SendCommand(ADC_CMD_CONVERSION_START);
        
    }
 

    return 0;



}

void Error_Handler(void) {
 // Add debug code
}


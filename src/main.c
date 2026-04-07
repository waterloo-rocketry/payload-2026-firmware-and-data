
#include "main.h"
#include "hal_init.c"
#include "system_clock_config.c"
#include "mx_adc_init.c"
#include "mx_spi_init.c"
#include "mx_tim1_init.c"
#include "mx_fdcan1_init.c"

#include "GPIO_init.c"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);
static void MX_FDCAN1_Init(void);

void main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_SPI1_Init();
    MX_TIM1_Init();
    MX_FDCAN1_Init();


}


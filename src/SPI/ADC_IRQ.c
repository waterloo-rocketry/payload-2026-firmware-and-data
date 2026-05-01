#include "stm32g4xx_hal.h"
#include "ADC_IRQ.h"
#include "SPI.h"
#include "SPI_ADC.h"
#include "main.h"

void Handle_ADC_IRQ(void) {
    // This function will be called when the ADC interrupt occurs
    // You can add code here to read the ADC value, process it, or set flags for the main loop

    PULL_ADC_CS_LOW();
    HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)&SEND_DATA_COMMAND, buffer, 4, 1000);
    PULL_ADC_CS_HIGH();

}




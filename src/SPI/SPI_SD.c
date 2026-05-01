#include "stm32g4xx_hal.h" /* Provide the low-level HAL functions */
#include "user_diskio_spi.h"
#include "app_fatfs.h"
#include "SPI_SD.h"
#include "SPI.h"


void SD_initialize(void) {
    PULL_SD_CS_LOW();   
    USER_SPI_initialize(0);
    PULL_SD_CS_HIGH();
}


DRESULT WRITE_TO_SD(uint8_t *buffer, uint8_t size) {
    DRESULT STAT;

    PULL_SD_CS_LOW();
    STAT = USER_SPI_write(0, buffer, 0, size);

    if (STAT != RES_OK) {
        // Handle error
        Error_Handler();
    }

    PULL_SD_CS_HIGH();
    return STAT;

}

void FORMAT_BUFFER_TO_CSV(uint8_t *buffer) {

}

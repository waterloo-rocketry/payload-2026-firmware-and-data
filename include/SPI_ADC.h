
#ifndef SPI_ADC_H
#define SPI_ADC_H

#include <stdint.h>

#define DEBUG_SPI_ADC 0x15 // 10101
#define ADC_CMD_CONVERSION_START 0x68  01101000
#define ADC_CMD_CONVERSION_RESTART 0x68 
#define ADC_CMD_STANDBY_FAST 0x6C 
#define ADC_CMD_SHUTDOWN_FAST 0x70
#define ADC_CMD_FULL_SHUTDOWN 0x74
#define ADC_CMD_FULL_RESET 0x78 

void SPI_ADC_SendCommand(uint8_t cmd);
void SPI_BLINKY(void);

#endif 

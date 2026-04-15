#include <stdint.h>

void SPI_SendCommand(uint8_t cmd);
void SPI_ReceiveData(uint8_t *buffer, uint16_t size);
void PULL_ADC_CS_LOW(void);
void PULL_ADC_CS_HIGH(void);
void PULL_DAC_CS_LOW(void);
void PULL_DAC_CS_HIGH(void);
void PULL_SD_CS_LOW(void);
void PULL_SD_CS_HIGH(void);
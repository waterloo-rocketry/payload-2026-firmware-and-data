#include <stdint.h>

void SPI_SendCommand(uint8_t cmd);
void SPI_ReceiveData(uint8_t *buffer, uint8_t size);
void PULL_ADC_CS_LOW(void);
void PULL_ADC_CS_HIGH(void);
void PULL_DAC_CS_LOW(void);
void PULL_DAC_CS_HIGH(void);
void PULL_SD_CS_LOW(void);
void PULL_SD_CS_HIGH(void);
void MCU_SPI_INIT(void);
void START_SPI_Sample_Short(void);
void START_SPI_TRANSFER_MISO(void);
void START_SPI_Sample_Countinous(void);


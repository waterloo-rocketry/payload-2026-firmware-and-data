#include <stdint.h>

void SPI_SendCommand(uint8_t cmd);
void SPI_ReceiveData(uint8_t *buffer, uint16_t size);
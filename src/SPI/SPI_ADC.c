#include "SPI_ADC.h"
#include "SPI.h"

/**
 * @brief Initialize SPI ADC
 * @returns void 
 * Sets External digital clock
 * No current source 
 * Shutdown mode 
 * 
 * 
 */
void SPI_ADC_INIT(void) {

#define COMMUNCAIATE_WITH_REGISTER_0 = ADC_DEVICE_ADRESS << 6 | REG_CONFIG0 << 3 | 0x0; // 00000000 





}


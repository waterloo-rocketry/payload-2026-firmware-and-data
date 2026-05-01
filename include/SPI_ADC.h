

#ifndef SPI_ADC_H
#define SPI_ADC_H

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define ADC_DEVICE_ADRESS 0x1

typedef enum {
    ADC_DATA    = 0x0,
    REG_CONFIG0 = 0x1,
    REG_CONFIG1 = 0x2,
    REG_CONFIG2 = 0x3,
    REG_CONFIG3 = 0x4,
    REG_IRQ = 0x5,
} ADC_CONFIG_REG_ADDR;

typedef enum {
Fast_Command = 0x0,
Static_Read = 0x1,
Incremental_Write = 0x2,
Incremental_Read = 0x3
} ADC_COMMAND_TYPE;


typedef enum { 
    DEBUG_SPI_ADC = 0x15, // 10101
    ADC_CMD_CONVERSION_START = 0x68,  // 01101000
    ADC_CMD_CONVERSION_RESTART = 0x68,
    ADC_CMD_STANDBY_FAST = 0x6C,
    ADC_CMD_SHUTDOWN_FAST = 0x70,
    ADC_CMD_FULL_SHUTDOWN = 0x74,
    ADC_CMD_FULL_RESET = 0x78
} ADC_FAST_COMMADS;



void SPI_ADC_INIT(void);
bool SPI_ADC_Check_Config(void);


extern uint8_t WRITE_FAST_COMMAND;
extern uint8_t WRITE_TO_REGISTER_0;
extern uint8_t WRITE_TO_REGISTER_1;
extern uint8_t WRITE_TO_REGISTER_2;
extern uint8_t WRITE_TO_REGISTER_3;
extern uint8_t WRITE_TO_REGISTER_IRQ;
extern uint8_t SEND_DATA_COMMAND;

#endif 

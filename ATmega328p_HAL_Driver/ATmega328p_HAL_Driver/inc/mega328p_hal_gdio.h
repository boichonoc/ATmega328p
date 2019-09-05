/*
 * mega328p_hal_gdio.h
 *
 * Created: 14.08.2019 10:49:57
 *  Author: Евгений
 */ 


#ifndef MEGA328P_HAL_GDIO_H_
#define MEGA328P_HAL_GDIO_H_

#include "mega328p_hal_cpu.h"

#define INPUT		0
#define OUTPUT		1

#define HIGH		1
#define LOW			0

#define GDIO_PORT_B 0x05
#define GDIO_PORT_C 0x08
#define GDIO_PORT_D 0x0B

#define GDIO_DDR_B 0x04
#define GDIO_DDR_C 0x07
#define GDIO_DDR_D 0x0A

void HAL_GDIO_PORT_Init(uint8_t GDIO_PIN, uint8_t GDIO_PORT_DDR, uint8_t IN_OUT);
void HAL_GDIO_PORT_Write(uint8_t GDIO_PORT, uint8_t GDIO_PIN, uint8_t out_LVL);
uint8_t HAL_GDIO_PORT_Read(uint8_t PORT_pin);


#endif /* MEGA328P_HAL_GDIO_H_ */
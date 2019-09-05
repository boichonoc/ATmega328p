/*
 * mega328p_hal_gdio.c
 *
 * Created: 14.08.2019 10:54:09
 *  Author: Евгений
 */ 

#include "mega328p_hal_gdio.h"

void HAL_GDIO_PORT_Init(uint8_t GDIO_PIN, uint8_t GDIO_PORT_DDR, uint8_t IN_OUT)
{
	_SFR_IO8(GDIO_PORT_DDR) |= (IN_OUT  << GDIO_PIN);
}
void HAL_GDIO_PORT_Write(uint8_t GDIO_PORT, uint8_t GDIO_PIN, uint8_t out_LVL)
{
	switch(out_LVL)
	{
		case HIGH: _SFR_IO8(GDIO_PORT) |= (1 << GDIO_PIN);
			break;
		case  LOW: _SFR_IO8(GDIO_PORT) &= (0 << GDIO_PIN);
			break;
	}
}
uint8_t HAL_GDIO_PORT_Read(uint8_t PORT_pin)
{
	return PORT_pin;
}
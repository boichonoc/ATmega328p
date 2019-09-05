/*
 * mega328p_hal_cpu.c
 *
 * Created: 16.08.2019 9:25:57
 *  Author: Евгений
 */ 
#include <mega328p_hal_cpu.h>


void HAL_WDT_Disable()
{
	cli();
	wdt_reset();
	MCUSR &= ~(1<<WDRF);
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	WDTCSR = 0x00;
	sei();
}
void HAL_WDT_SetTime(uint8_t time)
{
	cli();
	wdt_reset();
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	switch ( time )
	{
		case _16MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (0<<WDP2) | (0<<WDP1) | (0<<WDP0);
			break;
		case _32MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (0<<WDP2) | (0<<WDP1) | (1<<WDP0);
			break;
		case _64MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (0<<WDP2) | (1<<WDP1) | (0<<WDP0);
			break;
		case _125MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (0<<WDP2) | (1<<WDP1) | (1<<WDP0);
			break;
		case _250MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (0<<WDP1) | (0<<WDP0);
			break;
		case _500MS:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (0<<WDP1) | (1<<WDP0);
			break;
		case _1S:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (1<<WDP1) | (0<<WDP0);
			break;
		case _2S:
				WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
			break;
		case _4S:
				WDTCSR = (1<<WDE) | (1<<WDP3) | (0<<WDP2) | (0<<WDP1) | (0<<WDP0);
			break;
		case _8S:
				WDTCSR = (1<<WDE) | (1<<WDP3) | (0<<WDP2) | (0<<WDP1) | (1<<WDP0);
			break;
	}
	sei();
}
void HAL_GlobalInterrupt(uint8_t setStatus)
{
	switch( setStatus )
	{
		case GLOBAL_INT_ON:
			{
				sei();
			}
			break;
		case GLOBAL_INT_OFF:
			{
				cli();
			}
			break;
	}
}
void HAL_GDIO_Pull_Up(uint8_t pullUpStatus)
{
	switch( pullUpStatus )
	{
		case PULL_UP_ENB:
			{
				MCUCR |= (pullUpStatus << PUD);	
			}
			break;
		case PULL_UP_DIS:
			{
				MCUCR |= (pullUpStatus << PUD);	
			}
			break;
	}
}
/*
 * mega328p_hal_cpu.h
 *
 * Created: 14.08.2019 10:51:17
 *  Author: Евгений
 */ 


#ifndef MEGA328P_HAL_CPU_H_
#define MEGA328P_HAL_CPU_H_
//------------ CPU Speed ---------------------------------------//
#define F_CPU 8000000UL											// Frequency CPU
#include <avr/io.h>												// Include i\o file
#include <util/delay.h>											// Include delay file
#include <avr/interrupt.h>										// Include interrupt
#include <avr/wdt.h>											// Include WDT
//--------------------------------------------------------------//
#define GLOBAL_INT_ON	1
#define GLOBAL_INT_OFF	0

#define PULL_UP_ENB		0
#define PULL_UP_DIS		1

#define _16MS			0
#define _32MS			1
#define _64MS			2
#define _125MS			3
#define _250MS			4
#define _500MS			5
#define _1S				6
#define _2S				7
#define _4S				8
#define _8S				9

void HAL_WDT_Disable();
void HAL_WDT_SetTime(uint8_t time);
void HAL_GlobalInterrupt(uint8_t setStatus);
void HAL_GDIO_Pull_Up(uint8_t pullUpStatus);

#endif /* MEGA328P_HAL_CPU_H_ */
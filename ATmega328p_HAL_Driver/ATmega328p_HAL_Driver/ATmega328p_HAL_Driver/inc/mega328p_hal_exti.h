/*
 * mega328p_hal_exti.h
 *
 * Created: 14.08.2019 16:03:19
 *  Author: Евгений
 */ 


#ifndef MEGA328P_HAL_EXTI_H_
#define MEGA328P_HAL_EXTI_H_

#include <mega328p_hal_cpu.h>
//------------ External Interrupt ------------------------------//
#define BY_LOW_LVL		0										//
#define BY_ANY_CHNG		1										//
#define BY_FALLING_EDG	2										//
#define BY_RISING_ENG	3										//
//--------------------------------------------------------------//
#define INT_1			1										//
#define INT_0			0										//
#define ENABLE_EXTI		1										//
#define DISABLE_EXTI	0										//
//------------ Control Register A ------------------------------// ISC01|ISC00
#define INT0_BY_LOW_LVL()	EICRA |= (0 << ISC01)|(0 << ISC00)	//	 0	|  0	The low level of INT0 generates an interrupt request.
#define INT0_BY_ANY_CHNG()	EICRA |= (0 << ISC01)|(1 << ISC00)	//	 0  |  1	Any logical change on INT0 generates an interrupt request.
#define INT0_BY_FALL_EDG()	EICRA |= (1 << ISC01)|(0 << ISC00)	//	 1  |  0	The falling edge of INT0 generates an interrupt request.
#define INT0_BY_RISI_EDG()	EICRA |= (1 << ISC01)|(1 << ISC00)	//	 1  |  1	The rising edge of INT0 generates an interrupt request.
//--------------------------------------------------------------// ISC11|ISC10
#define INT1_BY_LOW_LVL()	EICRA |= (0 << ISC11)|(0 << ISC10)	//	 0	|  0	The low level of INT1 generates an interrupt request.
#define INT1_BY_ANY_CHNG()	EICRA |= (0 << ISC11)|(1 << ISC10)	//	 0  |  1	Any logical change on INT1 generates an interrupt request
#define INT1_BY_FALL_EDG()	EICRA |= (1 << ISC11)|(0 << ISC10)	//	 1  |  0	The falling edge of INT1 generates an interrupt request.
#define INT1_BY_RISI_EDG()	EICRA |= (1 << ISC11)|(1 << ISC10)	//	 1  |  1	The rising edge of INT1 generates an interrupt request.
//------------ Mask Register -----------------------------------//
#define EXTI_1_ENABLE()		EIMSK |= (1 << INT1)				// Enable  external interrupt INT1
#define EXTI_1_DISABLE()	EIMSK |= (0 << INT1)				// Disable external interrupt INT1
#define EXTI_0_ENABLE()		EIMSK |= (1 << INT0)				// Enable  external interrupt INT0
#define EXTI_0_DISABLE()	EIMSK |= (0 << INT0)				// Disable external interrupt INT0
//--------------------------------------------------------------//
//------------ Function prototype ------------------------------//
void HAL_EXTI_INT1(uint8_t status, uint8_t CTRLsense);			//
void HAL_EXTI_INT0(uint8_t status, uint8_t CTRLsense);			//
//--------------------------------------------------------------//


#endif /* MEGA328P_HAL_EXTI_H_ */
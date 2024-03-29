﻿/*
 * mega328p_hal_timer.h
 *
 * Created: 15.08.2019 10:18:42
 *  Author: Евгений
 */ 


#ifndef MEGA328P_HAL_TIMER_H_
#define MEGA328P_HAL_TIMER_H_

#include <mega328p_hal_cpu.h>
//--------------------- 8-bit Timer/Counter 0 ----------------------- */
//------------------------------------------------------------------- */
//----------------- Timer/Counter Control Register ------------------ */
//------------------------ TCCR0A|TCCR0B ---------------------------- */
/*				Compare Output Mode, non-PWM Mode
---------------------------------------------------------------
 COM0A1 | COM0A0 | Description							  
---------------------------------------------------------------	
   0    |   0	 | Normal port operation, OC0A disconnected
---------------------------------------------------------------	   
   0    |   1    | Toggle OC0A on compare match
---------------------------------------------------------------
   1    |   0    | Clear OC0A on compare match	   
---------------------------------------------------------------
   1    |   1    | Set OC0A on compare match
---------------------------------------------------------------
				Compare Output Mode, Fast PWM Mode
---------------------------------------------------------------				
 COM0A1 | COM0A0 | Description
---------------------------------------------------------------
   0    |   0    | Normal port operation, OC0A disconnected.
---------------------------------------------------------------   
   0    |   1    | WGM02 = 0: Normal port operation, OC0A disconnected.
		|		 | WGM02 = 1: Toggle OC0A on compare match.
---------------------------------------------------------------
   1    |   0    | Clear OC0A on compare match, set OC0A at BOTTOM,
        |        | (non-inverting mode).
---------------------------------------------------------------
   1    |   1    | Set OC0A on compare match, clear OC0A at BOTTOM,
        |        | (inverting mode).
---------------------------------------------------------------   
			Compare Output Mode, Phase Correct PWM Mode
---------------------------------------------------------------
 COM0A1 | COM0A0 | Description
---------------------------------------------------------------
   0    |   0    | Normal port operation, OC0A disconnected.
---------------------------------------------------------------
   0    |   1    | WGM02 = 0: Normal port operation, OC0A disconnected.
	    |		 | WGM02 = 1: Toggle OC0A on compare match.
---------------------------------------------------------------
   1    |   0    | Clear OC0A on compare match when up-counting.
        |        | Set OC0A on compare match when down-counting.
---------------------------------------------------------------		
   1    |   1    | Set OC0A on compare match when up-counting.
        |        | Clear OC0A on compare match when down-counting.			
---------------------------------------------------------------	
				
---------------------------------------------------------------
				Compare Output Mode, non-PWM Mode
---------------------------------------------------------------
 COM0B1 | COM0B0 | Description							  
---------------------------------------------------------------	
   0    |   0	 | Normal port operation, OC0B disconnected
---------------------------------------------------------------	   
   0    |   1    | Toggle OC0B on compare match
---------------------------------------------------------------
   1    |   0    | Clear OC0B on compare match	   
---------------------------------------------------------------
   1    |   1    | Set OC0B on compare match
---------------------------------------------------------------
				Compare Output Mode, Fast PWM Mode
---------------------------------------------------------------
 COM0B1 | COM0B0 | Description
---------------------------------------------------------------
   0    |   0	 | Normal port operation, OC0B disconnected
---------------------------------------------------------------
   0    |   1    | Reserved
---------------------------------------------------------------
   1    |   0    | Clear OC0B on compare match, set OC0B at BOTTOM,
        |        | (non-inverting mode)
---------------------------------------------------------------
   1    |   1    | Set OC0B on compare match, clear OC0B at BOTTOM, 
        |        | (inverting mode).
---------------------------------------------------------------
				Compare Output Mode, Phase Correct PWM Mode
---------------------------------------------------------------
 COM0B1 | COM0B0 | Description
---------------------------------------------------------------
   0    |   0	 | Normal port operation, OC0B disconnected
---------------------------------------------------------------	
   0    |   1    | Reserved
---------------------------------------------------------------
   1    |   0    | Clear OC0B on compare match when up-counting. 
		|		 | Set OC0B on compare match when down-counting.
---------------------------------------------------------------   
   1    |   1    | Set OC0B on compare match when up-counting.
        |        | Clear OC0B on compare match when down-counting.	
---------------------------------------------------------------		

|-------------------------------------------------------------------------------------------|
|					Waveform Generation Mode Bit Description								|
|-------------------------------------------------------------------------------------------|					
|	Mode | WGM02  | WGM01  | WGM00	|Timer/Counter	  | 	TOP	  |	Update of |	TOV Flag	|
|	 	 |		  |		   |		|Mode of Operation|			  |	OCRx at	  |	Set on(1)(2)|
|-------------------------------------------------------------------------------------------|
|	 0   |   0    |   0    |   0    |   Normal        |    0xFF   | Immediate |   MAX		|
|-------------------------------------------------------------------------------------------|
|    1   |   0    |   0    |   1    |   PWM,		  |    0xFF   |    TOP    |   BOTTOM	|
|		 | 		  |		   |		|   phase correct |           |           |				|
|-------------------------------------------------------------------------------------------|		 
|    2   |   0    |   1    |   0    |   CTC           |    OCRA   | Immediate |   MAX		|
|-------------------------------------------------------------------------------------------|	 
|    3   |   0    |   1    |   1    |   Fast PWM      |    0xFF   |  BOTTOM   |   MAX		|
|-------------------------------------------------------------------------------------------|	 
|    4   |   1    |   0    |   0    |   Reserved      |     –     |     –     |    –		|
|-------------------------------------------------------------------------------------------|	 
|    5   |   1    |   0    |   1    |   PWM,		  |    OCRA   |    TOP    |   BOTTOM	|
|		 |		  |    	   |		|	phase correct |			  |			  |				|
|-------------------------------------------------------------------------------------------|		 
|    6   |   1    |   1    |   0    |   Reserved      |     –     |     –     |    –		|
|-------------------------------------------------------------------------------------------|	 
|    7   |   1    |   1    |   1    |   Fast PWM      |    OCRA   |  BOTTOM   |   TOP		|
|-------------------------------------------------------------------------------------------|	 

|-------------------------------------------------------------------------------------------|
|								Clock Select Bit Description								|
|-------------------------------------------------------------------------------------------|
|CS02 |CS01 |CS00 | Description																|
|--------------------------------------------------------------------------------------------
| 0   | 0   | 0   | No clock source (Timer/Counter stopped)									|
|--------------------------------------------------------------------------------------------
| 0   | 0   | 1   | clk.I.O/(no prescaling)													|
|--------------------------------------------------------------------------------------------
| 0   | 1   | 0   | clk.I.O/8 (from prescaler)												|
|--------------------------------------------------------------------------------------------
| 0   | 1   | 1   | clk.I.O/64 (from prescaler)												|
|--------------------------------------------------------------------------------------------
| 1   | 0   | 0   | clk.I.O/256 (from prescaler)											|
|--------------------------------------------------------------------------------------------
| 1   | 0   | 1   | clk.I.O/1024 (from prescaler)											|
|--------------------------------------------------------------------------------------------
| 1   | 1   | 0   | External clock source on T0 pin. Clock on falling edge.					|
|--------------------------------------------------------------------------------------------
| 1   | 1   | 1   | External clock source on T0 pin. Clock on rising edge.					|
|-------------------------------------------------------------------------------------------|
*/
void HAL_TIM0_Init(uint8_t comp_A, uint8_t comp_B, uint8_t compA_INT, uint8_t compB_INT, uint8_t overflow_INT);
void HAL_TIM1_Init(uint16_t comp_A, uint16_t comp_B, uint8_t compB_INT, uint8_t compA_INT, uint8_t overflow_INT);

#endif /* MEGA328P_HAL_TIMER_H_ */
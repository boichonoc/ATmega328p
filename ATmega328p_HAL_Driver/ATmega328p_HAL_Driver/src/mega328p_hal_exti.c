/*
 * mega328p_hal_exti.c
 *
 * Created: 14.08.2019 10:48:06
 *  Author: Евгений
 */ 
#include <mega328p_hal_exti.h>
void HAL_EXTI_INT1(uint8_t status, uint8_t CTRLsense)
{
	if(status == ENABLE_EXTI)
	{
		EXTI_1_ENABLE();
		sei();
		switch(CTRLsense)
		{
			case 0:	 
				INT1_BY_LOW_LVL();
				break;
			case 1:
				INT1_BY_ANY_CHNG();
				break;
			case 2:
				INT1_BY_FALL_EDG();
				break;
			case 3:
				INT1_BY_RISI_EDG();
				break;
		}
	}
	else
	{
		EXTI_1_DISABLE();
		cli();
	}
	
}
void HAL_EXTI_INT0(uint8_t status, uint8_t CTRLsense)
{
	if(status == ENABLE_EXTI)
	{
		EXTI_0_ENABLE();
		sei();
		switch(CTRLsense)
		{
			case 0:
				INT0_BY_LOW_LVL();
				break;
			case 1:
				INT0_BY_ANY_CHNG();
				break;
			case 2:
				INT0_BY_FALL_EDG();
				break;
			case 3:
				INT0_BY_RISI_EDG();
				break;
		}
	}
	else
	{
		EXTI_0_DISABLE();
		cli();
	}	
}
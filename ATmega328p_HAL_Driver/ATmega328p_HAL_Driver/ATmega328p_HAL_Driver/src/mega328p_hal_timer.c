/*
 * mega328p_hal_timer.c
 *
 * Created: 15.08.2019 14:07:02
 *  Author: Евгений
 */ 

#include <mega328p_hal_timer.h>

//--------------- Local Functions Prototypes -----------------//
//--------------------- TIM0 /8-bit --------------------------//
//------------------- TCCR0A Register ------------------------//
static void _SET_TCCR0A(uint8_t COM0A_1, uint8_t COM0A_0, uint8_t COM0B_1, uint8_t COM0B_0, uint8_t WGM0_1, uint8_t WGM0_0);
//------------------------------------------------------------//
//------------------- TCCR0B Register ------------------------//
static void _SET_TCCR0B(uint8_t FOC0_A, uint8_t FOC0_B, uint8_t WGM0_2, uint8_t CS0_2, uint8_t CS0_1, uint8_t CS0_0);
//------------------------------------------------------------//
//-----------------  Timer/Counter Register ------------------ */
//--------------------------- TCNT0 -------------------------- */
static void _SET_TCNT0(uint8_t TCNT_0);
static uint8_t _GET_TCNT0();
//-------------------------------------------------------------//
//--------------- Output Compare Register A / B -------------- */
//--------------------- OCR0A / OCR0B ------------------------ */
static void _SET_OCR0A(uint8_t OCR0_A);
static void _SET_OCR0B(uint8_t OCR0_B);
static uint8_t _GET_OCR0_A();
static uint8_t _GET_OCR0_B();
//-------------------------------------------------------------//
//----------- Timer/Counter Interrupt Mask Register -----------//
//----------------------- TIMSK0 ------------------------------//
static void _SET_TIMSK0(uint8_t OCIE0_B, uint8_t OCIE0_A, uint8_t TOIE_0);
//-------------------------------------------------------------//
//----------- Timer/Counter 0 Interrupt Flag Register ---------//
//----------------------- TIFR0 -------------------------------//
static void _SET_TIFR0(uint8_t OCF0_A, uint8_t OCR0_B, uint8_t TOV_0);
//-------------------------------------------------------------//
//--------------------- TIM1 /16-bit --------------------------//
//------------------- TCCR1A Register -------------------------//
static void _SET_TCCR1A(uint8_t COM1A_1, uint8_t COM1A_0, uint8_t COM1B_1, uint8_t COM1B_0, uint8_t WGM1_1, uint8_t WGM1_0);
//------------------- TCCR1B Register -------------------------//
static void _SET_TCCR1B(uint8_t ICNC_1, uint8_t ICES_1, uint8_t WGM1_3, uint8_t WGM1_2, uint8_t CS1_2, uint8_t CS1_1, uint8_t CS1_0);
//------------------- TCCR1C Register -------------------------//
static void _SET_TCCR1C(uint8_t FOC1_A, uint8_t FOC1_B);
//-----------------  Timer/Counter Register -------------------//
//--------------------------- TCNT1 ---------------------------//
static void _SET_TCNT1(uint16_t TCNT1_H_L);
//--------------- Output Compare Register A / B ---------------//
//------------------ OCR1A_H_L / OCR1B_H_L --------------------//
static void _SET_OCR1A(uint16_t OCR1A_H_L);
static void _SET_OCR1B(uint16_t OCR1B_H_L);
//-------------- Input Capture Register 1 ---------------------//
//------------------ ICR1H and ICR1L --------------------------//
static void _SET_ICR1(uint16_t ICR1_H_L);
//----------- Timer/Counter Interrupt Mask Register -----------//
//----------------------- TIMSK1 ------------------------------//
static void _SET_TIMSK1(uint8_t ICIE_1, uint8_t OCIE1_B, uint8_t OCIE1_A, uint8_t TOIE_1);
//----------- Timer/Counter 1 Interrupt Flag Register ---------//
//----------------------- TIFR1 -------------------------------//
static void _SET_TIFR1(uint8_t ICF_1, uint8_t OCF1_A, uint8_t OCF1_B, uint8_t TOV_1);
//-------------------------------------------------------------//

//--------------------- Global Functions ----------------------//
//--------------------- TIM0 /8-bit Init ----------------------//
void HAL_TIM0_Init(uint8_t comp_A, uint8_t comp_B, uint8_t compA_INT, uint8_t compB_INT, uint8_t overflow_INT)
{
	_SET_TCCR0A(0, 0, 0, 0, 1, 0);
	_SET_TCCR0B(0, 0, 0, 1, 0, 1);
	_SET_TCNT0(0x00);
	_SET_OCR0A(comp_A);
	_SET_OCR0B(comp_B);
	_SET_TIMSK0(compB_INT, compA_INT, overflow_INT);
}
//--------------------- TIM1 /16-bit Init ---------------------//
void HAL_TIM1_Init(uint16_t comp_A, uint16_t comp_B, uint8_t compB_INT, uint8_t compA_INT, uint8_t overflow_INT)
{
	_SET_TCCR1A(0, 0, 0, 0, 0, 0);
	_SET_TCCR1B(0, 0, 0, 1, 1, 0, 0);
	_SET_TCNT1(0x0000);
	_SET_OCR1A(comp_A);
	_SET_OCR1B(comp_B);
	_SET_TIMSK1(0, compB_INT, compA_INT, overflow_INT);
}
//-------------------------/* Local Funcions */------------------------------------------------------------------------//
//------------------------/* Timer 0 / 8- bit */-----------------------------------------------------------------------//
static void _SET_TCCR0A(uint8_t COM0A_1, uint8_t COM0A_0, uint8_t COM0B_1, uint8_t COM0B_0, uint8_t WGM0_1, uint8_t WGM0_0)
{
	TCCR0A |= (COM0A_1 << COM0A1)|(COM0A_0 << COM0A0);
	
	TCCR0A |= (COM0B_1 << COM0B1)|(COM0B_0 << COM0B0);
	
	TCCR0A |= (WGM0_1 << WGM01)|(WGM0_0 << WGM00);
}
static void _SET_TCCR0B(uint8_t FOC0_A, uint8_t FOC0_B, uint8_t WGM0_2, uint8_t CS0_2, uint8_t CS0_1, uint8_t CS0_0)
{
	TCCR0B |= (FOC0_A << FOC0A)|(FOC0_B << FOC0B);
	
	TCCR0B |= (WGM0_2 << WGM02);
	
	TCCR0B |= (CS0_2 << CS02)|(CS0_1 << CS01)|(CS0_0 << CS00);
}
static void _SET_TCNT0(uint8_t TCNT_0)
{
	TCNT0 = TCNT_0;
}
static uint8_t _GET_TCNT0()
{
	return TCNT0;
}
static void _SET_OCR0A(uint8_t OCR0_A)
{
	OCR0A = OCR0_A;
}
static void _SET_OCR0B(uint8_t OCR0_B)
{
	OCR0B = OCR0_B;
}
static uint8_t _GET_OCR0_A()
{
	return OCR0A;
}
static uint8_t _GET_OCR0_B()
{
	return OCR0B;
}
static void _SET_TIMSK0(uint8_t OCIE0_B, uint8_t OCIE0_A, uint8_t TOIE_0)
{
	TIMSK0 |= (OCIE0_B << OCIE0B);
	TIMSK0 |= (OCIE0_A << OCIE0A);
	TIMSK0 |= (TOIE_0 << TOIE0);
}
static void _SET_TIFR0(uint8_t OCF0_A, uint8_t OCF0_B, uint8_t TOV_0)
{
	TIFR0 |= (OCF0_A << OCF0A)|(OCF0_B << OCF0B);
	TIFR0 |= (TOV_0 << TOV0);
}
//----------------------------------------------------------------------------------------------------------------------//
//------------------------/* Timer 1 / 16- bit */-----------------------------------------------------------------------//
static void _SET_TCCR1A(uint8_t COM1A_1, uint8_t COM1A_0, uint8_t COM1B_1, uint8_t COM1B_0, uint8_t WGM1_1, uint8_t WGM1_0)
{
	TCCR1A |= (COM1A_1 << COM1A1)|(COM1A_0 << COM1A0);
	
	TCCR1A |= (COM1B_1 << COM1B1)|(COM1B_0 << COM1B0);
	
	TCCR1A |= (WGM1_1 << WGM11)|(WGM1_0 << WGM10);
}
static void _SET_TCCR1B(uint8_t ICNC_1, uint8_t ICES_1, uint8_t WGM1_3, uint8_t WGM1_2, uint8_t CS1_2, uint8_t CS1_1, uint8_t CS1_0)
{
	TCCR1B |= (ICNC_1 << ICNC1)|(ICES_1 << ICES1);
	
	TCCR1B |= (WGM1_3 << WGM13)|(WGM1_2 << WGM12);
	
	TCCR1B |= (CS1_2 << CS12)|(CS1_1 << CS11)|(CS1_0 << CS10);
}
static void _SET_TCCR1C(uint8_t FOC1_A, uint8_t FOC1_B)
{
	TCCR1C |= (FOC1_A << FOC1A)|(FOC1_B << FOC1B);
}
static void _SET_TCNT1(uint16_t TCNT1_H_L)
{
	TCNT1 = (uint16_t)TCNT1_H_L;
}
static void _SET_OCR1A(uint16_t OCR1A_H_L)
{
	OCR1A = (uint16_t)OCR1A_H_L;
}
static void _SET_OCR1B(uint16_t OCR1B_H_L)
{
	OCR1B = (uint16_t)OCR1B_H_L;
}
static void _SET_ICR1(uint16_t ICR1_H_L)
{
	ICR1H = (uint16_t)ICR1_H_L;
}
static void _SET_TIMSK1(uint8_t ICIE_1, uint8_t OCIE1_B, uint8_t OCIE1_A, uint8_t TOIE_1)
{
	TIMSK1 |= (ICIE_1 << ICIE1);
	TIMSK1 |= (OCIE1_B << OCIE1B);
	TIMSK1 |= (OCIE1_A << OCIE1A);
	TIMSK1 |= (TOIE_1 << TOIE1);
}
static void _SET_TIFR1(uint8_t ICF_1, uint8_t OCF1_A, uint8_t OCF1_B, uint8_t TOV_1)
{
	TIFR1 |= (ICF_1 << ICF1);
	TIFR1 |= (OCF1_A << OCF1A)|(OCF1_B << OCF1B);
	TIFR1 |= (TOV_1 << TOV1);
}
//----------------------------------------------------------------------------------------------------------------------//
/*
 * ATmega328p_HAL_Driver.c
 *
 * Created: 14.08.2019 10:44:08
 *  Author: Евгений
 */ 


#include <ATmega328p_HAL_Driver.h>
//------------- Private Includes ------------------------//
//------------- USER CODE BEGIN -------------------------//
//TODO:: Please write your application code

//------------- USER CODE END ---------------------------//
//-------------------------------------------------------//

//------------- Private Defenitions ---------------------//
//------------- USER CODE BEGIN -------------------------//
//TODO:: Please write your application code

//------------- USER CODE END ---------------------------//
//-------------------------------------------------------//

//------------- Private Variable ------------------------//
//------------- USER CODE BEGIN -------------------------//
//TODO:: Please write your application code
int cnt = 0;

//------------- USER CODE END ---------------------------//
//-------------------------------------------------------//
int main(void)
{
	HAL_Init();
	
    while(1)
    {
		//------------- USER CODE BEGIN -------------------------//
        //TODO:: Please write your application code
		//HAL_USART_Transmit('O');
		//_delay_ms(1000);
		//HAL_USART_Transmit('K');
		//_delay_ms(1000);
		//HAL_USART_Transmit('\r');
		//HAL_USART_Transmit('\n');
		//HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, LOW);
		//------------- USER CODE END ---------------------------//
		//-------------------------------------------------------//
    }
}
//--------/* ATmega328p Initial Periphery */-------------------//
void HAL_Init()
{	
//--------------- USER CODE BEGIN --------------------------//
//TODO:: Please write your application code

	HAL_TIM0_Init(127,255,1,1,0);	
	HAL_TIM1_Init(0xF424,0x7A12,1,1,0);
	HAL_GDIO_PORT_Init(PORTB5, GDIO_DDR_B, OUTPUT);
	HAL_GDIO_PORT_Init(PORTB4, GDIO_DDR_B, OUTPUT);
	HAL_GDIO_PORT_Init(PORTB3, GDIO_DDR_B, OUTPUT);
	HAL_GDIO_PORT_Init(PORTB2, GDIO_DDR_B, OUTPUT);
	HAL_GlobalInterrupt(GLOBAL_INT_ON);
	
	//HAL_GDIO_PORT_Init(PORTD2, GDIO_DDR_D, INPUT);
	//HAL_EXTI_INT0(ENABLE_EXTI, BY_FALLING_EDG);
	
	//HAL_USART_Init(MYUBRR);
	//HAL_USART_TX_IT(ENABLE_IT);
	//HAL_USART_RX_IT(ENABLE_IT);
//--------------- USER CODE END ----------------------------//
//----------------------------------------------------------//
}


//--------/* IRQ_Handler for interrupts */------------------//
//--------/*       USER CODE            */------------------//
	ISR(TIMER1_COMPA_vect)
	{
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB4, HIGH);
		_delay_ms(50);
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB4, LOW);
		_delay_ms(50);
	}
	ISR(TIMER1_COMPB_vect)
	{
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB3, HIGH);
		_delay_ms(50);
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB3, LOW);
		_delay_ms(50);
	}
	ISR(TIMER0_COMPA_vect)
	{
		/* IRQ_Handler: Timer 0 - Comp. A */
		//TODO:: Please write your application code
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB2, HIGH);
		_delay_ms(10);
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB2, LOW);
		_delay_ms(10);
	}
	ISR(TIMER0_COMPB_vect)
	{
		/* IRQ_Handler: Timer 0 - Comp. B */
		//TODO:: Please write your application code
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, HIGH);
		_delay_ms(20);
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, LOW);
		_delay_ms(20);
	}
	ISR(INT0_vect)
	{
		/* IRQ_Handler: EXTI0 */
		//TODO:: Please write your application code
		HAL_USART_Transmit('E');
		HAL_USART_Transmit('X');
		HAL_USART_Transmit('T');
		HAL_USART_Transmit('I');
		HAL_USART_Transmit('0');
		HAL_USART_Transmit('\r');
		HAL_USART_Transmit('\n');
		_delay_ms(200);
	}
	ISR(INT1_vect)
	{
		/* IRQ_Handler: EXTI1 */
		//TODO:: Please write your application code
	}
	ISR(USART_RX_vect)
	{
		/* IRQ_Handler: USART RX Interrupt */
		//TODO:: Please write your application code
		HAL_USART_Flush();
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, HIGH);
		_delay_ms(100);
		HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, LOW);
		_delay_ms(100);
	}

	ISR(USART_TX_vect)
	{
		/* IRQ_Handler: USART TX Interrupt */
		//TODO:: Please write your application code
		if(cnt == 0)
		{
			cnt++;	
			HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, LOW);
		}
		_delay_ms(1000);
		if(cnt == 1)
		{
			HAL_GDIO_PORT_Write(GDIO_PORT_B, PORTB5, HIGH);
			cnt = 0;
		}
	
	
	}
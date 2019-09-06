/*
 * mega328p_hal_usart.h
 *
 * Created: 14.08.2019 10:50:29
 *  Author: Евгений
 */ 


#ifndef MEGA328P_HAL_USART_H_
#define MEGA328P_HAL_USART_H_

#include <mega328p_hal_cpu.h>

//------------ USART -------------------------------------------//
//------------ Clock -------------------------------------------//
#define BAUD 9600												// USART baud rate
#define MYUBRR (F_CPU/8/BAUD)-1									// UBRR
//--------------------------------------------------------------//
//--------------------------------------------------------------//
#define ENABLE_IT  1
#define DISABLE_IT 0
//--------------- Functions prototype --------------------------//

void HAL_USART_Init(unsigned int ubrr);
void HAL_USART_TX_IT(uint8_t status);
void HAL_USART_RX_IT(uint8_t status);
void HAL_USART_Transmit(unsigned char data);
void HAL_USART_Transmit_9BIT(unsigned int data);
unsigned char HAL_USART_Receive(void);
unsigned char HAL_USART_Receive_IT(void);
unsigned int HAL_USART_Receive_9BIT(void);
void HAL_USART_Flush(void);

//----------------------------------------------------------------//

#endif /* MEGA328P_HAL_USART_H_ */
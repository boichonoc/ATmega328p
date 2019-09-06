/*
 * mega328p_hal_usart.c
 *
 * Created: 14.08.2019 10:54:21
 *  Author: Евгений
 */ 
#include <mega328p_hal_usart.h>

void HAL_USART_Init(unsigned int ubrr)
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|( 1<<TXEN0); 
	UCSR0A |= (0<<U2X0); 
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);
}

void HAL_USART_TX_IT(uint8_t status)
{
	switch(status)
	{
		case ENABLE_IT:  
		{
			UCSR0B |= (1 << TXCIE0);
			break;
		}
		case DISABLE_IT:
		{
			UCSR0B |= (0 << TXCIE0);
			break;
		}
	}
}

void HAL_USART_RX_IT(uint8_t status)
{
	switch(status)
	{
		case ENABLE_IT:
		{
			UCSR0B |= (1 << RXCIE0);
			break;
		}
		case DISABLE_IT:
		{
			UCSR0B |= (1 << RXCIE0);
			break;
		}
	}
}

void HAL_USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	/* Put data into buffer, send the data */
	UDR0 = data;
}

void HAL_USART_Transmit_9BIT(unsigned int data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	/* Copy 9th bit to TXB8 */
	UCSR0B &= ~(1<<TXB80);
	if (data & 0x0100)
		UCSR0B |= (1<<TXB80);
	/* Put data into buffer, send the data */
	UDR0 = data;
}

unsigned char HAL_USART_Receive(void)
{
	/* Wait for data to be received */
	while (! (UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

unsigned int HAL_USART_Receive_9BIT(void)
{
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* get status and 9th bit, then data */
	/* from buffer */
	status = UCSR0A;
	resh = UCSR0B;
	resl = UDR0;
	/* If error, return -1 */
	if (status & (1<<FE0)|(1<<DOR0)|(1<<UPE0))
		return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

void HAL_USART_Flush(void)
{
	unsigned char dummy;
	while (UCSR0A & (1<<RXC0)) dummy = UDR0;
}
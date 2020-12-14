/*
 * UART_Prog.c
 *
 *  Created on: Nov 19, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "UART_priv.h"
#include "AVR_REG.h"

void UART_VidInit(u16 Copy_U8Baud)
{
	UBRRH = (u8)(Copy_U8Baud>>8);
	UBRRL = (u8)Copy_U8Baud;

	UCSRB = (1<<TXEN) |(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

}

void UART_VidSendData(u8 Copy_U8Data)
{

	/* Wait for empty transmit buffer */
	while ( !GET_BIT(UCSRA , UDRE) );
	/* Put data into buffer, sends the data */
	UDR = Copy_U8Data;

}

u8 UART_VidReceiveData(void)
{

	while ( !GET_BIT(UCSRA , RXC) );
	return UDR;
}


void UART_SendString(const u8 *str)
{
	while(*str != '\0')
	{
		UART_VidSendData(*str);
		str++;
	}
}




void UART_ReceiveString(u8 *Str)
{
	unsigned char i = 0;
	Str[i] = UART_VidReceiveData();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_VidReceiveData();
	}
	Str[i] = '\0';
}

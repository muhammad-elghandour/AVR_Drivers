/*
 * SPI_Prog.c
 *
 *  Created on: Nov 15, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include"BIT_MATH.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "AVR_REG.h"
#include "SPI_Private.h"

void SPI_MasterInit(void)
{
DIO_enuSetPinDirection(PORT_B , PIN4 , DIO_PIN_OUTPUT);
DIO_enuSetPinDirection(PORT_B , PIN5 , DIO_PIN_OUTPUT);
DIO_enuSetPinDirection(PORT_B , PIN6 , DIO_PIN_INPUT);
DIO_enuSetPinDirection(PORT_B , PIN7 , DIO_PIN_OUTPUT);

SPCR = (1<<SPE) | (1<<MSTR);
}




void SPI_SlaveInit(void)
{
DIO_enuSetPinDirection(PORT_B , PIN4 , DIO_PIN_INPUT);
DIO_enuSetPinDirection(PORT_B , PIN5 , DIO_PIN_INPUT);
DIO_enuSetPinDirection(PORT_B , PIN6 , DIO_PIN_OUTPUT);
DIO_enuSetPinDirection(PORT_B , PIN7 , DIO_PIN_INPUT);

SPCR = (1<<SPE);

}



void SPI_SendByte(u8 cData)
{
/* Start transmission */
SPDR = cData;

/* Wait for transmission complete */

while(!(GET_BIT(SPSR , SPIF)));  //wait until SPI interrupt flag=1 (data is sent correctly)
}

u8 SPI_recieveByte(void)
{
   while(!(GET_BIT(SPSR , SPIF))); //wait until SPI interrupt flag=1(data is receive correctly)
   return SPDR; //return the received byte from SPI data register
}



void SPI_SendString(const u8 *str)
{
	while(*str != '\0')
	{
		SPI_SendByte(*str);
		str++;
	}
}




void SPI_ReceiveString(u8 *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_recieveByte();
	}
	Str[i] = '\0';
}

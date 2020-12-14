/*
 * Timer_Program.c
 *
 *  Created on: Nov 5, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "Timer_Private.h"
#include "errorStates.h"
#include "DIO_int.h"



void Timer_VidInit(void)
{
	TCCR0 = 0b01101100; //  prescaller 256 , fast PWM
	//TIMSK = 0b00000001; //interrupt enable

	DIO_enuSetPinDirection(PORT_B , PIN3 , DIO_PIN_OUTPUT);

}

void Set_VidDuteyCycle(u8 Copy_U8_Duty)
{

	OCR0  = Copy_U8_Duty; //compare value


}



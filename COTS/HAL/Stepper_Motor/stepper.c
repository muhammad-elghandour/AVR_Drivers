/*
 * stepper.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Muhammad Elghandour
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_confg.h"
#include "DIO_interface.h"
#include "stepper_config.h"
#include "util/delay.h"

void stepper (void)
{
	DIO_VidSetPinDirection(Stepper_PORT,Stepper_PIN1,1);
	DIO_VidSetPinDirection(Stepper_PORT,Stepper_PIN2,1);
	DIO_VidSetPinDirection(Stepper_PORT,Stepper_PIN3,1);
	DIO_VidSetPinDirection(Stepper_PORT,Stepper_PIN4,1);

	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN1,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN2,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN3,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN4,HIGH);

	_delay_ms(3);

	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN1,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN2,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN3,HIGH);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN4,LOW);

	_delay_ms(3);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN1,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN2,HIGH);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN3,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN4,LOW);

	_delay_ms(3);

	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN1,HIGH);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN2,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN3,LOW);
	DIO_VidSetPinValue(Stepper_PORT,Stepper_PIN4,LOW);

	_delay_ms(3);





}

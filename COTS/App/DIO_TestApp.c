/*
 * main.c
 *
 *  Created on: Nov 2, 2020
 *      Author: hp
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR32_REG.h"


#include "../MCAL/DIO_int.h"

#include <util/delay.h>

int main()
{
	DIO_enuInit();

	while (1)
	{
		DIO_enuSetPinValue(PIN5,DIO_PIN_HIGH);
		DIO_enuSetPinValue(PIN12,DIO_PIN_HIGH);
		DIO_enuSetPinValue(PIN25,DIO_PIN_HIGH);
		_delay_ms(1000);
		DIO_enuSetPinValue(PIN5, DIO_PIN_LOW);
		DIO_enuSetPinValue(PIN12, DIO_PIN_LOW);
		DIO_enuSetPinValue(PIN25, DIO_PIN_LOW);
		_delay_ms(1000);

	}
	return 0;
}

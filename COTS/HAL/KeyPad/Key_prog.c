/*
 * Key_prog.c
 *
 *  Created on: Oct 22, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorStates.h"
#include "DIO_int.h"

#include "Key_config.h"
#include "Key_priv.h"


u8 Rowarr[]={R1,R2,R3,R4};
u8 Colarr[]={C1,C2,C3,C4};

u8 Key_u8Vals[4][4]=KEY_VALS;

void Key_vidInit(void)
{
	DIO_enuSetPortDirection(KEY_PORT, 0x0f);
	DIO_enuSetPortValue(KEY_PORT,0xff);
}

u8 Key_u8GetKey(void)
{
	u8 pinval=2;
	for (u8 ColIter =0; ColIter <=3 ; ColIter ++)
	{
		DIO_enuSetPinValue(KEY_PORT, Colarr[ColIter], DIO_PIN_LOW);
		for (u8 RowIter=0 ; RowIter<=3 ; RowIter++)
		{
			DIO_enuGetPinValue(KEY_PORT,Rowarr[RowIter],&pinval);
			if (! pinval)
			{
				while(! pinval)
				{
					DIO_enuGetPinValue(KEY_PORT,Rowarr[RowIter],&pinval);
				}
				return Key_u8Vals[RowIter][ColIter];
			}
		}
		DIO_enuSetPinValue(KEY_PORT, Colarr[ColIter], DIO_PIN_HIGH);
	}
	return KEY_NOT_PRESSED;
}

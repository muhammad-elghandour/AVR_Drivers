/*
 * Timer_Program.c
 *
 *  Created on: Nov 10, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "Timer_Private.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "GIE_int.h"


u8 OV_Counter=0;
u16 snap1=0;
u16 snap2=0;
u16 snap3=0;
u8 flag=0;


void Timer1_VidInit(void)
{
	TCCR1A = 0b10000010;
	TCCR1B = 0b00011100;
	//OCR1A =62;
	ICR1  = 625;
}

void TIMER1_VidICUInit(){
	DIO_enuSetPinDirection(PORT_D,PIN6,DIO_PIN_INPUT);
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	SET_BIT(TIMSK,5);
	SET_BIT(TIMSK,2);
	SET_BIT(TCCR1B,6);// rasing edge;
	GIE_enuEnable();
}


void TIMER1_VidStart(){
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}


void Set_VidDuteyCycle(u8 Copy_U8_Duty)
{

	OCR1A  = Copy_U8_Duty;


}




void __vector_9(void)
{
	OV_Counter++;
}


void __vector_6(void)
{
	if(flag==0){
		snap1=ICR1;
		CLR_BIT(TCCR1B,6);
		OV_Counter=0;

	}else if(flag==1){
		snap2=ICR1 + (OV_Counter * 65536);
		SET_BIT(TCCR1B,6);
		flag=2;
	}else if (flag==2){
		snap3=ICR1+(OV_Counter*65536);
		flag=3;
	}




}

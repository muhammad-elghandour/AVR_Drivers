/*
 * main.c
 *
 *  Created on	: Oct 27, 2020
 *  Version		: 1.0.0
 *  Author		: Muhammad Elghandour
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR_REG.h"


#include "../MCAL/GIE_int.h"


#include "../MCAL/EXT_INT_int.h"

void fun  (void*);
void fun1 (void*);
void fun2 (void*);

struct d
{
	u8 h;
	u8 g;
};

int main (void)
{
	DDRA=0xff;
	struct d k ={123};
	void*ptr=&k;

	DDRB|=(1<<4);	DDRB|=(1<<5);	DDRB|=(1<<6);


	GIE_enuEnable();
	EXT_INT_enuInit();

	EXT_INT_enuSelectSenceLevel(RISING_EDAGE_INT2);
	EXT_INT_enuSelectSenceLevel(ANY_LOGICAL_CHANGE_INT0);
	EXT_INT_enuSelectSenceLevel(RISING_EDAGE_INT1);

	EXT_INT_enuCallBackFunction(fun , ptr , INT0);
	EXT_INT_enuCallBackFunction(fun1 , ptr , INT1);
	EXT_INT_enuCallBackFunction(fun2 , NULL , INT2);

	while(1)
	{

	}
	return 0;
}

void fun2 (void* para)
{
	PORTB^=(1<<4);
}
void fun1 (void* para)
{
	PORTB^=(1<<5);
	struct  d *p=(struct d*)para;
	PORTA= p->h;
	p->g=15;
}
void fun (void* para)
{
	PORTB^=(1<<6);
	struct  d *p=(struct d*)para;
	PORTA= p->g;

}

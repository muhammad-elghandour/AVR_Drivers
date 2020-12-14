/*
 * BIT_MATH.h
 *
 *  Created on	: Oct 18, 2020
 *  Version		: last updated
 *  Author		: Muhammad Elghandour
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO)			  VAR|= (1<<BITNO)

#define CLR_BIT(VAR,BITNO)			  VAR&=~(1<<BITNO)

#define TOG_BIT(VAR,BITNO)  		  VAR^= (1<<BITNO)

#define GET_BIT(VAR,BITNO) 			  ((VAR>>BITNO)&0x01)

#define ASSIGN_BIT(VAR,BITNO,VAL)	  VAR =(VAR&(~(1<<BITNO))) | (VAL<<BITNO)

#endif /* BIT_MATH_H_ */

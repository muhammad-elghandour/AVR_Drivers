/*
 * EXT_INT_priv.h
 *
 *  Created on	: Oct 27, 2020
 *  Version		: 1.0.0
 *  Author		: Muhammad Elghandour
 */

#ifndef MCAL_EXT_INT_PRIV_H_
#define MCAL_EXT_INT_PRIV_H_



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                   Address of EXT_INTERRUPT registers                    **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#ifndef EXT_REG
#define EXT_REG
#define MCUCR 									*((volatile u8*) 0x55)
#define MCUCSR									*((volatile u8*) 0x54)
#define GICR 									*((volatile u8*) 0x5b)
#define GIFR  									*((volatile u8*) 0x5a)
#endif
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**              Definitions of EXT_INTERRUPT configuration                 **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/**         Definitions of Enabling EXT_INTERRUPT configuration             **/
/*****************************************************************************/
#define	INT_ZERO								1
#define	INT_ONE									3
#define	INT_TWO									5
#define	INT_ZERO_AND_ONE						7
#define	INT_ZERO_AND_TWO						9
#define	INT_ONE_AND_TWO							11
#define	INT_ZERO_AND_ONE_AND_TWO				13


#define SET_ENABLE_INT0							GICR|=(1<<6);\
												PORTD&=~(1<<2);\
												PORTD|=(1<<2);

#define SET_ENABLE_INT1							GICR|=(1<<7);\
												PORTD&=~(1<<3);\
												PORTD|=(1<<3);

#define SET_ENABLE_INT2							GICR|=(1<<5);\
												DDRB&=~(1<<2);\
												PORTB|=(1<<2)
/*****************************************************************************/



/*****************************************************************************/
/**               Definitions of Sense Level configuration                  **/
/*****************************************************************************/
#define SET_LOW_LEVEL_INT0						MCUCR&=~(1<<0)&(~(1<<1))

#define SET_ANY_LOGICAL_CHANGE_INT0				MCUCR|= (1<<0);\
												MCUCR&=~(1<<1)

#define SET_FALLING_EDAGE_INT0					MCUCR|= (1<<1);\
												MCUCR&=~(1<<0)

#define SET_RISING_EDAGE_INT0					MCUCR|= (1<<1)|(1<<0)


#define SET_LOW_LEVEL_INT1						MCUCR&=~(1<<2)&(~(1<<3))

#define SET_ANY_LOGICAL_CHANGE_INT1				MCUCR|= (1<<2);\
												MCUCR&=~(1<<3)

#define SET_FALLING_EDAGE_INT1					MCUCR|= (1<<3);\
												MCUCR&=~(1<<2)

#define SET_RISING_EDAGE_INT1					MCUCR|= (1<<3)|(1<<2)


#define SET_FALLING_EDAGE_INT2					MCUCSR&=~(1<<6)

#define SET_RISING_EDAGE_INT2					MCUCSR|= (1<<6)
/*****************************************************************************/



/*****************************************************************************/
/**                Definitions of Number of EXT_INTERRUPT                   **/
/*****************************************************************************/
#define EXT_INT_NUMs							3
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


#endif /* MCAL_EXT_INT_PRIV_H_ */
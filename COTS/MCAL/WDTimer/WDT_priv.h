/*
 * WDT_priv.h
 *
 *  Created on: Nov 23, 2020
 *      Author: Muhammad Elghandour
 */

#ifndef WDT_PRIV_H_
#define WDT_PRIV_H_

#define WDTCR	*((volatile u8*) 0x41)


#define WDE		3
#define WDP1	1
#define WDP2	2
#define WDTOE	4


#endif /* WDT_PRIV_H_ */

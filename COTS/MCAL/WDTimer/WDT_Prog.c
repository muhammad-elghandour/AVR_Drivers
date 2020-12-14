/*
 * WDT_Prog.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Muhammad Elghandour
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "WDT_priv.h"

void WDT_VidEnable(void)
{
SET_BIT(WDTCR , WDE);
SET_BIT(WDTCR , WDP1);
SET_BIT(WDTCR , WDP2);

}
void WDT_VidDisable(void)
{
	WDTCR |=(1<<WDTOE)|(1<<WDE) ;

	//CLR_BIT(WDTCR , WDE);
	WDTCR=0x00; // within the four cycles
}


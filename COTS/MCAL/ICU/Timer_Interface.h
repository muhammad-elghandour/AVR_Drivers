/*
 * Timer_Interface.h
 *
 *  Created on: Nov 10, 2020
 *      Author: Muhammad Elghandour
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer1_VidInit(void);

void Set_VidDuteyCycle(u8 Copy_U8_Duty);

void TIMER1_VidICUInit();
void TIMER1_VidStart();

#endif /* TIMER_INTERFACE_H_ */

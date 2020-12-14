/*
 * UART_Int.h
 *
 *  Created on: Nov 19, 2020
 *      Author: Muhammad Elghandour
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void UART_VidInit(u8 Copy_U8Baud);

void UART_VidSendData(u8 Copy_U8Data);

u8 UART_VidReceiveData(void);

void UART_SendString(const u8 *str);

void UART_ReceiveString(u8 *Str);


#endif /* UART_INT_H_ */

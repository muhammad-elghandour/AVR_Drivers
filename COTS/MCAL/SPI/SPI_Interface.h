/*
 * SPI_Int.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Muhammad Elghandour
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);

void SPI_SendByte(u8 cData);
u8 SPI_recieveByte(void);

void SPI_SendString(const u8 *Str);
void SPI_ReceiveString(u8 *Str);



#endif /* SPI_INT_H_ */

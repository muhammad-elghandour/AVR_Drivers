/*
 * ADC_config.h
 *
 *  Created on	: Nov 03, 2020
 *  Version		: 1.0.0
 *  Author		: Muhammad Elghandour
 */

#ifndef MCAL_ADC_CONFIG_H_
#define MCAL_ADC_CONFIG_H_


/*****************************************************************************/
/**                                                                         **/
/**      Definitions of Prescaler configuration by the following :          **/
/**            PRE_TWO   -   PRE_FOUR   -   PRE_EIGHT   -   PRE_SIXTEEN     **/
/**                    PRE_THIRTY_TWO   -   PRE_SIXTY_FOUR                  **/
/**                         PRE_HUNDRED_TWENTY_EIGHT                        **/
/*****************************************************************************/
#define PRESCALER							PRE_TWO
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/**                                                                         **/
/**            Definitions of Reference Voltage configuration               **/
/**                A_REF   -   A_VCC   -   INTERNAL_REF                     **/
/*****************************************************************************/
#define V_REF								A_VCC
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/**                                                                         **/
/**               Definitions of Adjustment configuration                   **/
/**                      RIGHT_ADJ   -   LEFT_ADJ                           **/
/*****************************************************************************/
#define ADJUSTMENT							RIGHT_ADJ
/*****************************************************************************/
/*****************************************************************************/


#endif /* MCAL_ADC_CONFIG_H_ */

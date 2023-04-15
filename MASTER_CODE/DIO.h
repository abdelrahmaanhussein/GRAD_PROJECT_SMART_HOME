/*
 * DIO.h
 *
 *  Created on: Dec 27, 2022
 *      Author: KIT
 */

#ifndef DIO_H_
#define DIO_H_

#include "MCU.h"

#define PORT_OUTPUT 255
#define PORT_INPUT 0
#define PORT_HIGH 255
#define PORT_LOW 0
#define PIN_HIGH 1
#define PIN_LOW 0
#define PIN_OUTPUT 1
#define PIN_INPUT 0
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3
void DIO_vSetPortDirection(u8 LOC_u8PortID,u8 LOC_u8PortDirection);
void DIO_vSetPortValue(u8 LOC_u8PortID,u8 LOC_u8PortValue);
void DIO_vClrPortValue(u8 LOC_u8PortID,u8 LOC_u8PortValue);
u8 DIO_u8GetPortValue(u8 LOC_u8PortID);
void DIO_vtogPortValue(u8 LOC_u8PortID);
void DIO_vSetPinDir(u8 LOC_u8PortID,u8 LOC_u8Pin,u8 LOC_u8Dir);
void DIO_vSetPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin);
void DIO_vClrPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin);
void DIO_vTogPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin);
u8 DIO_u8GetPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin);


#endif /* DIO_H_ */

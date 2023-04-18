/*
 * UART.h
 *  Layer: Mcal
 *  Created on: Feb 6, 2023
 *      Author: Abdelrahman Hussein
 */

#ifndef UART_H_
#define UART_H_
#include"MCU.h"

enum ucsra{MPCM,U2X,PE,DOR,FE,UDRE,TXC,RXC};
enum ucsrb{TXB8,RXB8,UCSZ2,TXEN,RXEN,UDRIE,TSCIE,RXCIE};
enum ucsrc{UCPOL,UCSZ0,UCSZ1,USBS,UPM0,UPM1,UMSEL,URSEL};

void UART_vInit(void);
u8 UART_vReceive(void);
void UART_vTransmit(unsigned char data);



#endif /* UART_H_ */

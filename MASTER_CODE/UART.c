/*
 * UART.c
 *  Layer: Mcal
 *  Created on: Mar 14, 2023
 *      Author: Abdelrahman Hussein
 */


#include"UART.h"
void UART_vInit(void){
UBRRL=103;            // SETTING BAUD RATE TO 9600
SET_BIT(UCSRB,RXEN);  // ENABLING TRANSMISSION
CLR_BIT(UCSRB,UCSZ2); // SETTING CHARACTER SENT TO 8 BITS
UCSRC=0b10000110;
}
u8 UART_vReceive(void){
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;
}
void UART_vTransmit(unsigned char data){
	while(!(GET_BIT(UCSRA,5)));
	UDR=data;
	if (UDR==data){
		PORTD|=(1<<3);
	}
}






/*
 * int main(){
	SET_BIT(DDRB,4);
    UART_vInit();
	LCD_vPortInit();
	LCD_vLcdInit();
	_delay_ms(50);

	while(1)
	{
    u8 x=UART_vReceive();
    if(x=='A'){
    	SET_BIT(PORTB,4);
    }
    LCD_vWriteCharacter(x);
	}

	return 0;
}*/

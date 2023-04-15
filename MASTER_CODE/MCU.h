/*
 * MCU.h
 *
 *  Created on: Dec 27, 2022
 *      Author: KIT
 */

#ifndef MCU_H_
#define MCU_H_
#include<util\delay.h>
#include"TYPES.h"
#include"MACROS.h"
////////////////////////////////////////////////////////////////////////////
////////////          DIO REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////
#define PORTA      (*(volatile u8 *)0x3B)
#define DDRA       (*(volatile u8 *)0x3A)
#define PINA       (*(volatile u8 *)0x39)
#define PORTB      (*(volatile u8 *)0x38)
#define DDRB       (*(volatile u8 *)0x37)
#define PINB       (*(volatile u8 *)0x36)
#define PORTC      (*(volatile u8 *)0x35)
#define DDRC       (*(volatile u8 *)0x34)
#define PINC       (*(volatile u8 *)0x33)
#define PORTD      (*(volatile u8 *)0x32)
#define DDRD       (*(volatile u8 *)0x31)
#define PIND       (*(volatile u8 *)0x30)
////////////////////////////////////////////////////////////////////////////
////////////          INTERRUPT REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////

#define SREG       (*(volatile u8 *)0x5F)
#define GICR       (*(volatile u8 *)0x5B)
#define MCUCR      (*(volatile u8 *)0x55)
#define MCUCSR     (*(volatile u8 *)0x54)

////////////////////////////////////////////////////////////////////////////
////////////          ADC REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////

#define ADMUX      (*(volatile u8 *)0x27)
#define ADCSRA     (*(volatile u8 *)0x26)
#define SFIOR      (*(volatile u8 *)0x50)
#define ADCH       (*(volatile u8 *)0x25)
#define ADCL       (*(volatile u8 *)0x24)
#define ADC        (*(volatile u16 *)0x24)
////////////////////////////////////////////////////////////////////////////
////////////          TIMER0 REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////

#define TCCR0      (*(volatile u8 *)0x53)
#define TCNT0      (*(volatile u8 *)0x52)
#define OCR0       (*(volatile u8 *)0x5C)
#define TIMSK      (*(volatile u8 *)0x59)
#define TIFR       (*(volatile u8 *)0x58)

////////////////////////////////////////////////////////////////////////////
////////////          TIMER2 REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////

#define TCCR2      (*(volatile u8 *)0x53)
#define TCNT2      (*(volatile u8 *)0x52)
#define OCR2       (*(volatile u8 *)0x5C)


////////////////////////////////////////////////////////////////////////////
////////////          TIMER1 REGISTERS   ////////////////////
////////////////////////////////////////////////////////////////////////////

#define TCCR1A       (*(volatile u8 *)0x4F)
#define TCCR1B       (*(volatile u8 *)0x4E)
#define TCNT1H       (*(volatile u8 *)0x4D)
#define TCNT1L       (*(volatile u16 *)0x4C)
#define OCR1AH       (*(volatile u8 *)0x4B)
#define OCR1AL       (*(volatile u16 *)0x4A)
#define OCR1BH       (*(volatile u8 *)0x49)
#define OCR1BL       (*(volatile u16 *)0x48)
#define ICR1H        (*(volatile u8 *)0x47)
#define ICR1L        (*(volatile u16 *)0x46)

////////////////////////////////////////////////////////////////////////////
////////////        WATCHDOG  ////////////////////
////////////////////////////////////////////////////////////////////////////

#define WDTCR        (*(volatile u8 *)0x41)

////////////////////////////////////////////////////////////////////////////
////////////        UART REGISTERS  ////////////////////
////////////////////////////////////////////////////////////////////////////

#define UDR          (*(volatile u8 *)0x2C)
#define UCSRA        (*(volatile u8 *)0x2B)
#define UCSRB        (*(volatile u8 *)0x2A)
#define UCSRC        (*(volatile u8 *)0x40)
#define UBRRL        (*(volatile u8 *)0x29)
#define UBRRH        (*(volatile u8 *)0x40)


////////////////////////////////////////////////////////////////////////////
////////////        SPI REGISTERS  ////////////////////
////////////////////////////////////////////////////////////////////////////

#define SPCR         (*(volatile u8 *)0x2D)
#define SPSR         (*(volatile u8 *)0x2E)
#define SPDR         (*(volatile u8 *)0x2F)


////////////////////////////////////////////////////////////////////////////
////////////        TWI REGISTERS  ////////////////////
////////////////////////////////////////////////////////////////////////////

#define TWDR         (*(volatile u8 *)0x23)
#define TWAR         (*(volatile u8 *)0x22)
#define TWSR         (*(volatile u8 *)0x21)
#define TWBR         (*(volatile u8 *)0x20)
#define TWCR         (*(volatile u8 *)0x56)


#endif /* MCU_H_ */

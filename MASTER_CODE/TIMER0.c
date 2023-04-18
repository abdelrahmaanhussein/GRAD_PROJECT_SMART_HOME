/*
 * TIMER0.c
 *  Layer: Mcal
 *  Created on: Jan 13, 2023
 *      Author: Abdelrahman Hussein
 */
#include"TIMER0.h"
void TIMER0_vTimer0Init(void){
#if TIMER_MODE == NORMAL_MODE
	TCCR0=0b10000011;  // NORMAL MODE- NO PWM - 64 PRESCALER
#elif 	TIMER_MODE == CTC_MODE
	TCCR0=0b00001011;  // CTC MODE- NO PWM - 64 PRESCALE
#endif

	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);

	SET_BIT(SREG,7);   // GLOBAL INTERRUPT
	SET_BIT(TIMSK,TOIE0);  //  overflow INTERRUPT ENABLE
	//OCR0=250;          // COMPARE VALUE

	SET_BIT(DDRD,7);
	SET_BIT(PORTD,7);
}

void (*GGptr)(void)=NULL;

void TIMER0_CALLBACK(void (*ptr)(void)){
	if(ptr!=NULL)
		GGptr=ptr;
}


ISR(VECT_TIMER0_OVF){ ////////VECT_TIMER0_OVF
	if(GGptr!=NULL)
		GGptr();
}

void TIMER0_vOperateTimer0(void){
	TIMER0_CALLBACK(SERVO_CTC);
}

void SERVO_CTC(void){
	static u8 counter=0;
	counter++;
	if(counter==2){
		CLR_BIT(PORTD,7);
		CLR_BIT(PORTC,7);
	}
	else  if(counter==20)
	{
		SET_BIT(PORTD,7);
		SET_BIT(PORTC,7);
		counter=0;
	}


}

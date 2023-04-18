/*
 * TIMER0.h
 *  Layer: Mcal
 *  Created on: Jan 13, 2023
 *      Author: Abdelrahman Hussein
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include"MCU.h"

enum tccr0{CS00,CS01,CS02,WGM01,COM00,COM01,WGM00,FOC0};
enum timsk{TOIE0,OCIE0,TOIE1,OCIE1B,OCIE1A,TICIE1,TOIE2,OCIE2};

#define CTC_MODE 0
#define NORMAL_MODE 1
#define PWM 2
#define TIMER_MODE CTC_MODE

#define OC0 PIN_3
#define SERVO_HALF_DUTY 13
#define SERVO_DUTY 26
#define CTC_INT_ENABLE OCIE0
#define PWM_PIN OC0
#define TIMER0_COMPARE_REG OCR0


#define VECT_TIMER0_OVF __vector_11
#define VECT_TIMER0_comp __vector_10

void TIMER0_vTimer0Init(void);
void TIMER0_CALLBACK(void (*ptr)(void));

void TIMER0_vOperateTimer0(void);
void SERVO_CTC(void);
#endif /* TIMER0_H_ */

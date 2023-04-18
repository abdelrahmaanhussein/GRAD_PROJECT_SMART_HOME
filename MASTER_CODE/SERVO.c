/*
 * SERVO.c
 *  Layer: Hal
 *  Created on: Apr 13, 2023
 *      Author: Abdelrahman Hussein
 */



#include"SERVO.h"

void SERVO_PWM_TMR2(void){
	static u8 counter=0;
	if(counter==0){
		OCR2=SERVO_DUTY;
		counter++;
	}
	else if(counter==1){
		OCR2=SERVO_HALF_DUTY;
		counter--;
	}

}

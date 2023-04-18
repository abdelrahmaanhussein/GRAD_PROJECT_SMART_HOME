/*
 * LED.c
 *  Layer: Hal
 *  Created on: Dec 27, 2022
 *      Author: Abdelrahman Hussein
 */


#include"LED.h"
#include"MCU.h"


void Led_Init(void){
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,7);
	SET_BIT(DDRD,3);
}



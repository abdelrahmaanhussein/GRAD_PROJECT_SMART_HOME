/*
 * ADC.c
 *  Layer: Mcal
 *  Created on: Jan 7, 2023
 *      Author: Abdelrahman Hussein
 */
#include"ADC.h"
#include"LCD.h"
#include"DIO.h"



void ADC_vInit(void){

	/*SETTING ADC1 AS INPUT*/
	CLR_BIT(DDRA,1);

	/*SETTING AVCC*/
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

	/*SETTING LEFT ADJUSTMENT FOR 8 BIT RESOLUTION*/
	SET_BIT(ADMUX,ADLAR);

	/*ADC PRESCALER 128*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	/* ADC ENABLE*/
	SET_BIT(ADCSRA,ADEN);
}
u8 ADC_vReadFlag(void){
	u8 flag= GET_BIT(ADCSRA,ADIF);
	return flag;
}
u32 ADC_vGetAnalogVal(u8 copy_u8Channel){

	/*SETTING CHANNEL*/
	ADMUX&=0b11100000;
	ADMUX|=copy_u8Channel;

	/*STARTING CONVERSION*/
	SET_BIT(ADCSRA,ADSC);

	/*WAITING FOR INTERRUPT FLAG*/
	while 	(!ADC_vReadFlag());

	/*CLEARING ADC INTERRUPT FLAG*/
	SET_BIT(ADCSRA,ADIF);


	return ADCH;
}

void ADC_vOperateAdc(void){

	/*READING ADC CHANNEL*/
	volatile u32 copyAdc = ADC_vGetAnalogVal(ADC1);

	/*SHOWING VALUE ON LCD*/

	LCD_vLcdGoto(First_line,0);
	LCD_vNumToString(copyAdc);
}

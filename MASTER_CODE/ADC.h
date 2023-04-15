/*
 * ADC.h
 *
 *  Created on: Jan 7, 2023
 *      Author: KIT
 */

#ifndef ADC_H_
#define ADC_H_
#include"MCU.h"


enum admux{MUX0,MUX1,MUX2,MUX3,MUX4,ADLAR,REFS0,REFS1};
enum adcsra{ADPS0,ADPS1,ADPS2,ADIE,ADIF,ADATE,ADSC,ADEN};
enum adc_channel{ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7};


#define SFIOR_ADTS0 5
#define SFIOR_ADTS1 6
#define SFIOR_ADTS2 7

void ADC_vInit(void);
u8 ADC_vReadFlag(void);
u32 ADC_vGetAnalogVal(u8 copy_u8Channel);
void ADC_vOperateAdc(void);

#endif /* ADC_H_ */

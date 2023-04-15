/*
 * main.c
 *
 *  Created on: Apr 13, 2023
 *      Author: KIT
 */
#include"APP.h"

int main()
{
	/*INITIALIZING TWI*/
	//TWI_vInitMaster(0);

	/*INITIALIZING LCD*/
	LCD_vLcdInit();

	/*INITIALIZING KEYPAD*/
	KEYPAD_vPortInit();

	/*INITIALIZING BUZZER*/
	InitBuzzer;

	/*INITIALIZING LEDS*/
	Led_Init();

	/*INITIALIZING AIR CONDITIONER*/
	SET_BIT(DDRC,0);

	/*INITIALIZING DIMMER*/
	SET_BIT(DDRA,2);

	/*INITIALIZING TIMER0*/
	TIMER0_vTimer0Init();

	/*INITIALIZING ADC*/
	ADC_vInit();


	/*SETTING ADMIN PASSWORD*/
    //EEPROM_WriteByte(0,admn_pass);

	/*SETTING USER PASSWORD*/
	//EEPROM_WriteByte(5,usr_pass);

	LCD_VWriteString("WELCOME");
	_delay_ms(1000);
	LCD_vLcdClear();

	while(1)
	{

		APP();

	}

	return 0;
}


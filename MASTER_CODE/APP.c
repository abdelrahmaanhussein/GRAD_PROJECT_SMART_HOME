/*
 * APP.c
 *
 *  Created on: Apr 13, 2023
 *      Author: KIT
 */
#include<string.h>
#include"APP.h"
char ADMIN_PASS[]= "1111";
char USER_PASS[]= "2222";

void CheckAdminPassword(void)
{
	u8 password[5];
	static u8	failsCounter=0;
	LCD_VWriteString("enter password!");
	LCD_vLcdGoto(Second_Line,0);
	for(u8 index;index<4;index++)
	{
		while(1)
		{
			password[index] = KEYPAD_u8GetPressedKey();
			if	(password[index] != 0)
			{
				LCD_vWriteCharacter(password[index]);
				break;
			}
		}

	}
	password[4]='\0';
	if(strcmp(ADMIN_PASS,password) == 0)
	{
		LCD_vLcdClear();
		LCD_VWriteString("right password!");
		return;
	}
	else
	{
		LCD_vLcdClear();
		LCD_VWriteString("wrong password!");
		_delay_ms(500);
		LCD_vLcdClear();
		if(failsCounter < 3)
		{
			LCD_VWriteString("reenter password!");
			_delay_ms(500);
			LCD_vLcdClear();
			failsCounter ++;
			CheckAdminPassword();
		}
		else
		{
			LCD_VWriteString("block mode!");
			TRIGGER_BUZZER;
			_delay_ms(20000);
			END_BUZZER;
			LCD_vLcdClear();
			failsCounter =0;
			CheckAdminPassword();
		}
	}

}

void CheckUserPassword(void)
{
	u8 password[5];
	static u8	failsCounter=0;
	LCD_VWriteString("enter password!");
	LCD_vLcdGoto(Second_Line,0);
	for(u8 index;index<4;index++)
	{
		while(1)
		{
			password[index] = KEYPAD_u8GetPressedKey();
			if	(password[index] != 0)
			{
				LCD_vWriteCharacter(password[index]);
				break;
			}
		}

	}
	password[4]='\0';
	if(strcmp(USER_PASS,password) == 0)
	{
		LCD_vLcdClear();
		LCD_VWriteString("right password!");
		return;
	}
	else
	{
		LCD_vLcdClear();
		LCD_VWriteString("wrong password!");
		_delay_ms(500);
		LCD_vLcdClear();
		if(failsCounter < 3)
		{
			LCD_VWriteString("reenter password!");
			_delay_ms(500);
			LCD_vLcdClear();
			failsCounter ++;
			CheckUserPassword();
		}
		else
		{
			LCD_VWriteString("block mode!");
			TRIGGER_BUZZER;
			_delay_ms(20000);
			END_BUZZER;
			LCD_vLcdClear();
			failsCounter =0;
			CheckUserPassword();
		}
	}

}

void APP(void)
{

	u8 key=0,key2=0;
	u8 key3=0,key4=0;
	u32 temperature;
	LCD_VWriteString("1:admin  2:user");
	while(1)
	{
		key=KEYPAD_u8GetPressedKey();
		if(key=='1')                /// ADMIN CONTROL
		{
			LCD_vLcdClear();
			LCD_vWriteCharacter(key);
			_delay_ms(500);
			LCD_vLcdClear();
			CheckAdminPassword();

			LCD_vLcdClear();
			LCD_VWriteString("1:choose room");
			LCD_vLcdGoto(Second_Line,0);
			LCD_VWriteString("2:more");
			while(1)
			{
				key2=KEYPAD_u8GetPressedKey();
				if(key2=='1')           // ADMIN ROOM CONTROL
				{
					LCD_vLcdClear();
					LCD_VWriteString("1:room1 2:room2");

					while(1)
					{
						key3 =KEYPAD_u8GetPressedKey();
						if(key3 == '1')         // ROOM 1 ON OFF
						{
							LCD_vLcdClear();
							LCD_VWriteString("r1: 1:on 2:off");
							while(1)
							{
								key4=KEYPAD_u8GetPressedKey();
								if(key4 == '1')
								{
									SET_BIT(PORTC,7);
									LCD_vLcdClear();
									break;
								}
								else if	(key4 == '2')
								{
									CLR_BIT(PORTC,7);
									LCD_vLcdClear();
									break;
								}
							}
							break;
						}
						else 		if(key3 == '2') // ROOM 2 ON OFF
						{
							LCD_vLcdClear();
							LCD_VWriteString("r2: 1:on 2:off");
							while(1)
							{
								key4=KEYPAD_u8GetPressedKey();
								if(key4 == '1')
								{
									SET_BIT(PORTC,2);
									LCD_vLcdClear();
									break;
								}
								else if	(key4 == '2')
								{
									CLR_BIT(PORTC,2);
									LCD_vLcdClear();
									break;
								}
							}
							break;
						}
					}
					break;
				}
				else if (key2=='2')    // AC-DOOR-DIM CONTROL
				{
					LCD_vLcdClear();
					LCD_VWriteString("1:ac 2:door 3:dim");

					while(1)
					{
						key3 =KEYPAD_u8GetPressedKey();
						if(key3 == '1')         // AC CONTROL
						{
							temperature =ADC_vGetAnalogVal(ADC1);
							LCD_vLcdClear();
							LCD_vNumToString(temperature);
							while(1)
							{
								temperature =ADC_vGetAnalogVal(ADC1);
								if(temperature >30)
								{

									SET_BIT(PORTC,0);
									//LCD_vLcdClear();
									LCD_vNumToString(temperature);
									LCD_vLcdGoto(0,0);
									//break;
								}
								else if	(temperature <30)
								{
									CLR_BIT(PORTC,0);
									//LCD_vLcdClear();
									LCD_vNumToString(temperature);
									LCD_vLcdGoto(0,0);
									//break;
								}
								if(temperature==0)
								{
									break;

								}
							}
							break;
						}
						else 		if(key3 == '2') // DOOR CONTROL
						{

							LCD_vLcdClear();
							LCD_VWriteString("door: 1:open");
							while(1)
							{
								key4=KEYPAD_u8GetPressedKey();
								if(key4 == '1')
								{
									LCD_vLcdClear();
									LCD_vWriteCharacter(key4);
									while(1)
									{

										for(u8 index=0;index<21;index++)
										{
											TIMER0_CALLBACK(SERVO_CTC);
											_delay_ms(100);
										}

										if(GET_BIT(PIND,7))
										{
											break;
										}
									}
									LCD_vLcdClear();
									break;
								}

							}
							break;
						}
						else 		if(key3 == '3') // DIMMER CONTROL
						{

							LCD_vLcdClear();
							LCD_VWriteString("dimmer control");
					        _delay_ms(20000);
							LCD_vLcdClear();


							break;
						}
					}
					break;
				}
			}
			break;
		}
		else if (key=='2')   // USER ROOM CONTROL
		{
			LCD_vLcdClear();
			LCD_vWriteCharacter(key);
			_delay_ms(1000);
			LCD_vLcdClear();
			CheckUserPassword();


			LCD_vLcdClear();
			LCD_VWriteString("1:room1 2:room2");

			while(1)
			{
				key3 =KEYPAD_u8GetPressedKey();
				if(key3 == '1')       //     ROOM 1 ON OFF
				{
					LCD_vLcdClear();
					LCD_VWriteString("r1: 1:on 2:off");
					while(1)
					{
						key4=KEYPAD_u8GetPressedKey();
						if(key4 == '1')
						{
							SET_BIT(PORTC,7);
							LCD_vLcdClear();
							break;
						}
						else if	(key4 == '2')
						{
							CLR_BIT(PORTC,7);
							LCD_vLcdClear();
							break;
						}
					}
					break;
				}
				else if(key3 == '2')       //     ROOM 2 ON OFF
				{
					LCD_vLcdClear();
					LCD_VWriteString("r2: 1:on 2:off");
					while(1)
					{
						key4=KEYPAD_u8GetPressedKey();
						if(key4 == '1')
						{
							SET_BIT(PORTC,2);
							LCD_vLcdClear();
							break;
						}
						else if	(key4 == '2')
						{
							CLR_BIT(PORTC,2);
							LCD_vLcdClear();
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}


}




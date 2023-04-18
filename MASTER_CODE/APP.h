/*
 * APP.h
 *  Layer: App
 *  Created on: Apr 13, 2023
 *      Author: Abdelrahman Hussein
 */

#ifndef APP_H_
#define APP_H_
#include<util\delay.h>
#include"LED.h"
#include"MCU.h"
#include"LCD.h"
#include"KEYPAD.h"
#include"EEPROM.h"
#include"UART.h"
#include"ADC.h"
#include"TIMER0.h"
#include"SERVO.h"
#include"TWI.h"

#define admn_pass 11
#define usr_pass 22

#define InitBuzzer SET_BIT(DDRA,3)
#define TRIGGER_BUZZER SET_BIT(PORTA,3)
#define END_BUZZER CLR_BIT(PORTA,3)

#define InitAc SET_BIT(DDRA,0)
#define StartAc SET_BIT(PORTA,0)
#define StopAc CLR_BIT(PORTA,0)

#define InitDimmer SET_BIT(DDRA,2)


void RoomControl(void);
void Modules(void);
void AdminControl(void);
void UserControl(void);
void AdminUserControl(void);
void CheckAdminPassword(void);
void CheckUserPassword(void);
void APP(void);

#endif /* APP_H_ */

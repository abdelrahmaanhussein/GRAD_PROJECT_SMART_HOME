/*
 * LCD.h
 *
 *  Created on: Dec 30, 2022
 *      Author: KIT
 */

#ifndef LCD_H_
#define LCD_H_
#include"MCU.h"
#define First_line 0x80
#define Second_Line 0xC0
#define clear 0x01



void LCD_vLcdInit();
void LCD_vSendCommand(u8 LOC_u8Command);
void LCD_vWriteCharacter(u8 LOC_u8Character);
void LCD_VWriteString(u8 *ptr);
void LCD_vLcdClear(void);
void LCD_vLcdGoto(u8 Line,u8 Cursor_Position);

u8 	LCD_u8GetSize(u16 size);
void LCD_vNumToString(u32 num);
#endif /* LCD_H_ */

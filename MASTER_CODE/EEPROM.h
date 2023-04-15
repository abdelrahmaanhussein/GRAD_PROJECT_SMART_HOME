/*
 * EEPROM.h
 *
 *  Created on: Mar 15, 2023
 *      Author: KIT
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include"MCU.h"

#define EEPROM_FIXED_ADDRESS 0b1010000


void EEPROM_WriteByte(u16 Copy_u16locAddress,u8 copyu8DataByte);
u8 EEPROM_ReadByte(u16 Copy_u16locAddress);

#endif /* EEPROM_H_ */

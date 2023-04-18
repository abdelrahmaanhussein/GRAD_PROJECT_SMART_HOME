/*
 * Keypad.h
 *  Layer: Hal
 *  Created on: Dec 31, 2022
 *      Author: Abdelrahman Hussein
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"MCU.h"

void KEYPAD_vPortInit(void);
u8 KEYPAD_u8GetPressedKey(void);

#endif /* KEYPAD_H_ */

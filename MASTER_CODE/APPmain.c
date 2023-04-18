/*
 * APPmain.c
 *  Layer: App
 *  Created on: Apr 13, 2023
 *      Author: Abdelrahman Hussein
 */
#include"APP.h"


void APP(void)
{

	u8 key=0;
	LCD_VWriteString("1:admin  2:user");
	while(1)
	{
		key=KEYPAD_u8GetPressedKey();
		if(key=='1')                /// ADMIN CONTROL
		{
			AdminControl();
			break;
		}
		else if (key=='2')   // USER ROOM CONTROL
		{
			UserControl();
			break;
		}
	}


}



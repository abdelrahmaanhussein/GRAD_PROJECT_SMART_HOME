#include"Keypad.h"
#include"DIO.h"
u8 arr[4][4]={{'/','*','-','+'},{'=','9','6','3'},{'0','8','5','2'},{'%','7','4','1'}};
void KEYPAD_vPortInit(void){
	DIO_vSetPortDirection(PortD,PORT_OUTPUT);
	DDRB&=0x0F;

	SET_BIT(PORTB,PIN_4);
	SET_BIT(PORTB,PIN_5);     // PULL UP RESISTOR
	SET_BIT(PORTB,PIN_6);
	SET_BIT(PORTB,PIN_7);

	SET_BIT(PORTD,PIN_0);
	SET_BIT(PORTD,PIN_1);   // SETTING COLUMNS VALUE
	SET_BIT(PORTD,PIN_2);
	SET_BIT(PORTD,PIN_3);
}
u8 KEYPAD_u8GetPressedKey(){
	u8 index,index2;
	for(index=0;index<4;index++){
		CLR_BIT(PORTD,index);
		for(index2=0;index2<4;index2++){
			if(!(GET_BIT(PINB,(index2+4))))
			{
				_delay_ms(25);
				while((GET_BIT(PINB,(index2+4))));
				if(!(GET_BIT(PINB,(index2+4))))
					return arr[index][index2];
			}
		}
		SET_BIT(PORTD,index);
	}
	return 0;
}


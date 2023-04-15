#include"DIO.h"
#include"LCD.h"

void LCD_vLcdInit(){
	DIO_vSetPinDir(PortA,PIN_4,PIN_HIGH);
	DIO_vSetPinDir(PortA,PIN_5,PIN_HIGH);
	DIO_vSetPinDir(PortA,PIN_6,PIN_HIGH);
	DIO_vSetPinDir(PortA,PIN_7,PIN_HIGH);


	DIO_vSetPinDir(PortB,PIN_1,PIN_HIGH);
	DIO_vSetPinDir(PortB,PIN_2,PIN_HIGH);
	DIO_vSetPinDir(PortB,PIN_3,PIN_HIGH);

	_delay_ms(50);
	LCD_vSendCommand(0x01);   // clear
	_delay_ms(50);
	LCD_vSendCommand(0x28);  //4 bit mode //0x28 2lines //0x20 1line
	_delay_ms(50);
	LCD_vSendCommand(0x06);  //increment
	_delay_ms(50);
	LCD_vSendCommand(0x0F);  //display
	_delay_ms(50);


}

void LCD_vSendCommand(u8 LOC_u8Command){
	CLR_BIT(PORTB,PIN_1); //1
	CLR_BIT(PORTB,PIN_2); //2
	CLR_BIT(PORTB,PIN_3); //3
	DIO_vSetPortValue(PortA,(LOC_u8Command&0xF0));
	SET_BIT(PORTB,PIN_3); //3
	_delay_ms(50);
	CLR_BIT(PORTB,PIN_3); //3
	DIO_vSetPortValue(PortA,(LOC_u8Command<<4));
	SET_BIT(PORTB,PIN_3); //3
	_delay_ms(50);
	CLR_BIT(PORTB,PIN_3); //3
}


void LCD_vWriteCharacter(u8 LOC_u8Character){
	SET_BIT(PORTB,PIN_1);//1
	CLR_BIT(PORTB,PIN_2);//2
	CLR_BIT(PORTB,PIN_3);//3
	DIO_vSetPortValue(PortA,(LOC_u8Character&0xF0));
	SET_BIT(PORTB,PIN_3);//3
	_delay_ms(50);
	CLR_BIT(PORTB,PIN_3);//3
	DIO_vSetPortValue(PortA,(LOC_u8Character<<4));
	SET_BIT(PORTB,PIN_3);//3
	_delay_ms(50);
	CLR_BIT(PORTB,PIN_3);//3


}
void LCD_VWriteString(u8 *ptr){
	u8 index;
	for(index=0;ptr[index]!='\0';index++){
		LCD_vWriteCharacter(ptr[index]);
	}
}
void LCD_vLcdClear(void){
	LCD_vSendCommand(0x01);
}
void LCD_vLcdGoto(u8 Line,u8 Cursor_Position){
	LCD_vSendCommand(Line+Cursor_Position);
}


u8 	LCD_u8GetSize(u16 val){
	u8 counter=0;
	while(val!=0){
		val/=10;
		counter++;
	}
	return counter;
}
void LCD_vNumToString(u32 num){
	static u32 oldNum=0;
	if(oldNum!=num){
		oldNum=num;
		LCD_vSendCommand(clear);
	}

	u8 arr[6],index;
	u16 a=num;
	u8 size =LCD_u8GetSize(a);
	for(index=0;index<size;index++){
		u8 x=a%10;
		a/=10;
		arr[size-(index+1)]=x+'0';
	}
	arr[size]='\0';
	LCD_VWriteString(arr);
	_delay_ms(100);
}


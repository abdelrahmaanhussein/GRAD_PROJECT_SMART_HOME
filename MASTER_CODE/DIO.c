/*
 * DIO.c
 *  Layer: Mcal
 *  Created on: Dec 13, 2022
 *      Author: Abdelrahman Hussein
 */



#include "DIO.h"
void DIO_vSetPortDirection(u8 LOC_u8PortID,u8 LOC_u8PortDirection){
	if(LOC_u8PortID<=PortD)
	{
		if (LOC_u8PortID==PortA){
			DDRA=LOC_u8PortDirection;
		}
		else if (LOC_u8PortID==PortB)
		{
			DDRB=LOC_u8PortDirection;
		}
		else if (LOC_u8PortID==PortC)
		{
			DDRC=LOC_u8PortDirection;
		}
		else if (LOC_u8PortID==PortD)
		{
			DDRD=LOC_u8PortDirection;
		}

	}
}

void DIO_vSetPortValue(u8 LOC_u8PortID,u8 LOC_u8PortValue){
	if(LOC_u8PortID<=PortD)
	{
		if (LOC_u8PortID==PortA){
			PORTA= LOC_u8PortValue;
		}
		else	if (LOC_u8PortID==PortB){
			PORTB=LOC_u8PortValue;
		}
		else if (LOC_u8PortID==PortC){
			PORTC=LOC_u8PortValue;
		}
		else if (LOC_u8PortID==PortD){
			PORTD=LOC_u8PortValue;
		}

	}
}
void DIO_vClrPortValue(u8 LOC_u8PortID,u8 LOC_u8PortValue){
	if(LOC_u8PortID<=PortD)
	{
		if (LOC_u8PortID==PortA){
			PORTA= 0;
		}
		else	if (LOC_u8PortID==PortB){
			PORTB=0;
		}
		else if (LOC_u8PortID==PortC){
			PORTC=0;
		}
		else if (LOC_u8PortID==PortD){
			PORTD=0;
		}

	}
}
u8 DIO_u8GetPortValue(u8 LOC_u8PortID){
	u8 LOC_u8PortValue;
	if(LOC_u8PortID<=PortD)
	{
		if (LOC_u8PortID==PortA){
			LOC_u8PortValue=PINA;
		}
		else if (LOC_u8PortID==PortB){
			LOC_u8PortValue=PINB;
		}
		else if (LOC_u8PortID==PortC){
			LOC_u8PortValue=PINC;
		}
		else if (LOC_u8PortID==PortD){
			LOC_u8PortValue=PIND;
		}

	}
	return LOC_u8PortValue;
}
void DIO_vtogPortValue(u8 LOC_u8PortID){

	if(LOC_u8PortID<=PortD)
	{
		if (LOC_u8PortID==PortA){
			PORTA=~PORTA;
		}
		else if (LOC_u8PortID==PortB){
			PORTB^=(~0);
		}
		else if (LOC_u8PortID==PortC){
			PORTC^=(~0);
		}
		else if (LOC_u8PortID==PortD){
			PORTD^=(~0);
		}

	}
}
void DIO_vSetPinDir(u8 LOC_u8PortID,u8 LOC_u8Pin,u8 LOC_u8Dir){
	if(LOC_u8PortID<=PortD){
		if(LOC_u8PortID==PortA){
			if(LOC_u8Dir==PIN_HIGH){
				SET_BIT(DDRA,LOC_u8Pin);
			}
			else if(LOC_u8Dir==PIN_LOW){
				CLR_BIT(DDRA,LOC_u8Pin);
			}
		}
		if(LOC_u8PortID==PortB){
			if(LOC_u8Dir==PIN_HIGH){
				SET_BIT(DDRB,LOC_u8Pin);
			}
			else if(LOC_u8Dir==PIN_LOW){
				CLR_BIT(DDRB,LOC_u8Pin);
			}
		}
		if(LOC_u8PortID==PortC){
			if(LOC_u8Dir==PIN_HIGH){
				SET_BIT(DDRC,LOC_u8Pin);
			}
			else if(LOC_u8Dir==PIN_LOW){
				CLR_BIT(DDRC,LOC_u8Pin);
			}
		}
		if(LOC_u8PortID==PortD){
			if(LOC_u8Dir==PIN_HIGH){
				SET_BIT(DDRD,LOC_u8Pin);
			}
			else if(LOC_u8Dir==PIN_LOW){
				CLR_BIT(DDRD,LOC_u8Pin);
			}
		}
	}
}
void DIO_vSetPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin){
	if(LOC_u8PortID<=PortD){
		if(LOC_u8PortID==PortA){
			SET_BIT(PORTA,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortB){
			SET_BIT(PORTB,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortC){
			SET_BIT(PORTC,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortD){
			SET_BIT(PORTD,LOC_u8Pin);
		}
	}
}
void DIO_vClrPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin){
	if(LOC_u8PortID<=PortD){
		if(LOC_u8PortID==PortA){
			CLR_BIT(PORTA,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortB){
			CLR_BIT(PORTB,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortC){
			CLR_BIT(PORTC,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortD){
			CLR_BIT(PORTD,LOC_u8Pin);
		}
	}
}
void DIO_vTogPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin){
	if(LOC_u8PortID<=PortD){
		if(LOC_u8PortID==PortA){
			TOG_BIT(PORTA,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortB){
			TOG_BIT(PORTB,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortC){
			TOG_BIT(PORTC,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortD){
			TOG_BIT(PORTD,LOC_u8Pin);
		}
	}
}
u8 DIO_u8GetPinVal(u8 LOC_u8PortID,u8 LOC_u8Pin){
	if(LOC_u8PortID<=PortD){
		if(LOC_u8PortID==PortA){
			return	GET_BIT(PINA,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortB){
			return      	GET_BIT(PINB,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortC){
			return	GET_BIT(PINC,LOC_u8Pin);
		}
		if(LOC_u8PortID==PortD){
			return 	GET_BIT(PIND,LOC_u8Pin);
		}
	}
}
/*
int main(){
//u8 count =DIO_u8GetPortValue(PortA);

return 0;
}

 */


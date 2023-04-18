/*
 * EEPROM.c
 *  Layer: Mcal
 *  Created on: Mar 15, 2023
 *      Author: Abdelrahman Hussein
 */



#include"EEPROM.h"
#include"TWI.h"
void EEPROM_WriteByte(u16 Copy_u16locAddress,u8 copyu8DataByte){

	u8 Local_u8AddressPacket= EEPROM_FIXED_ADDRESS | (u8)(Copy_u16locAddress>>8);

	/*send start condition*/
	TWI_SendStartCondition();

	/*send address packet*/
	TWI_SendSlaveAddresWithWrite(Local_u8AddressPacket);

	/*write the 8 lsb of location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16locAddress);

	/*writing data byte*/
	TWI_MasterWriteDataByte(copyu8DataByte);

	/*send stop condition*/
	TWI_SendStopCondition();

	_delay_ms(5);

}
u8 EEPROM_ReadByte(u16 Copy_u16locAddress){

	u8 Local_u8DataByte;

	u8 Local_u8AddressPacket= EEPROM_FIXED_ADDRESS | (u8)(Copy_u16locAddress>>8);

	/*send start condition*/
	TWI_SendStartCondition();

	/*send address packet*/
	TWI_SendSlaveAddresWithWrite(Local_u8AddressPacket);

	/*write the 8 lsb of location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16locAddress);

	/*send repeated start*/
	TWI_SendRepeatedStart();

	/*send slave address with read*/
	TWI_SendSlaveAddresWithRead(Local_u8AddressPacket);

	/*master read data byte*/
	TWI_MasterReadDataByte(&Local_u8DataByte);

	/*send stop condition*/
	TWI_SendStopCondition();

	return Local_u8DataByte;
}



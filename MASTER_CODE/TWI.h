/*
 * TWI.h
 *  Layer: Mcal
 *  Created on: Mar 14, 2023
 *      Author: Abdelrahman Hussein
 */

#ifndef TWI_H_
#define TWI_H_
#include"MCU.h"
#include"TWI_PRIVATE.h"

#define TWSR_TWPS0 0
#define TWSR_TWPS1 1

#define TWAR_TWGCE 1

#define TWDR_RW 0

enum twcr{TWIE,TWEN=2,TWWC,TWSTO,TWSTA,TWEA,TWINT};
typedef enum
{
	NoError,
	StartConditionErr,
	ReapeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,

}TWI_ErrStatus;

void TWI_vInitMaster(u8 copy_u8Address);

void TWI_vInitSlave(u8 copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddresWithWrite(u8 copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddresWithRead(u8 copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* copy_u8DataByte);

void TWI_SendStopCondition(void);

void Led_Init(void);
#endif /* TWI_H_ */

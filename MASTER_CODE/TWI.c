#include"TWI.h"

// IF MASTER IS NOT TO BE ADDRESSED PASS 0
void TWI_vInitMaster(u8 copy_u8Address){
	TWBR=12;
	CLR_BIT(TWSR,TWSR_TWPS0); /* SETTING SCL FREQ TO 400 KBPS */
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*setting master address*/
	if(copy_u8Address!=0){
		TWAR=copy_u8Address<<1;
	}
	else {
		/*do nothing*/
	}
	/*ENABLING ACKNOWLEDGE*/
	SET_BIT(TWCR,TWEA);
	/*ENABLING TWI*/
	SET_BIT(TWCR,TWEN);

}

void TWI_vInitSlave(u8 copy_u8Address){

	/*setting slave address*/
	TWAR=copy_u8Address<<1;

	/*ENABLING ACKNOWLEDGE*/
	SET_BIT(TWCR,TWEA);

	/*ENABLING TWI*/
	SET_BIT(TWCR,TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void){

	TWI_ErrStatus Local_err= NoError;

	/*sending start condition*/
	SET_BIT(TWCR,TWSTA);

	/*clearing twi flag*/
	SET_BIT(TWCR,TWINT);

	/*waiting till transmission complete and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	if((TWSR & 0xF8) !=START_CONDITION){

     	Local_err= StartConditionErr;

	}
	else {

		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);

	}

	return Local_err;
}

TWI_ErrStatus TWI_SendRepeatedStart(void){

	TWI_ErrStatus Local_err= NoError;

	/*sending start condition*/
	SET_BIT(TWCR,TWSTA);

	/*clearing twi flag*/
	SET_BIT(TWCR,TWINT);

	/*waiting till operation finishes and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	if(( TWSR& 0xF8) !=REP_START){
	Local_err=ReapeatedStartErr;
	}
	else {
		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);
	}

	return Local_err;

}

TWI_ErrStatus TWI_SendSlaveAddresWithWrite(u8 copy_u8SlaveAddress){

	TWI_ErrStatus Local_err= NoError;

	/*copy slave address*/
	TWDR =copy_u8SlaveAddress<<1;

	/*write operation*/
	CLR_BIT(TWDR,TWDR_RW);

	/*clear start condition bit*/
	CLR_BIT(TWCR,TWSTA);

	/*clearing twi flag*/
	SET_BIT(TWCR,TWINT);

	/*waiting till operation finishes and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	/*CHECK OPERATION STATUS*/
	if((TWSR & 0xF8) != SLA_WITH_WRITE_ACK){

		Local_err= SlaveAddressWithWriteErr;
	}
	else {
		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);
	}

	return Local_err;
}

TWI_ErrStatus TWI_SendSlaveAddresWithRead(u8 copy_u8SlaveAddress){

	TWI_ErrStatus Local_err= NoError;

	/*copy slave address*/
	TWDR =copy_u8SlaveAddress<<1;

	/*read operation*/
	SET_BIT(TWDR,TWDR_RW);

	/*clear start condition bit*/
	CLR_BIT(TWCR,TWSTA);

	/*clearing twi flag*/
	SET_BIT(TWCR,TWINT);

	/*waiting till operation finishes and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	/*CHECK OPERATION STATUS*/
	if((TWSR & 0xF8) != SLA_WITH_READ_ACK){

		Local_err= SlaveAddressWithReadErr;
	}
	else {
		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);
	}

	return Local_err;

}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 copy_u8DataByte){

	TWI_ErrStatus Local_err= NoError;

	/*write data byte*/
	TWDR = copy_u8DataByte;

	/*clearing twi flag to start previous operation*/
	SET_BIT(TWCR,TWINT);

	/*waiting till operation finishes and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	/*CHECK OPERATION STATUS*/
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK){

		Local_err= MasterWriteByteErr;
	}
	else {
		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);
	}

	return Local_err;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8* copy_u8DataByte){

	TWI_ErrStatus Local_err= NoError;

	/*clearing twi flag to allow slave to send data*/
	SET_BIT(TWCR,TWINT);

	/*waiting till operation finishes and flag is raised*/
	while((GET_BIT(TWCR,TWINT))==0);

	/*CHECK OPERATION STATUS*/
	if((TWSR & 0xF8) != MSTR_RD_BYTE_ACK){

		Local_err= MasterReadByteErr;
	}
	else {

		/*reading data byte*/
		*copy_u8DataByte =TWDR;

		SET_BIT(PORTC,2);
		_delay_ms(2000);
		CLR_BIT(PORTC,2);
	}


	return Local_err;
}

void TWI_SendStopCondition(void){

	/*send stop condition*/
	SET_BIT(TWCR,TWSTO);

	/*clearing twi flag to start previous operation*/
	SET_BIT(TWCR,TWINT);
}

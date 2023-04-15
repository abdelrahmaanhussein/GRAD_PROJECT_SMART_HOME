#include"SPI.h"
void SPI_vMasterInit(void){
	
	    SET_BIT(DDRB,MOSI);
		CLR_BIT(DDRB,MISO);
		SET_BIT(DDRB,SCK);
		CLR_BIT(DDRB,SS);
		SET_BIT(PORTB,SS); // SETTING SS AS INPUT AND PULLED UP

		SET_BIT(SPCR,MSTR);     // MASTER MODE

		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);     //  SETTING PRESCALE TO 64
		CLR_BIT(SPSR,SPI2X);

	    SET_BIT(SPCR,SPE);      // SPI ENABLE




		SET_BIT(DDRC,0);
		CLR_BIT(PORTC,0);  /* DIO OUTPUT TO SS  */

}

u8 SPI_u8TranCeive(u8 data_sent){
	SPDR =data_sent;
	while(!(GET_BIT(SPSR,SPIF)));
	return SPDR;
}
void SPI_ResetSlave(void){

	SET_BIT(PORTC,0);
	_delay_ms(10);

	CLR_BIT(PORTC,0);
}

#ifndef SPI_H_
#define SPI_H_

#include"MCU.h"
#define master 0
#define slave 1

#define SPI2X 0
#define WCOL 6       //// SPSR /////
#define SPIF 7

#define LSB 0
#define MSB 7        //// SPDR /////

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7


enum spcr{SPR0,SPR1,CPHA,CPOL,MSTR,DORD,SPE,SPIE};

void SPI_vMasterInit(void);
u8 SPI_u8TranCeive(u8 data_sent);
void SPI_ResetSlave(void);












#endif /* SPI_H_ */

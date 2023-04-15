/*
 * TWI_PRIVATE.h
 *
 *  Created on: Mar 14, 2023
 *      Author: KIT
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_CONDITION 0x08
#define REP_START 0x10
#define SLA_WITH_WRITE_ACK 0x18
#define SLA_WITH_READ_ACK 0x40
#define MSTR_WR_BYTE_ACK 0x28
#define MSTR_RD_BYTE_ACK 0x50
#define MSTR_RD_BYTE_NACK 0x58
#define SLAVE_ADD_RCVD_RD_REQ 0xA8
#define SLAVE_ADD_RCVD_WR_REQ 0x60
#define SLAVE_DATA_RCVD 0x80
#define SLAVE_BYTE_TRANSMITTED 0xB8

#endif /* TWI_PRIVATE_H_ */

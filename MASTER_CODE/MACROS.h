/*
 * MACROS.h
 *
 *  Created on: Dec 27, 2022
 *      Author: KIT
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bitno) reg|=(1<<bitno)
#define GET_BIT(reg,bitno) (reg>>bitno)&1
#define CLR_BIT(reg,bitno) reg&=(~(1<<bitno))
#define TOG_BIT(reg,bitno) reg^=(1<<bitno)



#endif /* MACROS_H_ */

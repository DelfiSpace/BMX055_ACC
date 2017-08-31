/* Code written by Chia Jiun Wei @ 31 Aug 2017
 * <J.W.Chia@tudelft.nl>
 
 * BMX055_ACC: a library to provide high level APIs to interface with 
 * the Bosch Absolute Orientation Sensors accelerometer. It is  
 * possible to use this library in Energia (the Arduino port for 
 * MSP microcontrollers) or in other toolchains.
 
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 
 * version 3, both as published by the Free Software Foundation.
  
 */
 
#ifndef BMX055_ACC_H
#define BMX055_ACC_H

#include <Energia.h>
#include <DSPI.h>

#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include "bma2x2.h"

#ifdef __cplusplus
}
#endif
	
	//Read write function interface with Bosch accelerometer bma2x2 API
	s8 readRegister(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 size);
	s8 writeRegister(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 size);
	void delay_msek(u32 msek);
	
class BMX055_ACC

{
protected:	
	
	bma2x2_t bma2x2;
	
public:
	
	BMX055_ACC(DSPI *spi, unsigned char pin);
	virtual ~BMX055_ACC( ) {};
	
	void init();
	signed char ping();
	void get_acc(s16 *data_array);
	
private:	
	
};


#endif  // BMX055_ACC_H
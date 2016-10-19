/*
 * bsk.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: timppa
 */

#include "hardware.h"
#include "i2c.h"
#include "delay.h"
#include "display.h"
#include "bsk.h"

/************************************************************************
 *
 *   IMPLEMENTATION BELOW
 *
 ************************************************************************/

//
// get_throw reads the BSK pin counting device and returns
// the number of knocked pins via the "pFrame" structure
//
// return value for the subroutine is:
//   ERR_PARAM_NULL if pFrame is zero/NULL
//   ERR_BAD_THROW if index is not 1 or 2
//   1 for reading the first throw
//   2 for reading the second throw
//   ERR_READ_FAILED if i2c_read returns other than 1
//
int bsk_get_throw(bsk_frame_t* pFrame,int index)
{
	if ( 0==pFrame ){
		return ERR_PARAM_NULL;
	}else if(index == 1){
		char buffer;
		i2c_read(0x90, 0,0,&buffer, 1);
		pFrame->first_throw = buffer;
		return 1;
	}else if (index == 2){
		char buffer;
		i2c_read(0x90, 0,0, &buffer, 1);
		pFrame->second_throw = buffer;
		return 2;
	}




	return ERR_BAD_THROW;
}

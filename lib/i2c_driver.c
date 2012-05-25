//ipi2c.c

#include "i2c_driver.h"
#include "utils.h"
#include <stdio.h>

///////////////   Private functions  //////////////////
void i2cConfig(void) {
	//Configuration is actually done by each module independently.
	//This may change in the future.
}


///////////////   Public functions  //////////////////
//This is the PUBLIC setup function;
void i2cSetup(void){
	i2cConfig();
	//Do any other setup....
}

/*****************************************************************************
* Function Name : i2cStartTx
* Description   : Start I2C transmission on a specified I2C channel
* Parameters    : channel is the channel number
* Return Value  : None
*****************************************************************************/
void i2cStartTx(unsigned char channel){
	if     (channel == 1) { StartI2C1(); while(I2C1CONbits.SEN); }
	else if(channel == 2) { StartI2C2(); while(I2C2CONbits.SEN); }
}

/*****************************************************************************
* Function Name : i2cEndTx
* Description   : End I2C transmission on a specified I2C channel
* Parameters    : channel is the channel number
* Return Value  : None
*****************************************************************************/
void i2cEndTx(unsigned char channel){
	if     (channel == 1) { StopI2C1(); while(I2C1CONbits.PEN); }
	else if(channel == 2) { StopI2C2(); while(I2C2CONbits.PEN); }
}

/*****************************************************************************
* Function Name : i2cSendNACK
* Description   : Send NACK to a specified I2C channel
* Parameters    : channel is the channel number
* Return Value  : None
*****************************************************************************/
void i2cSendNACK(unsigned char channel){
	if     (channel == 1) { NotAckI2C1(); while(I2C1CONbits.ACKEN); }
	else if(channel == 2) { NotAckI2C2(); while(I2C2CONbits.ACKEN); }
}

/*****************************************************************************
* Function Name : i2cReceiveByte
* Description   : Receive a byte from a specified I2C channel
* Parameters    : channel is the channel number
* Return Value  : None
*****************************************************************************/
unsigned char i2cReceiveByte(unsigned char channel) {
	unsigned char temp;
	if     (channel == 1) { temp = MasterReadI2C2(); }
	else if(channel == 2) { temp = MasterReadI2C2(); }
	return temp;
}

/*****************************************************************************
* Function Name : i2cSendByte
* Description   : Send a byte to a specified I2C channel
* Parameters    : channel is the channel number
				  byte - a byte to send
* Return Value  : None
*****************************************************************************/
void i2cSendByte(unsigned char channel, unsigned char byte ) {
	if     (channel == 1) {
		MasterWriteI2C1(byte);
    	while(I2C1STATbits.TRSTAT);
    	while(I2C1STATbits.ACKSTAT);
	}
	else if(channel == 2) {
		MasterWriteI2C2(byte);
    	while(I2C2STATbits.TRSTAT);
    	while(I2C2STATbits.ACKSTAT);
	}
}

/*****************************************************************************
* Function Name : i2cReadString
* Description   : It reads predetermined data string length from the I2C bus.
* Parameters    : channel is the I2C channel to read from
				  length is the string length to read
*                 data is the storage for received gyro data
*                 data_wait is the timeout value
* Return Value  : Number of bytes read before timeout.
*****************************************************************************/
unsigned int i2cReadString(unsigned char channel, unsigned length, unsigned char * data,
                                   unsigned int data_wait) {
    unsigned int res;
	if     (channel == 1) {
		res = MastergetsI2C1(length, data, data_wait);
	}
	else if(channel == 2) {
		res = MastergetsI2C2(length, data, data_wait);
	}
	return res;
}

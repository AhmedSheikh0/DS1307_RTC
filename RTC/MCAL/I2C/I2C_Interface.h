#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
/*
typedef enum
{
	NoError = 0,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,


}TWI_ErrorStatus;
*/

typedef enum
{
  NoError,
  ErrorStartCondition,
  ErrorRestartCondition,
  ErrorSlaveAddressWriteWithAck,
  ErrorSlaveAddressWriteWithoutAck,
  ErrorSlaveAddressReadWithAck,
  ErrorSlaveAddressReadWithoutAck,
  ErrorWriteDataWithAck,
  ErrorWriteDataWithoutAck,
  ErrorReadDataWithAck,
  ErrorReadDataWithoutAck,
}I2C_Error_State;



// NTI

void I2C_Master_voidInit(void);                                        //init for master
void I2C_Slave_voidInit(u8 I2C_Address);                               //init fo slave
I2C_Error_State I2C_Master_enuSendStartCond(void);                          //start if bus is idle
I2C_Error_State I2C_Master_enuSendRepeatedStartCond(void);                  //repeated start if bus is busy
I2C_Error_State I2C_Master_enuSendSlaveAddressWithRead(u8 I2C_Address);     //Send slave address With R/W bit Read
I2C_Error_State I2C_Master_enuSendSlaveAddressWithWrite(u8 I2C_Address);    //Send slave address With R/W bit Write
I2C_Error_State I2C_Master_enuSendu8Data(u8 I2C_Data);                      //master Sets Data given in argument
I2C_Error_State I2C_Master_enuReadu8Data(u8* I2C_Data);                     //master Gets Data and saves it in given argument
I2C_Error_State I2C_Master_voidFlush();
void I2C_Master_enuSendStopCond(void);                                      //send stop bit
I2C_Error_State I2C_Slave_enuReadu8Data(u8* I2C_Data);                      //Slave Reads Data saves it in given argument



#endif

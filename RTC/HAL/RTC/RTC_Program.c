/*
 * RTC_Program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: AHMED
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"

#include "../../MCAL/I2C/I2C_Interface.h"

#include "RTC_Config.h"
#include "RTC_Interface.h"


extern Sec;
extern Min;
extern Hour;
extern Day;
extern Date;
extern Mon;
extern Year;

void RTC_Read_Calendar(void)
{
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(RTC_CALENDAR_ADDRESS);
	I2C_Master_enuSendRepeatedStartCond();
	I2C_Master_enuSendSlaveAddressWithRead(RTC_SLAVE_ADDRESS);

	I2C_Master_enuReadu8Data(&Day);
	I2C_Master_enuReadu8Data(&Date);
	I2C_Master_enuReadu8Data(&Mon);
	I2C_Master_enuReadu8Data(&Year);

	I2C_Master_voidFlush();
	I2C_Master_enuSendStopCond();

}

void RTC_Write_Calendar( u8 _date, u8 _day, u8 _mon, u8 _year  )
{
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(RTC_CALENDAR_ADDRESS);

	I2C_Master_enuSendu8Data(_day);
	I2C_Master_enuSendu8Data(_date);
	I2C_Master_enuSendu8Data(_mon);
	I2C_Master_enuSendu8Data(_year);

	I2C_Master_enuSendStopCond();

}

void RTC_Write_Clock( u8 _sec, u8 _min, u8 _hour)
{
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(RTC_CLOCK_ADDRESS);

	I2C_Master_enuSendu8Data(_sec);
	I2C_Master_enuSendu8Data(_min);
	I2C_Master_enuSendu8Data(_hour);

	I2C_Master_enuSendStopCond();

}

void RTC_Read_Time(void)
{
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(RTC_CLOCK_ADDRESS);
	I2C_Master_enuSendRepeatedStartCond();
	I2C_Master_enuSendSlaveAddressWithRead(RTC_SLAVE_ADDRESS);

	I2C_Master_enuReadu8Data(&Sec);
	I2C_Master_enuReadu8Data(&Min);
	I2C_Master_enuReadu8Data(&Hour);

	I2C_Master_voidFlush();
	I2C_Master_enuSendStopCond();

}


/*
 * main.c
 *
 *  Created on: Nov 3, 2023
 *      Author: AHMED
 */

#include "LIB/STD_TYPES.h"

#include "HAL/LCD2/LCD_Interface.h"
#include "HAL/RTC/RTC_Interface.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Port/Port_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"

#define INITIAL_HOUR	15
#define INITIAL_MIN		12
#define INITIAL_SEC		0
#define INITIAL_DATE	3
#define INITIAL_DAY		5
#define INITIAL_MON		11
#define INITIAL_YEAR	23

volatile u8 Sec = 0;
volatile u8 Min = 0;
volatile u8 Hour = 0;
volatile u8 Day = 0;
volatile u8 Date = 0;
volatile u8 Mon = 0;
volatile u8 Year = 0;


u8* days[7]= {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};


u8 Convert( u8 Num )
{
	u8 ones =Num % 10;
	u8 tens = (Num / 10) << 4;
	u8 value = tens | ones;

	return value;
}

int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	I2C_Master_voidInit();

	RTC_Write_Calendar(Convert(INITIAL_DATE),INITIAL_DAY,Convert(INITIAL_MON),Convert(INITIAL_YEAR));
	RTC_Write_Clock(Convert(INITIAL_SEC),Convert(INITIAL_MIN),Convert(INITIAL_HOUR));


	while(1)
	{
		RTC_Read_Time();

		Sec = (Sec >> 4) * 10 + (Sec & 0x0F);
		Min = (Min >> 4) * 10 + (Min & 0x0F);
		Hour = (Hour >> 4) * 10 + (Hour & 0x0F);

		LCD_voidGoToPosition(0,0);
		if(Hour < 10)
		{
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(Hour);
		LCD_voidWriteChar(':');
		if(Min < 10)
		{
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(Min);
		LCD_voidWriteChar(':');
		if(Sec < 10)
		{
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(Sec);

		RTC_Read_Calendar();

		Date = (Date >> 4) * 10 + (Date & 0x0F);
		Mon = (Mon >> 4) * 10 + (Mon & 0x0F);
		Year = (Year >> 4) * 10 + (Year & 0x0F);

		LCD_voidGoToPosition(1,0);
		LCD_voidWriteIntData(Date);
		LCD_voidWriteChar('/');
		LCD_voidWriteIntData(Mon);
		LCD_voidWriteChar('/');
		LCD_voidWriteIntData(Year);
		LCD_voidWriteChar(' ');
		LCD_voidWriteString(days[Day]);

	}

	return 0;
}

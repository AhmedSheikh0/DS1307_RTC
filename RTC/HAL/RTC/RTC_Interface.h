/*
 * RTC_Interface.h
 *
 *  Created on: Nov 3, 2023
 *      Author: AHMED
 */

#ifndef HAL_RTC_RTC_INTERFACE_H_
#define HAL_RTC_RTC_INTERFACE_H_

void RTC_Read_Calendar(void);
void RTC_Read_Time(void);

void RTC_Write_Calendar( u8 _date, u8 _day, u8 _mon, u8 _year);
void RTC_Write_Clock( u8 _sec, u8 _min, u8 _hour);




#endif /* HAL_RTC_RTC_INTERFACE_H_ */

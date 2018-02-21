/*
 * LCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asmaa
 */

#include<util/delay.h>
#include"Std_Types.h"
#include"Macros.h"
#include"DIO_interface.h"
#include"LCD_interface.h"

/*Lcd initialization */
void LCD_vidInit(void)
{
	/*set data pins as outputs*/
	Dio_vidSetPinDirection(LCD_DATA_PORT_D0,LCD_D0,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D1,LCD_D1,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D2,LCD_D2,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D3,LCD_D3,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D4,LCD_D4,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D5,LCD_D5,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D6,LCD_D6,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT_D7,LCD_D7,STD_HIGH);

	/*set control pins as outputs */
	Dio_vidSetPinDirection(LCD_CTRL_PORT_RS,LCD_RS,STD_HIGH);
	Dio_vidSetPinDirection(LCD_CTRL_PORT_RW,LCD_RW,STD_HIGH);
	Dio_vidSetPinDirection(LCD_CTRL_PORT_E,LCD_E,STD_HIGH);

	/*set mode (8-bit interface, 2-lines, 5x7 pixels)*/
	LCD_vidSendCommand(LCD_8MODE_2L);
	_delay_ms(2);      /*delay for command sending*/
	/*make cursor invisible*/
	LCD_vidSendCommand(LCD_ON_NOCURSOR);
	_delay_ms(2);
	/*clear screen*/
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	_delay_ms(2);
}

/*function takes command and load it on data bus*/
void LCD_vidSendCommand(u8 Command)
{
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_RS,STD_LOW);   /*set command mode (RS:0)*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RW,LCD_RW,STD_LOW);   /*set write mode (rw:0)*/

	/*output command on data pins*/
	Dio_vidSetPinValue(LCD_DATA_PORT_D0,LCD_D0,(GET_BIT(Command,PIN0)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D1,LCD_D1,(GET_BIT(Command,PIN1)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D2,LCD_D2,(GET_BIT(Command,PIN2)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D3,LCD_D3,(GET_BIT(Command,PIN3)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D4,LCD_D4,(GET_BIT(Command,PIN4)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D5,LCD_D5,(GET_BIT(Command,PIN5)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D6,LCD_D6,(GET_BIT(Command,PIN6)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D7,LCD_D7,(GET_BIT(Command,PIN7)));

	/*disable enable first and delay to make sure all data are sent parallel*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_E,STD_HIGH);
	_delay_ms(2);
	/*enable to recieve command and execute*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_E,STD_LOW);
}
/*function takes ASCI of character and display it */
void LCD_vidWriteChar(u8 Data)
{
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_RS,STD_HIGH);    /*set data mode (RS:1)*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_RW,STD_LOW);     /*set write mode (rw:0)*/

	/*output ASCI of character on data pins*/
	Dio_vidSetPinValue(LCD_DATA_PORT_D0,LCD_D0,(GET_BIT(Data,PIN0)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D1,LCD_D1,(GET_BIT(Data,PIN1)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D2,LCD_D2,(GET_BIT(Data,PIN2)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D3,LCD_D3,(GET_BIT(Data,PIN3)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D4,LCD_D4,(GET_BIT(Data,PIN4)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D5,LCD_D5,(GET_BIT(Data,PIN5)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D6,LCD_D6,(GET_BIT(Data,PIN6)));
	Dio_vidSetPinValue(LCD_DATA_PORT_D7,LCD_D7,(GET_BIT(Data,PIN7)));

	/*disable enable first and delay to make sure all data are sent parallel*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_E,STD_HIGH);
	_delay_ms(2);
	/*enable to recieve command and execute*/
	Dio_vidSetPinValue(LCD_CTRL_PORT_RS,LCD_E,STD_LOW);
}
/*function to display string */
void LCD_vidWriteString(u8 Array[])
{
	u8 i;
	i=0;
	while(Array[i]!='\0')       /*display char array until reaching the null terminator*/
	{
		LCD_vidWriteChar(Array[i]);
		i++;
	}
}
/*function to go to a certain position,takes index of row 1 or 2 and index of column (0:15)*/
void LCD_vidGoToXY(u8 u8Row,u8 u8Col)
{
	if(u8Row==1)                         /*in case of line 1*/
	{
		LCD_vidSendCommand(0x80+u8Col);  /*send address of line 1 + x position   address from data sheet*/
	}
	else if(u8Row==2)                    /*in case of line 2*/
	{
		LCD_vidSendCommand(0xC0+u8Col);  /*send address of line 2 + x position*/
	}
}


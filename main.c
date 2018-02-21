/*
 * main.c
 *  This is a code which:
 *  >>Test the keypad driver by receiving character through keypad
 *  >>then display it on LCD
 *  Created on: 9/2/2018
 *      Author: Asmaa
 */

#include<util/delay.h>
#include"Std_Types.h"
#include"Macros.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"KEYPAD_interface.h"

int main(void)
{
	u8 u8PressedKey;

	LCD_vidInit();
	KEYPAD_vidInit();

	u8PressedKey=0xFF;
	while(1)
	{
		do
		{
			u8PressedKey=KEYPAD_u8GetKey();
			_delay_ms(200);
			u8PressedKey=KEYPAD_u8GetKey();
		}
		while(u8PressedKey==0xFF);

		if((u8PressedKey>=0)&&(u8PressedKey<=9))
		{
			u8PressedKey+=0x30;
		}
		LCD_vidWriteChar(u8PressedKey);
	}
	return 0;
}

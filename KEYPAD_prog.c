/*
 * KEYPAD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asmaa
 */

/*includes*/
#include"Std_Types.h"
#include"Macros.h"
#include"DIO_interface.h"
#include"KEYPAD_interface.h"

/*keypad initialization*/
void KEYPAD_vidInit(void)
{
	/*set rows as outputs from microcontroller */
	Dio_vidSetPinDirection(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinDirection(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinDirection(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinDirection(ROW3_PORT,ROW3_PIN,STD_HIGH);

	/*set columns as inputs to uc and pull up resistor mode*/
	Dio_vidSetPinDirection(COL0_PORT,COL0_PIN,STD_LOW);
	Dio_vidSetPinDirection(COL1_PORT,COL1_PIN,STD_LOW);
	Dio_vidSetPinDirection(COL2_PORT,COL2_PIN,STD_LOW);
	Dio_vidSetPinDirection(COL3_PORT,COL3_PIN,STD_LOW);

	/*set mode of input culomns as pull up resistor mode*/
	Dio_vidSetPinValue(COL0_PORT,COL0_PIN,STD_HIGH);
	Dio_vidSetPinValue(COL1_PORT,COL1_PIN,STD_HIGH);
	Dio_vidSetPinValue(COL2_PORT,COL2_PIN,STD_HIGH);
	Dio_vidSetPinValue(COL3_PORT,COL3_PIN,STD_HIGH);
}

/*keypad get key from user*/
u8 KEYPAD_u8GetKey(void)
{
	u8 x;

	/*set 1st pattern on rows 1110  (row0 only is enabled */
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	/*store columns value in variable x in case of 1st pattern*/
	x=0;
	x|= (Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);   //put column0 value in pin0 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);   //put column1 value in pin1 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);   //put column2 value in pin2 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);   //put column3 value in pin3 of variable x by shifting and oring with x

	/*switch on columns pattern to return the right key*/
	switch(x)
	{
	case 0x07:           //case xxxxc3c2c1c0=0000 0111
		return '/';
	case 0x0B:           //case xxxxc3c2c1c0=0000 1011
		return 3;
	case 0x0D:           //case xxxxc3c2c1c0=0000 1101
		return 2;
	case 0x0E:           //case xxxxc3c2c1c0=0000 1110
		return 1;
	}
	///////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////

	/*set 2nd pattern on rows 1101  (row1 only is enabled */
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	/*store columns value in variable x in case of 2nd pattern*/
	x=0;
	x|= (Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);   //put column0 value in pin0 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);   //put column1 value in pin1 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);   //put column2 value in pin2 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);   //put column3 value in pin3 of variable x by shifting and oring with x

	/*switch on columns pattern to return the right key*/
	switch(x)
	{
	case 0x07:           //case xxxxc3c2c1c0=0000 0111
		return '*';
	case 0x0B:           //case xxxxc3c2c1c0=0000 1011
		return 6;
	case 0x0D:           //case xxxxc3c2c1c0=0000 1101
		return 5;
	case 0x0E:           //case xxxxc3c2c1c0=0000 1110
		return 4;
	}
    ////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

	/*set 3rd pattern on rows 1011  (row2 only is enabled */
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	/*store columns value in variable x in case of 3rd pattern*/
	x=0;
	x|= (Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);   //put column0 value in pin0 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);   //put column1 value in pin1 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);   //put column2 value in pin2 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);   //put column3 value in pin3 of variable x by shifting and oring with x

	/*switch on columns pattern to return the right key*/
	switch(x)
	{
	case 0x07:           //case xxxxc3c2c1c0=0000 0111
		return '+';
	case 0x0B:           //case xxxxc3c2c1c0=0000 1011
		return 9;
	case 0x0D:           //case xxxxc3c2c1c0=0000 1101
		return 8;
	case 0x0E:           //case xxxxc3c2c1c0=0000 1110
		return 7;
	}
	///////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////

	/*set 4th pattern on rows 0111  (row3 only is enabled */
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_LOW);

	/*store columns value in variable x in case of 4th pattern*/
	x=0;
	x|= (Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);   //put column0 value in pin0 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);   //put column1 value in pin1 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);   //put column2 value in pin2 of variable x by shifting and oring with x
	x|= (Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);   //put column3 value in pin3 of variable x by shifting and oring with x

	/*switch on columns pattern to return the right key*/
	switch(x)
	{
	case 0x07:           //case xxxxc3c2c1c0=0000 0111
		return '-';
	case 0x0B:           //case xxxxc3c2c1c0=0000 1011
		return '=';
	case 0x0D:           //case xxxxc3c2c1c0=0000 1101
		return 0;
	case 0x0E:           //case xxxxc3c2c1c0=0000 1110
		return '#';
	}

    return DEFAULT_VALUE;      /*return non pressed value*/
}

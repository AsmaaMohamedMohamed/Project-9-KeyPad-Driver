/*
 * LCD_interface.h
 *
 *  Created on: 2/2/2018
 *      Author: Asmaa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Vss>> gnd
 * Vdd>> 5v
 * Vo>>  Potentiometer
 * A>>   5v
 * K>>   gnd
 */
/*Data ports definition*/
#define LCD_DATA_PORT_D0 DIO_PORTD
#define LCD_DATA_PORT_D1 DIO_PORTD
#define LCD_DATA_PORT_D2 DIO_PORTD
#define LCD_DATA_PORT_D3 DIO_PORTD
#define LCD_DATA_PORT_D4 DIO_PORTD
#define LCD_DATA_PORT_D5 DIO_PORTD
#define LCD_DATA_PORT_D6 DIO_PORTD
#define LCD_DATA_PORT_D7 DIO_PORTD

/*Control ports definition*/
#define LCD_CTRL_PORT_RS DIO_PORTA
#define LCD_CTRL_PORT_RW DIO_PORTA
#define LCD_CTRL_PORT_E  DIO_PORTA

/*Data pins definition*/
#define LCD_D0 PIN0
#define LCD_D1 PIN1
#define LCD_D2 PIN2
#define LCD_D3 PIN3
#define LCD_D4 PIN4
#define LCD_D5 PIN5
#define LCD_D6 PIN6
#define LCD_D7 PIN7

/*control pins definition*/
#define LCD_RS PIN0        /*register select pin (0:command , 1:Data)*/
#define LCD_RW PIN1        /*Read write pin (0:write, 1:read)*/
#define LCD_E PIN2         /*Enable pin to start recieving data(1:disable, 0:enable)*/

/*required commands definition*/
#define LCD_8MODE_2L 0x38       /*Function set (8-bit interface, 2-lines, 5x7 pixels)*/
#define LCD_ON_NOCURSOR 0x0C    /*make cursor invisible*/
#define LCD_CLEAR_SCREEN 0x01   /*clear screen */

#define LCD_LINE1 1             /*first line on lcd*/
#define LCD_LINE2 2             /*second line on lcd*/

/*Lcd initialization */
void LCD_vidInit(void);
/*function takes command and load it on data bus*/
void LCD_vidSendCommand(u8 Command);
/*function takes ASCI of character and display it */
void LCD_vidWriteChar(u8 Data);
/*function to display string */
void LCD_vidWriteString(u8 Array[40]);
/*function to go to a certain position,takes index of row 1 or 2 and index of column (0:15)*/
void LCD_vidGoToXY(u8 u8Row,u8 u8Col);

#endif /* LCD_INTERFACE_H_ */

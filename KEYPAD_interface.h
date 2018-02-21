/*
 * KEYPAD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asmaa
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*rows ports definition*/
#define ROW0_PORT DIO_PORTC
#define ROW1_PORT DIO_PORTC
#define ROW2_PORT DIO_PORTC
#define ROW3_PORT DIO_PORTC

/*columns ports definition */
#define COL0_PORT DIO_PORTC
#define COL1_PORT DIO_PORTC
#define COL2_PORT DIO_PORTC
#define COL3_PORT DIO_PORTC

/*rows pins definition */
#define ROW0_PIN PIN0
#define ROW1_PIN PIN1
#define ROW2_PIN PIN2
#define ROW3_PIN PIN3

/*columns pins definition */
#define COL0_PIN PIN4
#define COL1_PIN PIN5
#define COL2_PIN PIN6
#define COL3_PIN PIN7

/*define non pressed return value*/
#define DEFAULT_VALUE 0xFF

/*functions definition*/

/*keypad initialization*/
void KEYPAD_vidInit(void);

/*keypad get key from user*/
u8 KEYPAD_u8GetKey(void);

#endif /* KEYPAD_INTERFACE_H_ */

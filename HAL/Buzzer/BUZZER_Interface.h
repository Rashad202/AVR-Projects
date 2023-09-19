/*
 *   			--- BUZZER_Interface.h----
 *
 *  Author : Rashad
 *  Layer  : HAL
 *  SWC    : BUZZER
 *
 */
#ifndef BUZZER_INT_H_
#define BUZZER_INT_H_

// Port Defines
#define  BUZZER_PORTA  0
#define  BUZZER_PORTB  1
#define  BUZZER_PORTC  2
#define  BUZZER_PORTD  3


// PIN Defines
#define BUZZER_PIN0   0
#define BUZZER_PIN1   1
#define BUZZER_PIN2   2
#define BUZZER_PIN3   3
#define BUZZER_PIN4   4
#define BUZZER_PIN5   5
#define BUZZER_PIN6   6
#define BUZZER_PIN7   7



/**
* Direction of BUZZER
*/
#define BUZZER_OUTPUT 1

#define BUZZER_HIGH	  1

#define BUZZER_LOW	  0


void BUZZER_voidBUZZERInit (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber) ;


void BUZZER_voidBUZZEROn (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber) ;


void BUZZER_voidBUZZEROff (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber) ;


void HUZZER_voidBUZZERToggle (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber) ;

#endif /* BUZZER_INT_H_ */

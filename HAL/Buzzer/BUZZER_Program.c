/*
 *   			--- BUZZER_Program.c----
 *
 *  Author : Rashad
 *  Layer  : HAL
 *  SWC    : BUZZER
 *
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUZZER_Interface.h"


void BUZZER_voidBUZZERInit (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber)
{
	/** select direction of buzzer as output */
    DIO_voidSetPinDirection(Copy_u8PortNumber , Copy_u8PinNumber , BUZZER_OUTPUT) ;
}


void BUZZER_voidBUZZEROn (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber)
{
	/**make buzzer on (it's pin is high)*/
	DIO_voidSetPinValue(Copy_u8PortNumber , Copy_u8PinNumber,BUZZER_HIGH) ;
}

void BUZZER_voidBUZZEROff (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber)
{
	/**make buzzer off (it's pin is low)*/
	DIO_voidSetPinValue(Copy_u8PortNumber , Copy_u8PinNumber,BUZZER_LOW) ;
}

void BUZZER_voidBUZZERToggle  (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber)
{
	/**inverse the status of buzzer*/
	DIO_voidTogglePinValue(Copy_u8PortNumber , Copy_u8PinNumber) ;
}

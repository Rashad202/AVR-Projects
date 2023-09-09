#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

#include "DIO_Interface.h"


void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,OUTPUT);
    }
}

void LED_voidInit_8Leds_Port ( u8 Copy_u8PortNumber)
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidSetPortDirection ( Copy_u8PortNumber, OUTPUT );
    }
}


void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Status)
        {
            case ON  :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, HIGH );     break;
            case OFF :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, LOW  );     break;
            default  :                                                                          break;
        }
    }
}



void LED_voidStatus_8Leds_Port ( u8 Copy_u8PortNumber, u8 Copy_u8Status )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Status)
        {
            case ON  :   DIO_voidSetPortValue ( Copy_u8PortNumber, HIGH );     break;
            case OFF :   DIO_voidSetPortValue ( Copy_u8PortNumber, LOW  );     break;
            default  :                                                         break;
        }
    }
}




void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidTogglePinValue ( Copy_u8PortNumber, Copy_u8PinNumber );
    }
}


void LED_voidToggle_8Leds_Port ( u8 Copy_u8PortNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidTogglePortValue ( Copy_u8PortNumber );
    }
}

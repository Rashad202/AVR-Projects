
/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "BUTTON_Interface.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"


void BUTTON_voidInit_Button_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD  || Copy_u8PinNumber > DIO_PIN7 )
    {
        // Do Nothing
    }
    else
    {   // Set Direction INPUT to Copy_u8PinNumber
        DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,DIO_INPUT);
        // activate Pull Up Resistor on Copy_u8PinNumber
        DIO_voidConfig_Pull_Up_Pin (Copy_u8PortNumber,Copy_u8PinNumber, Copy_u8PullUpStatus );
    }
}

void BUTTON_voidInit_8Buttons_Port ( u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else
    {   // Set Direction INPUT to Copy_u8PortNumber
        DIO_voidSetPortDirection (Copy_u8PortNumber, DIO_INPUT );
        // activate Pull Up Resistor on Copy_u8PortNumber
        DIO_voidConfig_Pull_Up_Port (Copy_u8PortNumber, Copy_u8PullUpStatus );
    }
}

u8 BUTTON_u8Get_Button_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    u8 Local_u8Value  ;
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD || Copy_u8PinNumber > DIO_PIN7 )
    {
        // Do Nothing
    }
    else
    {   
        Local_u8Value = DIO_u8GetPinValue ( Copy_u8PortNumber,  Copy_u8PinNumber ) ;
    }
    return Local_u8Value ;
}


u8 BUTTON_u8Get_8Buttons_Port (u8 Copy_u8PortNumber)
{   
    u8 Local_u8Value  ;
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else
    {   
        Local_u8Value = DIO_u8GetPortValue ( Copy_u8PortNumber ) ;   
    }
    return Local_u8Value ;
}


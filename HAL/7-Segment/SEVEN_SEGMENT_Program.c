#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"

/* Include My own Header Files*/
#include "SEVEN_SEGMENT_Interface.h"
#include "SEVEN_SEGMENT_Private.h"
#include "SEVEN_SEGMENT_Config.h"

u8 Common_Anode_Arr[10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SEX,SEVEN,EIGHT,NINE} ;




void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber )
{
    switch(Copy_u8PortNumber)
    {
        case PORTA :   DIO_voidSetPortDirection (PORTA,OUTPUT);    break;
        case PORTB :   DIO_voidSetPortDirection (PORTB,OUTPUT);    break;
        case PORTC :   DIO_voidSetPortDirection (PORTC,OUTPUT);    break;
        case PORTD :   DIO_voidSetPortDirection (PORTD,OUTPUT);    break;
        default    :                                               break;
    }
}



void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number )
{
    switch ( Copy_SegmentPolarity )
    {
        case COMMON_ANODE   :   switch(Copy_u8PortNumber)
                                {
                                    case PORTA :   DIO_voidSetPortValue (PORTA,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTB :   DIO_voidSetPortValue (PORTB,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTC :   DIO_voidSetPortValue (PORTC,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTD :   DIO_voidSetPortValue (PORTD,Common_Anode_Arr[Copy_u8Number]);    break;
                                    default    :                                                                    break;
                                }
                                break;
        case COMMON_CATHODE :   switch(Copy_u8PortNumber)
                                {
                                    case PORTA :   DIO_voidSetPortValue (PORTA,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTB :   DIO_voidSetPortValue (PORTB,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTC :   DIO_voidSetPortValue (PORTC,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTD :   DIO_voidSetPortValue (PORTD,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    default    :                                                                    break;
                                }   
                                break;
        default             :   break;
    }
    
}






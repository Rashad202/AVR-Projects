#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"

/* Include My own Header Files*/
#include "SEVEN_SEGMENT_Interface.h"
#include "SEVEN_SEGMENT_Private.h"


u8 Common_Anode_Arr[10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SEX,SEVEN,EIGHT,NINE} ;




void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber )
{
    switch(Copy_u8PortNumber)
    {
        case DIO_PORTA :   DIO_voidSetPortDirection (DIO_PORTA,DIO_OUTPUT);    break;
        case DIO_PORTB :   DIO_voidSetPortDirection (DIO_PORTB,DIO_OUTPUT);    break;
        case DIO_PORTC :   DIO_voidSetPortDirection (DIO_PORTC,DIO_OUTPUT);    break;
        case DIO_PORTD :   DIO_voidSetPortDirection (DIO_PORTD,DIO_OUTPUT);    break;
        default    :                                               break;
    }
}



void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number )
{
    switch ( Copy_SegmentPolarity )
    {
        case COMMON_ANODE   :
        						switch(Copy_u8PortNumber)
                                {
                                    case DIO_PORTA :
                                    	DIO_voidSetPortValue (DIO_PORTA,Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTB :
                                    	DIO_voidSetPortValue (DIO_PORTB,Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTC :
                                    	DIO_voidSetPortValue (DIO_PORTC,Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTD :
                                    	DIO_voidSetPortValue (DIO_PORTD,Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    default    :
                                    	break;
                                }
                                break;
        case COMMON_CATHODE :   switch(Copy_u8PortNumber)
                                {
                                    case DIO_PORTA :
                                    	DIO_voidSetPortValue (DIO_PORTA,~Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTB :
                                    	DIO_voidSetPortValue (DIO_PORTB,~Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTC :
                                    	DIO_voidSetPortValue (DIO_PORTC,~Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    case DIO_PORTD :
                                    	DIO_voidSetPortValue (DIO_PORTD,~Common_Anode_Arr[Copy_u8Number]);
                                    	break;
                                    default    :                                                                    break;
                                }   
                                break;
        default             :
        	break;
    }
    
}






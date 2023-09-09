#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "SERVO_Interface.h"
#include "SERVO_Private.h"
#include "SERVO_Config.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMER1/TIMER1_Interface.h"


void SERVO_voidRotateSpecificAngle_OC1A ( u16 Copy_u16Angle )
{
    DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
    u32 Local_u32Variable ;
    Local_u32Variable = ((Copy_u16Angle*1000UL)+179820) / (180) ;
    TIMER1_voidBahaa_u16PWM_T1A ( Local_u32Variable ,19999);
}



void SERVO_voidRotateSpecificAngle_OC1B ( u16 Copy_u16Angle )
{
    DIO_voidSetPinDirection(PORTD,PIN4,OUTPUT);
    u32 Local_u32Variable ;
    Local_u32Variable = ((Copy_u16Angle*1000UL)+179820) / (180) ;
    TIMER1_voidBahaa_u16PWM_T1B ( Local_u32Variable ,19999);
}
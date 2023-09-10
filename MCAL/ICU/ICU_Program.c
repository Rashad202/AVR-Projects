#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "ICU_Interface.h"
#include "ICU_Private.h"
#include "ICU_Config.h"

/* Include Header Files From MCAL */
#include"../DIO/DIO_Interface.h"
#include"../TIMERS/TIMER1/TIMER1_Interface.h"
#include"../TIMERS/TIMER1/TIMER1_Private.h"
#include"../TIMERS/TIMER1/TIMER1_Config.h"
/* Global Pointer to Function */
void (*GlobalPF_vector_6) ( void ) = NULL ;

void ICU_voidInit (void)
{
    TIMER1_voidInit();


/*  TIMER1 Normal Mode Selection to use ICU to Calculate PWM Frequency */

        /*       TIMER1 Normal Mode      */                             
        CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG,TCCR1B_WGM12);
        CLR_BIT(TCCR1B_REG,TCCR1B_WGM13);


/*                     TIMER1 Prescaller Selection                     */

    TCCR1B_REG = ( TCCR1B_REG & 0b11111000 );              // Clear Prescaller 

    #if( PRESCALER == NO_CLK_SOURCE_TIMER_STOPED )          
        CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == NOT_USE_PRESCALER )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_8 )
        CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_64 )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_256 )
        CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_1024 )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLR_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_FALLING_EDGE )
        CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_RAISING_EDGE )
        SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #else
        #error  Wrong selection of Prescaller mode
    #endif

    ICU_voidEdgeSelect ( RAISING_EDGE );        // Sense Raising Edge to start calculate time of Period Time from First Raising Ege to Second Raising Edge.

    SET_BIT(TIMSK_REG,TIMER_TIMSK_TICIE);              // Enable PIE of ICU    
}


void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK_REG,TIMER_TIMSK_TICIE);
}

void ICU_voidEdgeSelect ( u8 Copy_u8EdgeSelect )
{
    switch ( Copy_u8EdgeSelect )
    {
        case FALLING_EDGE :  CLR_BIT(TCCR1B_REG,TCCR1B_ICES1);       break;
        case RAISING_EDGE :    SET_BIT(TCCR1B_REG,TCCR1B_ICES1);       break;
        default           :         break;
    }
}



u16 ICU_u16GetReadICR1 (void)
{
	return ICR1_REG ;
}



void ICU_SetCallBackFun ( void (*LocalPF_vector_6) (void) )
{
	GlobalPF_vector_6 = LocalPF_vector_6 ;
}


/*  ISR (ICU)  */
void __vector_6 (void)    __attribute__((signal));
void __vector_6 (void)
{
	if (GlobalPF_vector_6 != NULL )
	{
		GlobalPF_vector_6();
	}
}

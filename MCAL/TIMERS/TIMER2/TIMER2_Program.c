/*
 *<<<<<<<<<<<    TIMER_program.c   >>>>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : Timer
 *
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
/* Include My own Header Files*/
#include "TIMER2_Config.h"
#include "TIMER2_Interface.h"
#include "TIMER2_Private.h"

void (*Global_PointerToFunction_OVF_T2) (void) = NULL ;
void (*Global_PointerToFunction_CTC_T2) (void) = NULL ;
u16 Global_u8PreloadValue = 0 ;
u16 Global_u8CompareMatchValue = 0 ;
u32 Global_u32Time_ms = 0 ;


void TIMER2_voidInit (void)
{

/*         TIMER2 Mode Selection        */
    #if (MODE == NORMAL_OVF)                             // OVF Normal Mode of Timer/Counter0
        CLR_BIT(TCCR2_REG,TIMER2_TCCR0_WGM20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR0_WGM21);
		SET_BIT(TIMSK_REG,TIMER2_TIMSK_TOIE2);          // Enable T0 OVF Interrupt [PIE].

    #elif (MODE == PWM_PHASECORRECT)                     // PWM_Phase Correct Mode of Timer/Counter0
        SET_BIT(TCCR2_REG,TIMER2_TCCR0_WGM20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR0_WGM21);
        
        /*          OC2 Mode Selection          */
        #if ( OC2_MODE == DISCONNECTED )
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #elif ( OC2_MODE == SETonCOMPdownCounting_CLEARonCOMPupCounting )
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #elif ( OC2_MODE == SETonCOMPupCounting_CLEARonCOMPdownCounting )
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #else 
            #error  Wrong selection of OC2 mode
        #endif

    #elif (MODE == CTC)                                  // CTC Mode of Timer/Counter0
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_WGM20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_WGM21);
		SET_BIT(TIMSK_REG,TIMER2_TIMSK_OCIE2);          // Enable T0 CTC Interrupt [PIE].

    #elif (MODE == FAST_PWM)                             // Fast-PWM Mode of Timer/Counter0
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_WGM20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_WGM21);

        /*          OC2 Mode Selection          */
        #if ( OC2_MODE == DISCONNECTED )
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #elif ( OC2_MODE == SETonTOP_CLEARonCOMPARE )
            CLR_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #elif ( OC2_MODE == SETonCOMPARE_CLEARonTOP )
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM20);
            SET_BIT(TCCR2_REG,TIMER2_TCCR2_COM21);
        #else 
            #error  Wrong selection of OC2 mode
        #endif

    #else 
        #error  Wrong selection of operation mode
    #endif 


/*     TIMER2 Prescaller Selection      */
    TCCR2_REG = ( TCCR2_REG & 0b11111000 );              // Clear Prescaller

    #if( PRESCALER == NO_CLK_SOURCE_TIMER_STOPED )          
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == NOT_USE_PRESCALER )
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_8 )
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_32 )
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_64 )
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_128 )
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_256 )
        CLR_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_1024 )
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS20);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS21);
        SET_BIT(TCCR2_REG,TIMER2_TCCR2_CS22);
    #else
        #error  Wrong selection of Prescaller mode
    #endif

}


void TIMER2_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void))
{
    Global_PointerToFunction_OVF_T2 = Local_PointerToFunction_OVF ;
}


void TIMER2_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void))
{
    Global_PointerToFunction_CTC_T2 = Local_PointerToFunction_CTC ;
}

void TIMER2_voidSetPreloadValue ( u8 Local_u8PreloadValue )
{
    #if (MODE == NORMAL_OVF)
        TCNT0_REG = Local_u8PreloadValue ;
        Global_u8PreloadValue = Local_u8PreloadValue ;
    #else
        // No Action
    #endif
}


void TIMER2_voidSetCompareMatchValue ( u8 Local_u8CompareMatchValue )
{
    #if (MODE == CTC)
        OCR2_REG = Local_u8CompareMatchValue ;
        Global_u8CompareMatchValue = Local_u8CompareMatchValue ;
    #elif ( MODE == FAST_PWM )
        OCR2_REG = Local_u8CompareMatchValue ;
    #elif (MODE == PWM_PHASECORRECT)
        OCR2_REG = Local_u8CompareMatchValue ;
    #endif
}

void TIMER2_voidSetCallBack_CTC_andRequiredTime_ms (void (*Local_PointerToFunction_CTC) (void),u32 Copy_u32Time_ms)
{
    TIMER2_voidSetCompareMatchValue (200);
    TIMER2_voidSetCallBack_CTC (Local_PointerToFunction_CTC);
    Global_u32Time_ms = Copy_u32Time_ms ;
}



void TIMER2_voidPWM ( u8 Local_u8CompareMatchValue )
{
    TIMER2_voidSetCompareMatchValue ( Local_u8CompareMatchValue );
}
/*  // For Loop to Increase PWM and Decrease PWM used in APPLICATION.
    for ( u16 Counter=0 ; Counter <= 255 ; Counter++ )
    {
        TIMER2_voidPWM (Counter);
        _delay_ms(10);
    }
    for ( u16 Counter=0 ; Counter <= 255 ; Counter++ )
    {
        TIMER2_voidPWM (255-Counter);
        _delay_ms(10);
    }
*/



/**************     [ISR] to OVF     *************/
void __vector_5 (void)   __attribute__((signal));
void __vector_5 (void)
{
    static u16 counter = 0 ;
    counter ++ ;
    if ( counter == 3907 )
    {
        if(Global_PointerToFunction_OVF_T2 != NULL)
		{
    		Global_PointerToFunction_OVF_T2();                 // Action of OVF Application Function
		}
        counter = 0 ;                                       // For Next Period.
        TCNT2_REG = Global_u8PreloadValue ;                 // For Next Period Preload Value.
    }
}

/**************     [ISR] to CTC     *************/
void __vector_4 (void)   __attribute__((signal));
void __vector_4 (void)
{
    static u16 counter = 0 ;
    counter ++ ;

        if ( counter == 5000 )
        {
            if(Global_PointerToFunction_CTC_T2 != NULL)
		    {
                Global_PointerToFunction_CTC_T2();                  // Action of CTC Application Function
		    }                
            counter = 0 ;                                        // For Next Period.
            OCR2_REG = Global_u8CompareMatchValue ;              // For Next Period Compare Match Value.
        }

}

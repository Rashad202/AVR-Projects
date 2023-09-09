#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/* Global Pointer to Function */
void (*Global_PF_Vector_1)(void) = NULL ;
void (*Global_PF_Vector_2)(void) = NULL ;
void (*Global_PF_Vector_3)(void) = NULL ;



void EXTI_voidEnable ( u8 Copy_u8INTnumber , u8 Copy_u8SenseControl )
{
    switch ( Copy_u8INTnumber )
    {
        case INT0 :     // Set 1 On PIN6 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT0 .
                         SET_BIT(GICR_REG,PIN6);            
                        switch ( Copy_u8SenseControl )
                        {                                                                                                   // BIT1  -  BIT0  on MCUCR_REG
                            case FALLING_EDGE :     SET_BIT(MCUCR_REG,PIN1);      CLEAR_BIT(MCUCR_REG,PIN0);      break;    //   1   -   0   Falling Edge
                            case RAISING_EDGE :     SET_BIT(MCUCR_REG,PIN1);      SET_BIT(MCUCR_REG,PIN0);        break;    //   1   -   1   Raising Edge  
                            case LOW_LEVEL    :     CLEAR_BIT(MCUCR_REG,PIN1);    CLEAR_BIT(MCUCR_REG,PIN0);      break;    //   0   -   0   Low Level  
                            case ON_CHANGE    :     CLEAR_BIT(MCUCR_REG,PIN1);    SET_BIT(MCUCR_REG,PIN0);        break;    //   0   -   1   On Change   
                            default           :                                                                   break;
                        }
                        break;
        case INT1 :     // Set 1 On PIN7 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT1 .
                        SET_BIT(GICR_REG,PIN7);             
                        switch ( Copy_u8SenseControl )
                        {                                                                                                   // BIT3  -  BIT2  on MCUCR_REG
                            case FALLING_EDGE :     SET_BIT(MCUCR_REG,PIN3);      CLEAR_BIT(MCUCR_REG,PIN2);      break;    //   1   -   0   Falling Edge
                            case RAISING_EDGE :     SET_BIT(MCUCR_REG,PIN3);      SET_BIT(MCUCR_REG,PIN2);        break;    //   1   -   1   Raising Edge
                            case LOW_LEVEL    :     CLEAR_BIT(MCUCR_REG,PIN3);    CLEAR_BIT(MCUCR_REG,PIN2);      break;    //   0   -   0   Low Level
                            case ON_CHANGE    :     CLEAR_BIT(MCUCR_REG,PIN3);    SET_BIT(MCUCR_REG,PIN2);        break;    //   0   -   1   On Change 
                            default           :                                                                   break;  
                        }
                        break;
        case INT2 :      // Set 1 On PIN5 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT2 .
                        SET_BIT(GICR_REG,PIN5);            
                        switch ( Copy_u8SenseControl )
                        {                                                                      //  BIT6  on  MCUCSR_REG
                            case FALLING_EDGE :     CLEAR_BIT(MCUCSR_REG,PIN6);      break;    //   0    Falling Edge   
                            case RAISING_EDGE :     SET_BIT(MCUCSR_REG,PIN6);        break;    //   1    Raising Edge
                            default           :                                      break;  
                        } 
                        break;
        default   :     break;
    }
}


void EXTI_voidDisable ( u8 Copy_u8INTnumber )
{
    switch ( Copy_u8INTnumber )
    {
        case INT0 :     CLEAR_BIT(GICR_REG,PIN6);   break;    // Set 0 On PIN6 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT0 .
        case INT1 :     CLEAR_BIT(GICR_REG,PIN7);   break;    // Set 0 On PIN7 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT1 .
        case INT2 :     CLEAR_BIT(GICR_REG,PIN5);   break;    // Set 0 On PIN5 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT2 .
        default   :                                 break;
    }
}

void EXTI_voidSetCallBack ( u8 Copy_u8INTnumber , void (*Local_PointerToFunction) (void) )
{
    switch( Copy_u8INTnumber )
    {
        case INT0 :     Global_PF_Vector_1 = Local_PointerToFunction ;     break;
        case INT1 :     Global_PF_Vector_2 = Local_PointerToFunction ;     break; 
        case INT2 :     Global_PF_Vector_3 = Local_PointerToFunction ;     break; 
        default   :                                                        break; 
    } 
}


void __vector_1 (void)   __attribute__((signal));
void __vector_1 (void)
{
    if ( Global_PF_Vector_1 != NULL )
    {
        Global_PF_Vector_1 ();  // calling Global pointer to function that contain address of Application Function with INT0. 
    }

}

void __vector_2 (void)   __attribute__((signal));
void __vector_2 (void) 
{
    if ( Global_PF_Vector_2 != NULL )
    {
        Global_PF_Vector_2 ();  // calling Global pointer to function that contain address of Application Function with INT1. 
    }
    
}

void __vector_3 (void)   __attribute__((signal));
void __vector_3 (void) 
{
    if ( Global_PF_Vector_3 != NULL )
    {
        Global_PF_Vector_3 ();  // calling Global pointer to function that contain address of Application Function with INT2.
    }
}
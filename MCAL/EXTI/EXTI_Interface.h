#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Macros as INT options */
#define  INT0             0
#define  INT1             1
#define  INT2             2

/* Macros as Sense Control options */
#define  FALLING_EDGE                 0
#define  RAISING_EDGE                 1
#define  LOW_LEVEL                    2
#define  ON_CHANGE                    3


void EXTI_voidEnable ( u8 Copy_u8INTnumber , u8 Copy_u8SenseControl );

void EXTI_voidDisable ( u8 Copy_u8INTnumber );

void EXTI_voidSetCallBack ( u8 Copy_u8INTnumber , void (*Local_PointerToFunction) (void) );





#endif
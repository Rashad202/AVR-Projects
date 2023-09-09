#ifndef ICU_INTERFACE_H
#define ICU_INTERFACE_H


void ICU_voidInit (void);


u16 ICU_u16GetReadICR1 (void);


void ICU_voidDisableInterrupt(void);


void ICU_voidEdgeSelect ( u8 Copy_u8EdgeSelect );


void ICU_SetCallBackFun ( void (*LocalPF_vector_6) (void));


/*  (ICES1) Input Capture Edge Select { Falling Edge , Raising Edge }  */

#define     FALLING_EDGE                        0
#define     RAISING_EDGE                        1

#endif
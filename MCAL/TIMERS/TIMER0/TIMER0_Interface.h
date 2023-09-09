#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H


void TIMER0_voidInit (void);


void TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void));


void TIMER0_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void));


void TIMER0_voidSetPreloadValue ( u8 Copy_u8PreloadValue );


void TIMER0_voidSetCompareMatchValue ( u8 Copy_u8CompareMatchValue );


void TIMER0_voidSetBusyWait_ms ( u32 Copy_u32Time_ms );


void TIMER0_voidPWM ( u8 Local_u8CompareMatchValue );


void TIMER0_voidSetCallBack_CTC_andRequiredTime_ms (void (*Local_PointerToFunction_CTC) (void),u32 Copy_u32Time_ms);


#endif
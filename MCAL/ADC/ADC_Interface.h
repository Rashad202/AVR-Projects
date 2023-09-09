/*
 *<<<<<<<<<<    ADC_Interface.h    >>>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*     Macros of Channel Number    */
#define     ADC0                    0
#define     ADC1                    1
#define     ADC2                    2
#define     ADC3                    3
#define     ADC4                    4
#define     ADC5                    5
#define     ADC6                    6
#define     ADC7                    7




void ADC_voidInit (void);

u16 ADC_u16ReadSynchronus ( u8 Copy_u8ChannelNumber ) ;

u16 ADC_u16ReadASynchronus ( u8 Copy_u8ChannelNumber ,  void (*Local_PointerToFunction) (void) ) ;

#endif
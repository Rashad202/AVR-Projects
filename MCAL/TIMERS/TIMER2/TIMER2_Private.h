/*
 *<<<<<<<<<<<    TIMER_Private.h   >>>>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : Timer
 *
 */
#ifndef TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H


/********      [TIMER2] Registers       *********/
#define     TCCR2_REG        *((volatile u8*)0x45)     // Timer/Counter Control Register
#define     TCNT2_REG        *((volatile u8*)0x44)     // Timer/Counter Register
#define     OCR2_REG         *((volatile u8*)0x43)     // Output Compare Register
#define     TIMSK_REG        *((volatile u8*)0x59)     // Timer/Counter Interrupt Mask Register
#define     TIFR_REG         *((volatile u8*)0x58)     // Timer/Counter Interrupt Flag Register
#define     SFIOR_REG        *((volatile u8*)0x50)     // Special Function IO Register

/********   TIMER2 [TCCR0] BITS   *******/
#define     TIMER2_TCCR2_CS20          0              // TIMER2 Prescaller Clock Select BIT 0
#define     TIMER2_TCCR2_CS21          1              // TIMER2 Prescaller Clock Select BIT 1
#define     TIMER2_TCCR2_CS22          2              // TIMER2 Prescaller Clock Select BIT 2
#define     TIMER2_TCCR2_WGM21         3              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER2_TCCR2_COM20         4              // Compare Match Output Mode BIT 0 (OC0) behavior
#define     TIMER2_TCCR2_COM21         5              // Compare Match Output Mode BIT 1 (OC0) behavior
#define     TIMER2_TCCR2_WGM20         6              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER2_TCCR2_FOC2          7              // Force Output Compare


/********   TIMER2 [TIMSK] BITS   *******/
#define     TIMER2_TIMSK_TOIE2         6              // Timer/Counter0 OVF Interrupt Enable BIT 0
#define     TIMER2_TIMSK_OCIE2         7              // Timer/Counter0 CTC Interrupt Enable BIT 1

  
/********   TIMER2 [TIFR] BITS    *******/
#define      TIMER2_TIFR_TOV2          6              // Timer/Counter0 OVF Flag
#define      TIMER2_TIFR_OCF2          17              // Timer/Counter0 CTC Flag


/********   TIMER2 [SFIOR] BITS   *******/
#define      TIMER2_SFIOR_PSR2        1              // Prescaler Reset TIMER2 and TIMER1


#define     NULL                   (void*)(0)


#endif

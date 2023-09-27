/*
 *<<<<<<<<<<<    TIMER_Config.h   >>>>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : Timer
 *
 */
#ifndef TIMER2_CONFIG_H
#define TIMER2_CONFIG_H


/*
 *               TIMER2 Mode Selection

     NORMAL_OVF
     PWM_PHASECORRECT
     CTC
     FAST_PWM
 */

#define     MODE                     CTC


/*
 *                OC2 Mode Selection

     DISCONNECTED
     SETonTOP_CLEARonCOMPARE
     SETonCOMPARE_CLEARonTOP
     SETonCOMPdownCounting_CLEARonCOMPupCounting
     SETonCOMPupCounting_CLEARonCOMPdownCounting
*/
#define     OC0_MODE      SETonTOP_CLEARonCOMPARE


/*
 *          TIMER2 Prescaller Selection

     NO_CLK_SOURCE_TIMER_STOPED
     NOT_USE_PRESCALER
     PRESCALER_DIVISION_BY_8
     PRESCALER_DIVISION_BY_32
     PRESCALER_DIVISION_BY_64
     PRESCALER_DIVISION_BY_128
     PRESCALER_DIVISION_BY_256
     PRESCALER_DIVISION_BY_1024

 */
#define     PRESCALER           PRESCALER_DIVISION_BY_8



#endif

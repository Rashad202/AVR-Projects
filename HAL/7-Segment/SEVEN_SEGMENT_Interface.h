/*
 *   			--- SEVEN_SEGMENT_Interface.h----
 *
 *  Author : Rashad
 *  Layer  : HAL
 *  SWC    : SEVEN_SEGMENT
 *
 */

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

/* Segment Polarity */
#define COMMON_ANODE               0
#define COMMON_CATHODE             1






void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber );



void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number );


#endif

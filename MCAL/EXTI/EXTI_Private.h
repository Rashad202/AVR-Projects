#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Private Macros */

#define  GICR_REG            *((volatile u8*)0x5B)
#define  MCUCR_REG           *((volatile u8*)0x55)
#define  MCUCSR_REG          *((volatile u8*)0x54)

/* Private Macros to BIT Numbers */
#define  PIN0                    0
#define  PIN1                    1
#define  PIN2                    2
#define  PIN3                    3
#define  PIN4                    4
#define  PIN5                    5
#define  PIN6                    6
#define  PIN7                    7

#define  NULL                     (void*)(0)

#endif
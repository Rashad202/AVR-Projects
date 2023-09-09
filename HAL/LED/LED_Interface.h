#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H



void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );


void LED_voidInit_8Leds_Port ( u8 Copy_u8PortNumber);


void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status );


void LED_voidStatus_8Leds_Port ( u8 Copy_u8PortNumber, u8 Copy_u8Status );


void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );


void LED_voidToggle_8Leds_Port ( u8 Copy_u8PortNumber );




#endif
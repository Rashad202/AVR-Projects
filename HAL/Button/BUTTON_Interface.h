
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H



void BUTTON_voidInit_Button_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus );

void BUTTON_voidInit_8Buttons_Port ( u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus );

u8 BUTTON_u8Get_Button_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

u8 BUTTON_u8Get_8Buttons_Port (u8 Copy_u8PortNumber);


#endif

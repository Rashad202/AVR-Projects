#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


void USART_voidInit (void);


void USART_voidSendData (u8 Copy_u8Data);


void USART_voidRecieveData (u8 *Copy_Pu8Data);


void USART_voidAsyncSendData ( u8 Copy_u8Data , u8 *Copy_Pu8CallBackFunIndication_TXC );


void USART_voidAsyncRecieveData (u8 *Copy_Pu8Data);

#endif
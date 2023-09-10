/*
 *<<<<<<<<<<    SPI_interface.h     >>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : SPI
 *
 */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void SPI_voidMasterInit (void);


void SPI_voidSlaveInit (void);


u8 SPI_u8TranceiveData (u8 Copy_u8Data);


void SPI_voidTransmitData (u8 Copy_u8Data);


u8 SPI_voidRecieveData (void);


void SPI_voidTranceiveString (u8 *Copy_Au8TransmitString , u8 *Copy_u8RecieveString );


void SPI_voidSetCallBack (  void (*Local_PointerToFunction) (u8 *Copy_u8RecivedData) );


void SPI_u8AsynTranceiveData (u8 Copy_u8Data);


#endif

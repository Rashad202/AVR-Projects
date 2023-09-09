#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define     CPU_CLK             8000000
#define     BAUD_RATE           9600


/*   Select Normal or Double Speed Transsmition  */
#define     DOUBBLE_SPEED           0
#define     NORMAL_SPEED            1


#define     SPEED            DOUBBLE_SPEED




/*    Select Parity Mode EVEN , ODD , DISABLE    */
#define     DISABLE                  0
#define     EVEN                     1
#define     ODD                      2


#define     Parity_Mode             DISABLE



/*        Select STOP BIT  { ONE , TWO }         */

#define     ONE                      0
#define     TWO                      1

#define     STOP_BIT                ONE

#endif
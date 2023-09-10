
#ifndef BUZZER_INT_H_
#define BUZZER_INT_H_

/**
* Direction of BUZZER
*/
#define BUZZER_OUTPUT 1

#define BUZZER_HIGH	  1

#define BUZZER_LOW	  0


#define BUZZER_PORT    DIO_PORTA
#define BUZZER_PIN     DIO_PIN0


void BUZZER_voidBUZZERInit (void) ;


void BUZZER_voidBUZZEROn (void) ;


void BUZZER_voidBUZZEROff (void) ;


void HUZZER_voidBUZZERToggle (void) ;

#endif /* BUZZER_INT_H_ */

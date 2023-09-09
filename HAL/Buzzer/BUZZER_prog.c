#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUZZER_int.h"
#include "BUZZER_private.h"
#include "BUZZER_conf.h"

void BUZZER_voidBUZZERInit (void)
{
	/** select direction of buzzer as output */
    DIO_voidSetPinDirection(BUZZER_PORT , BUZZER_PIN , BUZZER_OUTPUT) ; 
}

void BUZZER_voidBUZZEROn (void)
{
	/**make buzzer on (it's pin is high)*/
	DIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN,BUZZER_HIGH) ; 
}

void BUZZER_voidBUZZEROff (void)
{
	/**make buzzer off (it's pin is low)*/
	DIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN,BUZZER_LOW) ;
}

void BUZZER_voidBUZZERToggle (void)
{
	/**inverse the status of buzzer*/
	DIO_voidTogglePinValue(BUZZER_PORT , BUZZER_PIN) ; 
}

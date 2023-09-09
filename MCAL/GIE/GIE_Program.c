#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"


void GIE_void_GI_Enable ( u8 Copy_u8Status )
{
    switch ( Copy_u8Status )
    {
        case ON  :    SET_BIT(SREG_REG,7);       break;
        case OFF :    CLEAR_BIT(SREG_REG,7);     break;
        default  :                               break;
    }
}

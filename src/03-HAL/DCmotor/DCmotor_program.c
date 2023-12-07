/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		7/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_interface.h"

#include "DCmotor_private.h"
#include "DCmotor_config.h"
#include "DCmotor_interface.h"


void HDC_init (DCmotor_Type M1)
{
	MTimer_voidInit(M1.FirstTimerType) ;
	if (M1.FirstTimerType != M1.SecondTimerType)
	{
		MTimer_voidInit(M1.SecondTimerType) ;
	}
}

void HDC_CounterClockWise  (DCmotor_Type M1 , u16 A_u16CaptureValue )
{
	MTimer_voidPWM(M1.FirstTimerType     ,
			       M1.FirstChannelNumber ,
				   A_u16CaptureValue
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
                   M1.SecondChannelNumber ,
				   0
				   )                      ;
}

void HDC_ClockWise  (DCmotor_Type M1 , u16 A_u16CaptureValue)
{
	MTimer_voidPWM(M1.FirstTimerType     ,
				   M1.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
	               M1.SecondChannelNumber ,
				   A_u16CaptureValue
				   )                      ;
}

void HDC_Stop  (DCmotor_Type M1)
{
	MTimer_voidPWM(M1.FirstTimerType     ,
				   M1.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
	               M1.SecondChannelNumber ,
				   0
				   )                      ;
}

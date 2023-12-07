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


DCmotor_Type M1 =
{
		.FirstTimerType      = TIM2_TYPE     ,
		.SecondTimerType     = TIM2_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_1 ,
		.SecondChannelNumber = TIM_CHANNEL_2
};

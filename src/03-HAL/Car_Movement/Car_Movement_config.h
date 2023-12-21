/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		20/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#ifndef _Car_Movement_config_H
#define _Car_Movement_config_H


 DCmotor_Type Motor1 =
{
		.FirstTimerType      = TIM1_TYPE     ,
		.SecondTimerType     = TIM1_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_1 ,
		.SecondChannelNumber = TIM_CHANNEL_2
};
 DCmotor_Type Motor3 =
 {
 		.FirstTimerType      = TIM1_TYPE     ,
 		.SecondTimerType     = TIM1_TYPE     ,
 		.FirstChannelNumber  = TIM_CHANNEL_3 ,
 		.SecondChannelNumber = TIM_CHANNEL_4
 };








#endif //_Car_Movement_config_H

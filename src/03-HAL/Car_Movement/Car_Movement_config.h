/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		20/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#ifndef _Car_Movement_config_H
#define _Car_Movement_config_H



#define MOTOR1_PORT	GPIOA
#define MOTOR2_PORT GPIOA

#define IN1_PIN		PIN0
#define IN2_PIN		PIN1

#define IN3_PIN		PIN2
#define IN4_PIN		PIN3

 // Initialize motor 1
DCM_MotorConfiguration Motor1 =
{
    .u8Port			= MOTOR1_PORT	,
    .u8Pin1 		= IN1_PIN		,
    .u8Pin2 		= IN2_PIN		,
	.u8SpeedPin		= TIM_CHANNEL_1		,
	.u32SpeedRatio	= SPEED_0_PERCENT
};

// Initialize motor 3
DCM_MotorConfiguration Motor3 =
{
    .u8Port			= MOTOR2_PORT	,
    .u8Pin1 		= IN3_PIN		,
    .u8Pin2 		= IN4_PIN		,
	.u8SpeedPin		= TIM_CHANNEL_1		,
	.u32SpeedRatio	= SPEED_0_PERCENT
};








#endif //_Car_Movement_config_H

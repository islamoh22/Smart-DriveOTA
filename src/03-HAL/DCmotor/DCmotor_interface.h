/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		7/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#ifndef HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_
#define HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_

#include "DCmotor_private.h"
#include "DCmotor_config.h"
#include "DCmotor_interface.h"

void HDC_init (DCmotor_Type MotorConf) ;

void HDC_CounterClockWise  (DCmotor_Type MotorConf , u16 A_u8CaptureValue) ;

void HDC_ClockWise  (DCmotor_Type MotorConf , u16 A_u8CaptureValue) ;

void HDC_Stop  (DCmotor_Type M1) ;
#endif /* HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_ */

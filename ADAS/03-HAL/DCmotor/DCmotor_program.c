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
#include "GPIO_interface.h"
#include "RCC_Interface.h"


void HDC_init (DCM_MotorConfiguration pMotorConfiguration)
{
	//Enable the clock of the selected GPIO port
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(AHB1 , pMotorConfiguration.u8Port);

	MGPIO_voidPinInit(pMotorConfiguration.u8Port ,pMotorConfiguration.u8Pin1,OUTPUT,PUSH_PULL,LOW_SPEED,AF0);
	MGPIO_voidPinInit(pMotorConfiguration.u8Port ,pMotorConfiguration.u8Pin2,OUTPUT,PUSH_PULL,LOW_SPEED,AF0);

	switch (pMotorConfiguration.u8Direction)
	    {

	    case FORWARD:
	    	HDC_ClockWise  (pMotorConfiguration );
	        break;

	    case BACKWARD:
	    	HDC_CounterClockWise  (pMotorConfiguration) ;
	        break;

	    /* Default case: stop the motor */
	    default:
	    	HDC_Stop(pMotorConfiguration);
	        break;
	    }

	    // Give an initial speed to the DC Motor:
		HDC_MotorSpeedCntrl(pMotorConfiguration, pMotorConfiguration.u32SpeedRatio);


}

void HDC_CounterClockWise  (DCM_MotorConfiguration pMotorConfiguration)
{
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin1 , LOW );
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin2, HIGH );

}

void HDC_ClockWise  ( DCM_MotorConfiguration pMotorConfiguration )
{
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin1 , HIGH );
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin2 , LOW );
}

void HDC_Stop  (DCM_MotorConfiguration pMotorConfiguration)
{
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin1 , LOW );
	MGPIO_voidSetPinValueNonAtomic( pMotorConfiguration.u8Port, pMotorConfiguration.u8Pin2 , LOW );
}



void HDC_MotorSpeedCntrl( DCM_MotorConfiguration pMotorConfiguration, u16 A_u16SpeedValue)
{
	MTimer_voidInit (TIM1_TYPE);
	MTimer_voidPWM (TIM1_TYPE , pMotorConfiguration.u8SpeedPin ,  A_u16SpeedValue) ;


	switch (pMotorConfiguration.u8SpeedPin)
	    {

	    case TIM_CHANNEL_1:
	    	MTimer_voidSetCompareReg1Value( A_u16SpeedValue);
	        break;

	    case TIM_CHANNEL_2:
	    	MTimer_voidSetCompareReg2Value( A_u16SpeedValue);
	        break;

	    case TIM_CHANNEL_3:
	    	MTimer_voidSetCompareReg3Value( A_u16SpeedValue);
	        break;

	    case TIM_CHANNEL_4:
	    	MTimer_voidSetCompareReg4Value( A_u16SpeedValue);
	        break;

	    default:
	        break;
	    }

}


u32 HDC_GetSpeedValue(DCM_MotorConfiguration pMotorConfiguration)
{

	 	 u32 L_u32SpeedValue = 0;

	    switch (pMotorConfiguration.u8SpeedPin)
	    {

	    case TIM_CHANNEL_1:
	        L_u32SpeedValue = MTimer_u16GetCaptureReg1Value();
	        break;

	    case TIM_CHANNEL_2:
	        L_u32SpeedValue = MTimer_u16GetCaptureReg2Value();
	        break;

	    case TIM_CHANNEL_3:
	        L_u32SpeedValue = MTimer_u16GetCaptureReg3Value();
	        break;

	    case TIM_CHANNEL_4:
	        L_u32SpeedValue = MTimer_u16GetCaptureReg4Value();
	        break;

	    default: /* Do nothing */
	        break;
	    }

	    return L_u32SpeedValue;

}

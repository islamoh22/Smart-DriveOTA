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


typedef struct
{
    /**
     * @brief Initialize the DC Motor on a certain port
     */
    u8 u8Port;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8 u8Pin1;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8 u8Pin2;
    /**
     * @brief Initialize the DC Motor with a certain direction
     */
    u8 u8Direction;
    /**
     * @brief Initialize the DC Motor with a certain speed pin
     */
    u8 u8SpeedPin;
    /**
     * @brief Initialize the DC Motor with a certain speed ratio
     */
    u32 u32SpeedRatio;
} DCM_MotorConfiguration;


/**
 * @def FORWARD
 * @brief Motor forward direction
 *
 */
#define FORWARD (CW)

/**
 * @def BACKWARD
 * @brief Motor backward direction
 *
 */
#define BACKWARD (CCW)


/**
 * @def SPEED_0_PERCENT
 * @brief Motor speed 0%
 */
#define SPEED_0_PERCENT 0

/**
 * @def SPEED_10_PERCENT
 * @brief Motor speed 10%
 */
#define SPEED_10_PERCENT 1000U

/**
 * @def SPEED_20_PERCENT
 * @brief Motor speed 20%
 */
#define SPEED_20_PERCENT 2000U

/**
 * @def SPEED_30_PERCENT
 * @brief Motor speed 30%
 */
#define SPEED_30_PERCENT 3000U

/**
 * @def SPEED_40_PERCENT
 * @brief Motor speed 40%
 */
#define SPEED_40_PERCENT 4000U

/**
 * @def SPEED_50_PERCENT
 * @brief Motor speed 50%
 */
#define SPEED_50_PERCENT 5000U

/**
 * @def SPEED_60_PERCENT
 * @brief Motor speed 60%
 */
#define SPEED_60_PERCENT 6000U

/**
 * @def SPEED_70_PERCENT
 * @brief Motor speed 70%
 */
#define SPEED_70_PERCENT 7000U

/**
 * @def SPEED_80_PERCENT
 * @brief Motor speed 80%
 */
#define SPEED_80_PERCENT 8000U

/**
 * @def SPEED_90_PERCENT
 * @brief Motor speed 90%
 */
#define SPEED_90_PERCENT 9000U

/**
 * @def SPEED_100_PERCENT
 * @brief Motor speed 100%
 */
#define SPEED_100_PERCENT 10000U


void HDC_init (DCM_MotorConfiguration pMotorConfiguration) ;

void HDC_CounterClockWise  (DCM_MotorConfiguration pMotorConfiguration) ;

void HDC_ClockWise  (DCM_MotorConfiguration pMotorConfiguration ) ;

void HDC_MotorSpeedCntrl( DCM_MotorConfiguration pMotorConfiguration, u16 A_u16SpeedValue);

void HDC_Stop  (DCM_MotorConfiguration pMotorConfiguration) ;

u32 HDC_GetSpeedValue(DCM_MotorConfiguration pMotorConfiguration);


#endif /* HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_ */

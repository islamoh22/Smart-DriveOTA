/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		7/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#ifndef MCAL_TIMER_TIMER_INIT_H_
#define MCAL_TIMER_TIMER_INIT_H_

/*
 * define A_u8TimerSelected
 */
#define TIM1_TYPE     1
#define TIM2_TYPE     2
#define TIM3_TYPE     3
#define TIM4_TYPE     4
#define TIM5_TYPE     5

/*
 * define A_u8Channel
 *
 * note that for TIM1 to TIM5 there are 4 channels
 */
#define TIM_CHANNEL_1  1
#define TIM_CHANNEL_2  2
#define TIM_CHANNEL_3  3
#define TIM_CHANNEL_4  4

/**
	Function Name        : MTimer_voidInit
	Function Returns     : void
	Function Arguments   : u8 A_u8TimerSelected
	Function Description : initialize the timer
*/
void MTimer_voidInit (u8 A_u8TimerSelected) ;

/**
	Function Name        : MTimer_voidPWM
	Function Returns     : void
	Function Arguments   : u8 A_u8TimerSelected , u8 A_u8Channel , u16 A_u16CompareValue
	Function Description : generate the pwm signal
*/
void MTimer_voidPWM (u8 A_u8TimerSelected , u8 A_u8Channel , u16 A_u16CompareValue) ;


void MTimer_voidSetCompareReg1Value( u16 A_u16CCR1_Value );

u16 MTimer_u16GetCaptureReg1Value( void );

void MTimer_voidSetCompareReg2Value( u16 A_u16CCR2_Value ) ;

u16 MTimer_u16GetCaptureReg2Value( void ) ;

void MTimer_voidSetCompareReg3Value( u16 A_u16CCR3_Value ) ;

u16 MTimer_u16GetCaptureReg3Value( void ) ;

void MTimer_voidSetCompareReg4Value( u16 A_u16CCR4_Value ) ;

u16 MTimer_u16GetCaptureReg4Value( void ) ;





#endif /* MCAL_TIMER_TIMER_INIT_H_ */

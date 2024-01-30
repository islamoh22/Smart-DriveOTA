/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		20/12/2023										 */
/*	Version :		V01												 */
/*********************************************************************/

#ifndef _Car_Movement_interface_H
#define _Car_Movement_interface_H


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/



void HCarMove_vInit(void);

void HCarMove_vSpeedRatio( u16 A_u16SpeedRatio );

void HCarMove_vForward();

void HCarMove_vBackward();

void HCarMove_vRight();

void HCarMove_vLeft();

void HCarMove_vStop(void);

u32 HCarMove_u32GetCarSpeed( void );










#endif //_Car_Movement_interface_H

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

void HCarMove_vForward(u16 speed);

void HCarMove_vBackward(u16 speed);

void HCarMove_vRight(u16 speed);

void HCarMove_vLeft(u16 speed);

void HCarMove_vStop(void);









#endif //_Car_Movement_interface_H

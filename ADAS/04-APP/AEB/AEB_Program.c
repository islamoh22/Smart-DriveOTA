#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TF_LUNA_LIDAR_INTERFACE.h"
#include "Car_Movement_interface.h"

#include "AEB_Interface.h"
#include "AEB_Private.h"
#include "AEB_Config.h"

void APP_VoidAEB(void){
	HCarMove_vInit();
	HCarMove_vSpeedRatio( 80 );
	HCarMove_vBackward();
	TF_LUNA_LIDAR_VoidInit();
	while(1){
		if(TF_LUNA_LIDAR_U16GetDistance() <= BREAK_DISTANCE){
			HCarMove_vStop();
		}else{
			HCarMove_vSpeedRatio( 80 );
			HCarMove_vBackward();
		}
	}
}
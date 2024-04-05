#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TF_LUNA_LIDAR_INTERFACE.h"
#include "Car_Movement_interface.h"
#include "GPIO_Interface.h"

#include "FCW_Interface.h"
#include "FCW_Private.h"
#include "FCW_Config.h"

void APP_VoidFCW(void){
	HCarMove_vInit();
	HCarMove_vSpeedRatio( 80 );
	HCarMove_vBackward();
	TF_LUNA_LIDAR_VoidInit();
	MGPIO_voidPinInit(GPIOA, PIN12, OUTPUT, PUSH_PULL, LOW_SPEED, AF0);
	while(1){
		if(TF_LUNA_LIDAR_U16GetDistance() <= WARNING_DISTANCE){
			MGPIO_voidSetPinValueNonAtomic(GPIOA, PIN12, HIGH);
		}else{
			MGPIO_voidSetPinValueNonAtomic(GPIOA, PIN12, LOW);
		}
	}
}
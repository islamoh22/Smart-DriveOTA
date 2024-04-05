/************************************************/
/*	Author	:	Eslam Mohamed                   */
/*	Date	:	4/2/2024                      */
/*	Version	:	V02                             */
/************************************************/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DCmotor_interface.h"
#include "Car_Movement_interface.h"
#include "TF_LUNA_LIDAR_INTERFACE.h"


#include "ACC_interface.h"
#include "ACC_private.h"
#include "ACC_config.h"




u32 L_u32SpeedValue  			= INITIAL_ZERO 	;
u32 L_f32Distance 				= INITIAL_ZERO		;



/// Function to turn on Adaptive Cruise Control (ACC) mode
void APP_VoidFCW( void )
{
    // Initialize the TF_LUNA_LIDAR sensor
    TF_LUNA_LIDAR_VoidInit();

    // Main loop for ACC operation
    while (1)
    {
        // Read the distance from the TF_LUNA_LIDAR sensor
        L_f32Distance = TF_LUNA_LIDAR_U16GetDistance();

        // Check if the distance is below the safe distance threshold
        if (L_f32Distance <= ACC_SAFE_DISTANCE)
        {
            // If too close, stop the car
            HCarMove_vStop();
        }
        else
        {
            // Gradually adjust speed based on distance
            if (L_f32Distance == ACC_NORMAL_DISTANCE)
            {
                // Maintain initial speed if at normal distance
                L_u32SpeedValue = INITIAL_SPEED;
            }
            else if (L_f32Distance > ACC_NORMAL_DISTANCE)
            {
                // Gradually increase speed to the maximum speed
                if (L_u32SpeedValue < MAX_SPEED_PERCENTAGE)
                {
                    L_u32SpeedValue += SPEED_INCREMENT_PERCENTAGE;
                }
                else
                {
                    L_u32SpeedValue = MAX_SPEED_PERCENTAGE;
                }
            }
            else
            {
                // Gradually decrease speed to the minimum speed
                if (L_u32SpeedValue > MIN_SPEED_PERCENTAGE)
                {
                    L_u32SpeedValue -= SPEED_DECREMENT_PERCENTAGE;
                }
                else
                {
                    L_u32SpeedValue = MIN_SPEED_PERCENTAGE;
                }
            }

            // Set the adjusted speed and move forward
            HCarMove_vSpeedRatio(L_u32SpeedValue);
            HCarMove_vForward();
        }

        // Consider adding a delay or system exit condition here
    }
}





















/*=================================================================================*/
/*  File        : RCC_Program.c                                                    */

/*=================================================================================*/



/*==========================================*/
/* Include Header Files From include Folder */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*==========================================*/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*==========================================*/



/********************************************    RCC_voidInitSystemClock            *************************************/
/********************************************    RCC_voidEnablePeripheralClock      *************************************/ 
/********************************************    RCC_voidDisablePeripheralClock     *************************************/ 


/************************************************************************************************/
/* Function Name : RCC_voidInitSystemClock                                                      */
/* Description : Initilization of RCC to initialize System clock                                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidInitSystemClock (void)
{
    #if  (RCC_CLOCK_SOURCE == HSI) 
        SET_BIT(RCC_CR,0U);                  // Enable HSI (Set HSI BIT) 
        /* Select HSI as Sys CLOCK Source */
        CLR_BIT(RCC_CFGR,0U);
        CLR_BIT(RCC_CFGR,1U);
    #elif (RCC_CLOCK_SOURCE == HSE_OSC) 
        CLR_BIT(RCC_CR,18U);               // Not bypassed
        SET_BIT(RCC_CR,16U);                 // Enable HSE (Set HSE BIT)
        /* Select HSE as System CLOCK Source */
        SET_BIT(RCC_CFGR,0U);
        CLR_BIT(RCC_CFGR,1U);
    #elif  (RCC_CLOCK_SOURCE == HSE_RC) 
        SET_BIT(RCC_CR,18U);                 // bypassed
        SET_BIT(RCC_CR,16U);                 // Enable HSE (Set HSE BIT)
        /* Select HSE as System CLOCK Source */
        SET_BIT(RCC_CFGR,0U);
        CLR_BIT(RCC_CFGR,1U);
    #elif  (RCC_CLOCK_SOURCE == PLL) 

    #else
        #error Invalid Clock Source 
    #endif

    #if( AHB_PRESCALLER ==  system_clock_divided_by_2 )
        CLR_BIT(RCC_CFGR,4);
        CLR_BIT(RCC_CFGR,5);
        CLR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #elif ( AHB_PRESCALLER == system_clock_divided_by_4 )
          SET_BIT(RCC_CFGR,4);
          CLR_BIT(RCC_CFGR,5);
          CLR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #elif ( AHB_PRESCALLER == system_clock_divided_by_8 )
          CLR_BIT(RCC_CFGR,4);
          SET_BIT(RCC_CFGR,5);
          CLR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #endif
}

/************************************************************************************************/
/* Function Name : RCC_voidEnablePeripheralClock                                                */
/* Description : Enable clock source to specific Bus and specific Peripheral                    */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Peripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidEnablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
    /* Input Validation */
    if( Copy_u8PeripheralID > 31 )
    {
        // Nothing to be Done
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1 :   SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);   break;
            case AHB2 :   SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);   break;
            case APB1 :   SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);   break;
            case APB2 :   SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);   break;
            default :                                                 break;
        }
    }
}

/************************************************************************************************/
/* Function Name : RCC_voidDisablePeripheralClock                                               */
/* Description : Disable clock source to specific Bus and specific Peripheral                   */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Peripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidDisablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
    /* Input Validation */
    if( Copy_u8PeripheralID > 31 )
    {
        // Nothing to be Done
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1 :   CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);   break;
            case AHB2 :   CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);   break;
            case APB1 :   CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);   break;
            case APB2 :   CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);   break;
            default :                                                   break;
        }
    }
}

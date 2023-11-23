/***************************************************************************/
/* Author : Menna Mohamed                                                  */
/* Date   : 22 nov 2023                                                    */
/* version: v01                                                            */
/***************************************************************************/
#ifndef_RCC_config_h
#define_RCC_config_h

/* Options: RCC_HSE_CRYSTAL
            RCC_HSE_RC 
            RCC_HSI
            RCC_PLL        */			
#define RCC_COLOCK_TYPE    RCC_HSE_CRYSTAL


/* Options:   RCC_PLL_IN_HSI_DIV_2
              RCC_PLL_IN_HSE_DIV_2
			  RCC_PLL_IN_HSE        */
			  
/* Note : Select value only if you have PLL as input clock sourse */
#if RCC CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	   RCC_PLL_IN_HSE_DIV_2		  
#endif


/* Options 2 to 16 */
/* Note : Select value only if you have PLL as input clock sourse */
#if RCC CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL


#endif
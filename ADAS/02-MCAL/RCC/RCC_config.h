

/* File Gaurd*/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*=======================================*/
/*=========  Configration List   ========*/
/*=== { HSI , HSE_OSC , HSE_RC , PLL } ==*/
/*=======================================*/
#define RCC_CLOCK_SOURCE    HSI
/*=======================================*/
/*=======================================*/
/*=========    AHB Prescaller    ========*/
#define system_clock_divided_by_2           0
#define system_clock_divided_by_4           1
#define system_clock_divided_by_8           2
/*=======================================*/
#define AHB_PRESCALLER      system_clock_divided_by_2
/*=======================================*/


#endif

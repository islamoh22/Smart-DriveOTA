

/* File Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*======================================================================================================================*/
/*======================================================================================================================*/

/************************************************************************************************/
/* Function Name : MRCC_voidInitSystemClock                                                      */
/* Description : Initialization of RCC to initialize System clock                                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidInitSystemClock (void);

/************************************************************************************************/
/* Function Name : MRCC_voidEnablePeripheralClock                                                */
/* Description : Enable clock source to specific Bus and specific Peripheral                    */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Peripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidEnablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralClock);

/************************************************************************************************/
/* Function Name : MRCC_voidDisablePeripheralClock                                               */
/* Description : Disable clock source to specific Bus and specific Peripheral                   */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MRCC_voidDisablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralClock);

/*====================================================================================================*/
/*====================================================================================================*/
/*=======================================*/
/*============     Bus ID     ===========*/
/*=======================================*/
#define	   AHB1			        0
#define    AHB2			        1
#define    APB1			        2
#define    APB2			        3
/*=======================================*/
/*=======================================*/
/*========     Peripheral ID     ========*/
/*=======================================*/
/*-------------- AHB1 Bus ---------------*/
#define     RCC_GPIOA         0
#define     RCC_GPIOB         1
#define     RCC_GPIOC         2
#define     RCC_CRC           12
#define     RCC_FLITF         15
#define     RCC_SRAM1         16
#define     RCC_DMA1          21
#define     RCC_DMA2          22
/*-------------- AHB2 Bus ---------------*/
#define     RCC_OTGFS         7
/*-------------- APB1 Bus ---------------*/
#define     RCC_TIM2          0
#define     RCC_TIM3          1
#define     RCC_TIM4          2
#define     RCC_TIM5          3
#define     RCC_WWDG          11
#define     RCC_SPI2          14
#define     RCC_SPI3          15
#define     RCC_USART2        17
#define     RCC_I2C1          21
#define     RCC_I2C2          22
#define     RCC_I2C3          23
#define     RCC_PWR           28
/*-------------- APB2 Bus ---------------*/
#define     RCC_TIM1          0
#define     RCC_USART1        4
#define     RCC_USART6        5
#define     RCC_ADC1          8
#define     RCC_SDIO          11
#define     RCC_SPI1          12
#define     RCC_SPI4          13
#define     RCC_SYSCFG        14
#define     RCC_TIM9          16
#define     RCC_TIM10         17
#define     RCC_TIM11         18
/*====================================================================================================*/
#endif

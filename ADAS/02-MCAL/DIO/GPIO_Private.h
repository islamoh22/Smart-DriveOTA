/*=================================================================================*/
/*  File        : GPIO_Private.h                                                   */
/*  Description : This Private file includes GPIO Drivers macros for STM32F446RE   */
/*  Author      : Ebrahem Mostafa                                                  */
/*  Date        : 22/11/2023                                                       */
/*=================================================================================*/

/*File Guard*/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

/******************** GPIOA Registers **************************/
#define GPIOA_MODER   *((volatile u32*)(GPIOA_BASE_ADDRESS+0x00)) // GPIOA port mode register (GPIOA_MODER)
#define GPIOA_OTYPER  *((volatile u32*)(GPIOA_BASE_ADDRESS+0x04)) // GPIOA port output type register (GPIOA_OTYPER)
#define GPIOA_OSPEEDR *((volatile u32*)(GPIOA_BASE_ADDRESS+0x08)) // GPIOA port output speed register (GPIOA_OSPEEDR)
#define GPIOA_PUPDR   *((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C)) // GPIOA port pull-up/pull-down register (GPIOA_PUPDR)
#define GPIOA_IDR     *((volatile u32*)(GPIOA_BASE_ADDRESS+0x10)) // GPIOA port input data register (GPIOA_IDR)
#define GPIOA_ODR     *((volatile u32*)(GPIOA_BASE_ADDRESS+0x14)) // GPIOA port output data register (GPIOA_ODR)
#define GPIOA_AFRH     *((volatile u32*)(GPIOA_BASE_ADDRESS+0X24))
#define GPIOA_AFRL     *((volatile u32*)(GPIOA_BASE_ADDRESS+0X20))
#define GPIOA_BSRR     *((volatile u32*)(GPIOA_BASE_ADDRESS+0x18))     // GPIOA port bit set/reset register (GPIOA_BSRR)
/******************** GPIOB Registers **************************/
#define GPIOB_MODER   *((volatile u32*)(GPIOB_BASE_ADDRESS+0x00)) // GPIOB port mode register (GPIOA_MODER)
#define GPIOB_OTYPER  *((volatile u32*)(GPIOB_BASE_ADDRESS+0x04)) // GPIOB port output type register (GPIOA_OTYPER)
#define GPIOB_OSPEEDR *((volatile u32*)(GPIOB_BASE_ADDRESS+0x08)) // GPIOB port output speed register (GPIOA_OSPEEDR)
#define GPIOB_PUPDR   *((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C)) // GPIOB port pull-up/pull-down register (GPIOA_PUPDR)
#define GPIOB_IDR     *((volatile u32*)(GPIOB_BASE_ADDRESS+0x10)) // GPIOB port input data register (GPIOA_IDR)
#define GPIOB_ODR     *((volatile u32*)(GPIOB_BASE_ADDRESS+0x14)) // GPIOB port output data register (GPIOA_ODR)
#define GPIOB_AFRH     *((volatile u32*)(GPIOB_BASE_ADDRESS+0X24))
#define GPIOB_AFRL     *((volatile u32*)(GPIOB_BASE_ADDRESS+0X20))
#define GPIOB_BSRR     *((volatile u32*)(GPIOB_BASE_ADDRESS+0x18))
/******************** GPIOC Registers **************************/
#define GPIOC_MODER   *((volatile u32*)(GPIOC_BASE_ADDRESS+0x00)) // GPIOC port mode register (GPIOA_MODER)
#define GPIOC_OTYPER  *((volatile u32*)(GPIOC_BASE_ADDRESS+0x04)) // GPIOC port output type register (GPIOA_OTYPER)
#define GPIOC_OSPEEDR *((volatile u32*)(GPIOC_BASE_ADDRESS+0x08)) // GPIOC port output speed register (GPIOA_OSPEEDR)
#define GPIOC_PUPDR   *((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C)) // GPIOC port pull-up/pull-down register (GPIOA_PUPDR)
#define GPIOC_IDR     *((volatile u32*)(GPIOC_BASE_ADDRESS+0x10)) // GPIOC port input data register (GPIOA_IDR)
#define GPIOC_ODR     *((volatile u32*)(GPIOC_BASE_ADDRESS+0x14)) // GPIOC port output data register (GPIOA_ODR)
#define GPIOC_AFRH     *((volatile u32*)(GPIOC_BASE_ADDRESS+0X24))
#define GPIOC_AFRL     *((volatile u32*)(GPIOC_BASE_ADDRESS+0X20))
#define GPIOC_BSRR     *((volatile u32*)(GPIOC_BASE_ADDRESS+0x18))

#endif /* GPIO_PRIVATE_H_ */

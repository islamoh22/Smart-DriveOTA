/***************************************************************************/
/* Author : Menna Mohamed                                                  */
/* Date   : 22 nov 2023                                                    */
/* version: v01                                                            */
/***************************************************************************/
#ifndef_RCC_private_h
#define_RCC_private_h


/* Register Definition */
#define RCC_BASE_ADDRESS    0x40023800 

#define RCC_CR           *((volatile u32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_PLLCFGR      *((volatile u32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CFGR         *((volatile u32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_CIR          *((volatile u32*)(RCC_BASE_ADDRESS+0x0C))
#define RCC_AHB1RSTR     *((volatile u32*)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHB2RSTR     *((volatile u32*)(RCC_BASE_ADDRESS+0x14))
#define RCC_AHB3RSTR     *((volatile u32*)(RCC_BASE_ADDRESS+0x18))
#define RCC_APB1RSTR     *((volatile u32*)(RCC_BASE_ADDRESS+0x20))
#define RCC_APB2RSTR     *((volatile u32*)(RCC_BASE_ADDRESS+0x24))
#define RCC_AHB1ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x30))
#define RCC_AHB2ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x34))
#define RCC_AHB3ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x38))
#define RCC_APB1ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x40))
#define RCC_APB2ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x44))
#define RCC_AHB1LPENR    *((volatile u32*)(RCC_BASE_ADDRESS+0x50))
#define RCC_AHB2LPENR    *((volatile u32*)(RCC_BASE_ADDRESS+0x54))
#define RCC_AHB3LPENR    *((volatile u32*)(RCC_BASE_ADDRESS+0x58))
#define RCC_APB1LPENR    *((volatile u32*)(RCC_BASE_ADDRESS+0x60))
#define RCC_APB2LPENR    *((volatile u32*)(RCC_BASE_ADDRESS+0x64))
#define RCC_BDCR         *((volatile u32*)(RCC_BASE_ADDRESS+0x70))
#define RCC_CSR          *((volatile u32*)(RCC_BASE_ADDRESS+0x74))
#define RCC_SSCGR        *((volatile u32*)(RCC_BASE_ADDRESS+0x80))
#define RCC_PLLI2SCFGR   *((volatile u32*)(RCC_BASE_ADDRESS+0x84))
#define RCC_PLLSAICFGR   *((volatile u32*)(RCC_BASE_ADDRESS+0x88))
#define RCC_DCKCFGR      *((volatile u32*)(RCC_BASE_ADDRESS+0x8C))
#define RCC_CLGATENR     *((volatile u32*)(RCC_BASE_ADDRESS+0x90))
#define RCC_DCKCFGR2     *((volatile u32*)(RCC_BASE_ADDRESS+0x94))
     

/*Clock Types */
#define   RCC_HSE_CRYSTAL   0
#define   RCC_HSE_RC        1
#define   RCC_HSI           2
#define   RCC_PLL           3

/*PLL Options */
#define   RCC_PLL_IN_HSI_DIV_2  0
#define   RCC_PLL_IN_HSE_DIV_2  1
#define   RCC_PLL_IN_HSE        2






#endif
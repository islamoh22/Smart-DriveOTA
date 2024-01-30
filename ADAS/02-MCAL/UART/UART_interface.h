/************************************************/
/*	Author	:	Eslam Mohamed                   */
/*	Date	:	30/1/2024                      */
/*	Version	:	V02                             */
/************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*============================================*/
/*============ 	 UART BAUDRATES   ============*/
/*============================================*/
typedef enum{
    B_1200   = 0x44505400,
    B_2400   = 0x43d05800,
    B_9600   = 0x341,
    B_19200  = 0x42504000,
    B_38400  = 0x41d08000,
    B_57600  = 0x418b0000,
    B_115200 = 0x45
}u_BaudRate_t;
/*=============================================*/
/*======== 	 USART Register Structure   =======*/
/*=============================================*/
typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;
/*=============================================*/
/*=====   The USART Structure Pointer 	=======*/
/*=============================================*/
#define 	UART1 		((USART_t *)0x40011000)
#define 	UART2 		((USART_t *)0x40004400)
#define 	UART6 		((USART_t *)0x40011400)


void	MUSART1_voidInit(USART_t *UARTx);
void	MUSART1_voidTransmit(USART_t *UARTx, u8 arr[]);
void	MUSART1_voidTransmitByte( USART_t *UARTx , u8 byte);
u8		MUSART1_u8Recieve(USART_t *UARTx);

#endif

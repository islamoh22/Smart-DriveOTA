/************************************************/
/*	Author	:	Eslam Mohamed                   */
/*	Date	:	26/11/2023                      */
/*	Version	:	V02                            */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void	MUSART1_voidInit(USART_t *UARTx)
{
	/*9600 		BRR = 0x341 */
	UARTx->BRR = B_9600;
	/*
		1- Enable RX
		2- Enable TX
		3- Enable USART
	*/
	SET_BIT(UARTx->CR1 , 2);
	SET_BIT(UARTx->CR1 , 3);
	SET_BIT(UARTx->CR1 , 13);

	
	/* Clear Status Register */
	UARTx->SR = 0;
	
}

void	MUSART1_voidTransmit( USART_t *UARTx , u8 arr[])
{
	u8 i = 0 ;
	while(arr[i] != '\0')
	{
		UARTx->DR = arr[i];
		/* Wait till transmission is complete */
		while((GET_BIT((UARTx->SR),6)) == 0);
		i++;
	}
}

u8		MUSART1_u8Recieve(USART_t *UARTx)
{
	u8 Loc_u8ReceivedData = 0;
		while((GET_BIT((UARTx->SR), 5)) == 0);
		Loc_u8ReceivedData = UARTx->DR;
		return (Loc_u8ReceivedData);
}

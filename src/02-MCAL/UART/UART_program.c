/************************************************/
/*	Author	:	Eslam Mohamed                   */
/*	Date	:	21/11/2023                      */
/*	Version	:	V01                             */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void	MUSART1_voidInit(void)
{
	/*9600 		BRR = 0x683 */
	UART1->BRR = B_9600;
	/*
		1- Enable RX
		2- Enable TX
		3- Enable USART
	*/
	SET_BIT(UART1->CR1 , 2);
	SET_BIT(UART1->CR1 , 3);
	SET_BIT(UART1->CR1 , 13);

	
	/* Clear Status Register */
	UART1->SR = 0;
	
}

void	MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0 ;
	while(arr[i] != '\0')
	{
		UART1->DR = arr[i];
		/* Wait till transmission is complete */
		while((GET_BIT((UART1->SR),6)) == 0);
		i++;
	}
}

u8		MUSART1_u8Recieve(void)
{
	u8 Loc_u8ReceivedData = 0;
		while((GET_BIT((UART1->SR), 5)) == 0);
		Loc_u8ReceivedData = UART1->DR;
		return (Loc_u8ReceivedData);
}

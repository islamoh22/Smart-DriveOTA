/*
 * TF_LUNA_LIDAR_PROGRAM.c
 *
 *  Created on: Feb 2, 2024
 *      Author: Ammar
 */

#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "UART_INTERFACE.h"
#include "TF_LUNA_LIDAR_INTERFACE.h"
#include "TF_LUNA_LIDAR_PRIVATE.h"
#include "TF_LUNA_LIDAR__CONFIG.h"

void TF_LUNA_LIDAR_VoidInit(){
	MRCC_voidInitSystemClock();
    // Enable GPIOA from RCC
    MRCC_voidEnablePeripheralClock(AHB1, RCC_GPIOA);
    // Enable USART1 from RCC
    MRCC_voidEnablePeripheralClock(APB2, RCC_USART1);
	// Configure USART2 Pins as Alternative Function Push Pull with AF7 USART1
    MGPIO_voidPinInit(GPIOA, PIN9, ALTERNATE, PUSH_PULL, LOW_SPEED, AF7); // PortA , PIN9 , TX
    MGPIO_voidPinInit(GPIOA, PIN10, ALTERNATE, PUSH_PULL, LOW_SPEED, AF7); // PORTA , PIN10 , RX*/
	// Configuration of UART
    MUSART1_voidInit(UART1);
	
	MUSART1_voidTransmitByte(UART1, 0x5A);
    MUSART1_voidTransmitByte(UART1, 0x06);
    MUSART1_voidTransmitByte(UART1, 0x03);
    MUSART1_voidTransmitByte(UART1, 0x00);
    MUSART1_voidTransmitByte(UART1, 0x00);
    MUSART1_voidTransmitByte(UART1, 0x0B);
	
    MUSART1_voidTransmitByte(UART1, 0x5A);
    MUSART1_voidTransmitByte(UART1, 0x05);
    MUSART1_voidTransmitByte(UART1, 0x05);
    MUSART1_voidTransmitByte(UART1, 0x02);
    MUSART1_voidTransmitByte(UART1, 0x11);
}

u16  TF_LUNA_LIDAR_U16GetDistance(){
    u8 distance[10];
    u16 distance_measured = 0;
    u8 value_received = '.';

    MUSART1_voidTransmitByte(UART1, 0x5A);
    MUSART1_voidTransmitByte(UART1, 0x04);
    MUSART1_voidTransmitByte(UART1, 0x04);
    MUSART1_voidTransmitByte(UART1, 0x0C);
    while(value_received != ' ')value_received = MUSART1_u8Recieve(UART1);
    u8 i = 0;
    while(i < 4){
        distance[i] = MUSART1_u8Recieve(UART1);
        i++;
    }

    distance[i] = '\0';

    i = 0;
    while(i < 4){
        if(distance[i] != '.' && distance[i] != '\r' && distance[i] != '\n'){
            distance_measured = distance_measured * 10;
            distance_measured = distance_measured + (distance[i] - '0');
        }
        i++;
    }
    return distance_measured;
}

//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x5A);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x06);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x03);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x00);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x00);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x0B);
//    delay_ms_main(10);
//
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x5A);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x05);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x05);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x02);
//    delay_ms_main(10);
//    UART_VoidSendByte(UART4, 0x11);
//    delay_ms_main(10);




#ifndef BOOTLOADER_H
#define BOOTLOADER_H


#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "usart.h"
#include "crc.h"
#include "stm32f4xx_hal_flash_ex.h"
#include "stm32f446xx.h"
#define HAL_MAX_SIZE 200


#define CBL_GET_VER_CMD            0x10
#define CBL_GET_HELP_CMD           0x11
#define CBL_GET_CID_CMD            0x12
#define CBL_GO_TO_ADDR_CMD         0x14
#define CBL_FLASH_ERASE_CMD        0x15
#define CBL_MEM_WRITE_CMD          0x16


#define SEND_NACK        0xAB
#define SEND_ACK         0xCD

/* BL GET VERSION */
#define  CBL_VENDOR_ID             100
#define  CBL_SW_MAJOR_VERSION      1
#define  CBL_SW_MINOR_VERSION      0
#define  CBL_SW_PATCH_VERSION      0


#define CRC_VERIFING_FAILED  0X00
#define CRC_VERIFING_PASS    0X01

/*
 * PACKET HOST_BUFFER
 *
 * LENGTH   |   CMD     |   DATA   |    CRC
 * 1byte    |    1byte  |   ?      |    4byte
 *
 */
#define CBL_FLASH_MAX_PAGE_NUMBER    8
#define CBL_FLASH_MASS_ERASE         0xFF


#define INVALID_PAGE_NUMBER          0x00
#define VALID_PAGE_NUMBER            0x01
#define UNSUCCESSFUL_ERASE           0x02
#define SUCCESSFUL_ERASE             0x03

#define HAL_SUCCESSFUL_ERASE         0xFFFFFFFFU

#define ADDRESS_IS_INVALID           0x00
#define ADDRESS_IS_VALID             0x01



///////////////
#define STM32F446_SRAM_SIZE         (128 * 1024)
#define STM32F446_FLASH_SIZE        (512 * 1024)
#define STM32F446_SRAM_END          (SRAM_BASE + STM32F446_SRAM_SIZE)
#define STM32F446_FLASH_END         (FLASH_BASE + STM32F446_FLASH_SIZE)



#define FLASH_PAYLOAD_WRITE_FAILED 0x00
#define FLASH_PAYLOAD_WRITE_PASSED 0x01


typedef enum
{
	BL_NACK = 0,
	BL_ACK
}BL_Status;

uint8_t BL_FeatchHostCommand ();
void BL_SendMessage(char *format,...);
#endif

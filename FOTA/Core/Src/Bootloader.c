/*
 * Bootloader.c
 *
 *  Created on: Dec 27, 2023
 *      Author: ahmed abdelrahman
 */
#include"Bootloader.h"

/* func to recieve data from host */
static uint8_t Host_Buffer[HAL_MAX_SIZE];
static void BL_Send_ACK(uint8_t DataLength);
static void BL_Send_NACK();
static uint32_t BL_CRC_Verfiy(uint8_t *pdata , uint32_t Data_Length , uint32_t HostCRC);


static void BL_Get_Version(uint8_t *Host_Buffer);
static void BL_Get_Help(uint8_t *Host_Buffer);
static void BL_Get_Chip_Identification(uint8_t *Host_Buffer);
//////////////////////////////
static void BL_Write_Data(uint8_t *Host_Buffer);
static uint8_t BL_Address_Varification(uint32_t Addresss);
static uint8_t FlashMemory_Paylaod_Write(uint16_t * pdata,uint32_t StartAddress,uint8_t Payloadlen);


////////
static void BL_Flash_Erase(uint8_t *Host_Buffer);
static uint8_t Perform_Flash_Erase(uint32_t PageAddress, uint8_t page_Number);
//////////////////////


void BL_SendMessage(char *format,...)
{
	char message[100]={0};
	va_list args;
	va_start(args,format);
	vsprintf(message,format,args);
	HAL_UART_Transmit(&huart2 ,(uint8_t*)message  , sizeof(message) , HAL_MAX_DELAY);
}


/*  to check the data recieve from host is recieve or not */
uint8_t BL_FeatchHostCommand ()
{
	/* Default Status */
	BL_Status Status = BL_NACK;
	/* default status Of Uart */
	HAL_StatusTypeDef HAL_Status = HAL_ERROR ;
	/*  variable to store length of data packet */
	uint8_t Data_Length = 0;

	/* to store zero in host buffer in each time i call this func  */
	memset(Host_Buffer,0,HAL_MAX_SIZE);

	/* recieve Data_Length */
	HAL_Status = HAL_UART_Receive(&huart2 ,Host_Buffer  , 1 , HAL_MAX_DELAY);

	if (HAL_Status != HAL_OK)
	{
		Status = BL_NACK;
	}
	else
	{
		Data_Length = Host_Buffer[0];//length i recieve
		HAL_Status = HAL_UART_Receive(&huart2 , &Host_Buffer[1] , Data_Length , HAL_MAX_DELAY);//CMD

		if (HAL_Status != HAL_OK)
			{
				Status = BL_NACK;
			}//end if
			else
			{
               switch(Host_Buffer[1])
               {
               case CBL_GET_VER_CMD:      BL_Get_Version(Host_Buffer);                    break;
               case CBL_GET_HELP_CMD:     BL_Get_Help(Host_Buffer);                       break;
               case CBL_GET_CID_CMD:      BL_Get_Chip_Identification(Host_Buffer);     break;
               case CBL_GO_TO_ADDR_CMD:   BL_Get_Version(Host_Buffer); break;
               case CBL_FLASH_ERASE_CMD: // BL_Flash_Erase(Host_Buffer);    break;
               case CBL_MEM_WRITE_CMD:    BL_Write_Data(Host_Buffer);
      break;
               default : Status = BL_NACK;
               }//end switch
			}//end else
	}//end first else
}//end func



/* check crc verifiy  */
static uint32_t BL_CRC_Verfiy(uint8_t *pdata , uint32_t Data_Length , uint32_t Host_CRC)
{
	uint8_t CRC_Status = CRC_VERIFING_FAILED;//default status
	uint32_t databuffer =0 ;
	uint32_t MCU_CRC =0;

	for (uint8_t counter=0 ; counter < Data_Length ; counter++)
	{
		databuffer = (uint32_t)pdata[counter];
		MCU_CRC = HAL_CRC_Accumulate(&hcrc ,&databuffer , 1);
	}
	__HAL_CRC_DR_RESET(&hcrc);
	if (Host_CRC == MCU_CRC)
	{
		CRC_Status = CRC_VERIFING_PASS;
	}
	else
	{
		CRC_Status = CRC_VERIFING_FAILED;
	}

	return CRC_Status;
}


static void BL_Send_ACK(uint8_t dataLen)
{
	uint8_t ACK_Value[2]={0};
	ACK_Value[0]=SEND_ACK;
	ACK_Value[1]=dataLen;
	HAL_UART_Transmit(&huart2,(uint8_t*)ACK_Value,2,HAL_MAX_DELAY);
}


static void BL_Send_NACK()
{
	uint8_t ACk_Value=SEND_NACK;
	HAL_UART_Transmit(&huart2,&ACk_Value,sizeof(ACk_Value),HAL_MAX_DELAY);
}


static void BL_Get_Version(uint8_t *Host_Buffer)
{
	uint8_t Version[4]={CBL_VENDOR_ID,CBL_SW_MAJOR_VERSION,CBL_SW_MINOR_VERSION,CBL_SW_PATCH_VERSION};
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_Buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_Buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_Verfiy((uint8_t*)&Host_Buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		BL_Send_ACK(4);
		HAL_UART_Transmit(&huart2,(uint8_t*)Version,4,HAL_MAX_DELAY);
		Bootloader_Jump_To_Application();
	}
	else
	{
		BL_Send_NACK();
	}
}

static void BL_Get_Help(uint8_t *Host_Buffer)
{
	uint8_t BL_Support_CMD[6] = {
			CBL_GET_VER_CMD,
			CBL_GET_HELP_CMD,
			CBL_GET_CID_CMD,
			CBL_GO_TO_ADDR_CMD,
			CBL_FLASH_ERASE_CMD,
			CBL_MEM_WRITE_CMD
	};
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_Buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_Buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_Verfiy((uint8_t*)&Host_Buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		BL_Send_ACK(6);
		HAL_UART_Transmit(&huart2,(uint8_t*)BL_Support_CMD,4,HAL_MAX_DELAY);
	}
	else
	{
		BL_Send_NACK();
	}
}

static void BL_Get_Chip_Identification(uint8_t *Host_Buffer)
{
	uint16_t Chip_ID=0;
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_Buffer[0]+1;//PACKET_LENGTH = 6
	CRC_valu = *(uint32_t*)(Host_Buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_Verfiy((uint8_t*)&Host_Buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		Chip_ID = (uint16_t)(DBGMCU->IDCODE & 0x00000FFF);
		BL_Send_ACK(2);
		HAL_UART_Transmit(&huart2,(uint8_t*)&Chip_ID,2,HAL_MAX_DELAY);
	}
	else
	{
		BL_Send_NACK();
	}
}

static uint8_t BL_Address_Varification(uint32_t Addresss)
{
	uint8_t Adress_varfiy=ADDRESS_IS_INVALID;
	if(Addresss>=FLASH_BASE &&Addresss<=STM32F446_FLASH_END)
	{
		Adress_varfiy=ADDRESS_IS_VALID;
	}
	else if(Addresss>=SRAM_BASE &&Addresss<=STM32F446_SRAM_END)
	{
		Adress_varfiy=ADDRESS_IS_VALID;
	}
	else{
		Adress_varfiy=ADDRESS_IS_INVALID;
	}
	return Adress_varfiy;
}









static void BL_Write_Data(uint8_t *Host_buffer)
{
	uint8_t Adress_varfiy=ADDRESS_IS_INVALID;
	uint32_t Address_Host=0;
	uint8_t DataLen=0;
	uint8_t payload_status =FLASH_PAYLOAD_WRITE_FAILED;
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_Buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_Buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_Verfiy((uint8_t*)&Host_Buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		BL_Send_ACK(1);
		Address_Host = *((uint32_t*)&Host_Buffer[2]);
		DataLen = Host_buffer[6];
		Adress_varfiy = BL_Address_Varification(Address_Host);
		if(Adress_varfiy == ADDRESS_IS_VALID)
		{

			//flash
			payload_status = FlashMemory_Paylaod_Write((uint16_t*)&Host_buffer[7],Address_Host,DataLen);
			HAL_UART_Transmit(&huart2,(uint8_t*)&payload_status,1,HAL_MAX_DELAY);
		}
		else
		{
			HAL_UART_Transmit(&huart2,(uint8_t*)&Adress_varfiy,1,HAL_MAX_DELAY);
		}

		//
	}
	else
	{
		BL_Send_NACK();
	}
}



static uint8_t FlashMemory_Paylaod_Write(uint16_t * pdata,uint32_t StartAddress,uint8_t Payloadlen)
{
	uint32_t Address=0;
	uint8_t UpdataAdress=0;
	HAL_StatusTypeDef Hal_status=HAL_ERROR;
	uint8_t payload_status =FLASH_PAYLOAD_WRITE_FAILED;
	HAL_FLASH_Unlock();

	for(uint8_t payload_count=0,UpdataAdress=0;payload_count<Payloadlen/2;payload_count++,UpdataAdress+=2)
	{
		Address =  StartAddress +UpdataAdress;
		Hal_status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,Address,pdata[payload_count]);
		if(Hal_status != HAL_OK)
		{
			payload_status =FLASH_PAYLOAD_WRITE_FAILED;
		}
		else{
			payload_status =FLASH_PAYLOAD_WRITE_PASSED;
		}
	}
	HAL_FLASH_Lock();
	return payload_status;

}


#define FLASH_SECTOR0_BASE_ADDRESS   0x08008000U
  typedef void (*pMainApp)(void);
  typedef void (*Jump_ptr)(void);

  void Bootloader_Jump_To_Application()
  {
  	uint32_t MSP_Value = ((volatile uint32_t)FLASH_SECTOR0_BASE_ADDRESS);
  	uint32_t MainAppAdd = ((volatile uint32_t)(FLASH_SECTOR0_BASE_ADDRESS+4));

  	pMainApp ResetHandler_Address=(pMainApp)MainAppAdd;
  	HAL_RCC_DeInit();
  	__set_MSP(MSP_Value);
  	ResetHandler_Address();

  }



//typedef void (*Function_t)(void);
//Function_t addr_to_call = 0;

void Jump_To_CertainAPP(void)
{

	//#define SCB_VTOR   ((volatile u32)0xE000ED08)
	//SCB_VTOR = 0x08001000;
	//addr_to_call = (Function_t)(0x08001004);
	//addr_to_call();

	//MGPIO_VidSetPinValue(GPIOA,PIN2,1);

}








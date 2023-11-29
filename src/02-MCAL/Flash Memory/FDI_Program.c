/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		29/11/2023										 */
/*	Version :		V01												 */
/*********************************************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"FDI_Config.h"
#include"FDI_Private.h"
#include"FDI_Interface.h"


/************************************************************************************************/
/* Function Name : MFDI_voidEraseSector                                               			*/
/* Description : Erase One sector from flash memory                    							*/
/* Fun. Argument1: FMI_SectorNum_t { FMI_SEC0,FMI_SEC1,FMI_SEC2,FMI_SEC3,FMI_SEC4,FMI_SEC5}     */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MFDI_voidEraseSector(FMI_SectorNum_t A_u8SectorNum)
{
	//1- CHECK THAT BUSY FLAG IS CLEARED
	while(GET_BIT(FMI->SR, FMI_BSY_BIT) == 1);
	
	//2- UNLOCK FLASH CONTROL REG USING KEY REGISTER
	if(GET_BIT(FMI->CR , FMI_LOCK_BIT) == 1)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}
	
	//3-SELECT WHICH SECTOR YOU WANT TO ERASE
	//3-a- CLEAR THE REQUIRED 4 BITS
	FMI->CR &= ~((u32)(0b1111 << 3));
	//3-b- INSERT THE REQUIRED SECTOR
	FMI->CR |= (A_u8SectorNum << 3);

	//4- SET THE SECTOR ERASE BIT
	SET_BIT(FMI->CR, FMI_SER_BIT);

	//5-START THE OPERATION
	SET_BIT(FMI->CR, FMI_STRT_BIT);

	//6-WAIT FOR THE BUSY FLAG TO BE CLEARED
    while(GET_BIT(FMI->SR , FMI_BSY_BIT) == 1);

	//7-CLEAR THE EOP FLAG
    SET_BIT(FMI->SR, FMI_EOP_BIT);

    //8-DESELECT THE ERASE ENABLE
	CLR_BIT(FMI->CR, FMI_SER_BIT);

}



/************************************************************************************************/
/* Function Name : MFDI_voidEraseSector                                               			*/
/* Description : Write data on any address of the flash memory                    				*/
/* Fun. Argument1: u32 A_u32Address     														*/
/* Fun. Argument2: u16 * A_ptrData																*/
/* Fun. Argument3: u16 A_u8DataLength                                   						*/
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MFDI_voidFlashWrite(u32 A_u32Address,u16 * A_ptrData , u16 A_u8DataLength){
	//wait if busy bit is set
	while(GET_BIT(FMI->SR,16)==1);
	//check if authorized for configuration, if not unlock flash register using KEYR
	if(GET_BIT(FMI->CR,31)==1){
		//Unlock flash register using KEYR
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}
  //select element size
  FMI->CR &=0xFFFFFCFF;
  FMI->CR |= 1<<8;
  //activate programming flash
  SET_BIT(FMI->CR,0);
// write Data Array on flash address
  for(u8 i=0;i<A_u8DataLength;i++){

      *((volatile u16 *)A_u32Address)= A_ptrData[i];
      A_u32Address +=2; //as we have half word 2bytes

  	//wait until flashing is finished
  	while(GET_BIT(FMI->SR,16)==1);

  	//clear EOP flag
  	SET_BIT(FMI->SR,0);

	//deactivate programming flash
  	CLR_BIT(FMI->SR,0);


  }
}


/************************************************************************************************/
/* Function Name : MFDI_voidEraseSector                                               			*/
/* Description 	 : Delete all sectors from after the selected sector flash memory                    						*/
/* Fun. Argument1: FMI_SectorNum_t A_u8StartingSector 											*/
/* Fun.	return	 : void                                                     					*/
/************************************************************************************************/
void MFDI_voidEraseAppArea(FMI_SectorNum_t A_u8StartingSector)
{
  for (u8 i = A_u8StartingSector ; i< FLASH_NUM_OF_SECTORS ; i++)
  {
	  MFDI_voidEraseSector(i);
  }
}

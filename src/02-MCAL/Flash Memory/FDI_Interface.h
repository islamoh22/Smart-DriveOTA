/*********************************************************************/
/*	Author	:		Eslam Mohamed									 */
/*	Date	:		29/11/2023										 */
/*	Version :		V01												 */
/*********************************************************************/


#ifndef MCAL_FMI_INTERFACE_H
#define MCAL_FMI_INTERFACE_H

/* Sectors of flash memory */
typedef enum{
	FMI_SEC0 , FMI_SEC1 , FMI_SEC2,
	FMI_SEC3,  FMI_SEC4,  FMI_SEC5
}FMI_SectorNum_t;

/* Maximum parallelism size */
typedef enum{
	FMI_Byte, FMI_HalfWord,
	FMI_Word, FMI_DoubleWord
}FMI_PSIZE_t;


/************************************************************************************************/
/* Function Name : MFDI_voidEraseSector                                                     	*/
/* Description : Erase One sector from flash memory                               				*/
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MFDI_voidEraseSector(FMI_SectorNum_t A_u8SectorNum);

/************************************************************************************************/
/* Function Name : MFDI_voidFlashWrite                                                     		*/
/* Description : Write data on flash memory                              						*/
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MFDI_voidFlashWrite(u32 A_u32Address,u16 * A_ptrData , u16 A_u8DataLength);

/************************************************************************************************/
/* Function Name : MFDI_voidEraseAppArea                                                    	*/
/* Description : Erase all sectors of flash memory                              				*/
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void MFDI_voidEraseAppArea(FMI_SectorNum_t A_u8StartingSector);

#endif 

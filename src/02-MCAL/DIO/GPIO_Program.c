/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This file includes GPIO Drivers implementation STM32F446RE       */
/*  Author      : Ebrahem Mostafa                                                  */
/*  Date        : 22/11/2023                                                       */
/*=================================================================================*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Confg.h"

/*=======================================================================*/
/*==================    Functions Implementation       ==================*/
/*=======================================================================*/
/*******************	GPIO_voidPinInit	           *******************/
/*******************    GPIO_voidSetPinMode            *******************/
/*******************    GPIO_voidSetPinType            *******************/
/*******************    GPIO_voidSetPinSpeed           *******************/
/*******************    GPIO_voidSetPinValueNonAtomic  *******************/
/*******************    GPIO_u8GetPinValue             *******************/
/*******************    GPIO_voidPortInit              *******************/
/*******************    GPIO_voidSetPortMode           *******************/
/*******************    GPIO_voidSetPortType           *******************/
/*******************    GPIO_voidSetPortSpeed          *******************/
/*=======================================================================*/

/************************************************************************************************/
/* Function Name : MGPIO_voidPinInit                                                            */
/* Description   : Initialization of Pin {Mode,Type,Speed}                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument4: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument5: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidPinInit(u8 Copy_u8PortID ,u8 Copy_u8PinID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed){
	MGPIO_voidSetPinMode(Copy_u8PortID,Copy_u8PinID,Copy_u8Mode);
	MGPIO_voidSetPinType(Copy_u8PortID,Copy_u8PinID,Copy_u8Type);
	MGPIO_voidSetPinSpeed(Copy_u8PortID,Copy_u8PinID,Copy_u8Speed);
}

/************************************************************************************************/
/* Function Name : MGPIO_voidSetPinMode                                                          */
/* Description   : Initialization of Pin {Mode}                                                 */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPinMode(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode ){
	switch(Copy_u8PortID){
		case GPIOA:
			switch(Copy_u8Mode){

				case OUTPUT:
					SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2)+1);
					break;
				case INPUT:
					CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2)+1);
					break;
				case ALTERNATE:
					CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
					SET_BIT(GPIOA_MODER,(Copy_u8PinID*2)+1);
					break;
				case ANALOG:
					SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
					SET_BIT(GPIOA_MODER,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;

		case GPIOB:
			switch(Copy_u8Mode){

					case OUTPUT:
						SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
						CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2)+1);
						break;
					case INPUT:
						CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
						CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2)+1);
						break;
					case ALTERNATE:
						CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOB_MODER,(Copy_u8PinID*2)+1);
						break;
					case ANALOG:
						SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOB_MODER,(Copy_u8PinID*2)+1);
						break;
					default:break;
			}
			break;

		case GPIOC:

			switch(Copy_u8Mode){

					case OUTPUT:
						SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
						CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2)+1);
						break;
					case INPUT:
						CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
						CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2)+1);
						break;
					case ALTERNATE:
						CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOC_MODER,(Copy_u8PinID*2)+1);
						break;
					case ANALOG:
						SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOC_MODER,(Copy_u8PinID*2)+1);
						break;
					default:break;
			}
			break;
		default:break;
	}

}

/************************************************************************************************/
/* Function Name : MGPIO_voidSetPinType                                                         */
/* Description   : Initialization of Pin {Type}                                                 */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPinType(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Type ){

	switch(Copy_u8PortID){
		case GPIOA:
			switch(Copy_u8Type){
				case PUSH_PULL:
					CLR_BIT(GPIOA_OTYPER,Copy_u8PinID);
					break;
				case OPEN_DRAIN:
					SET_BIT(GPIOA_OTYPER,Copy_u8PinID);
					break;
				case NO_PULL_UP_DOWM:
					CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_UP:
					SET_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
					SET_BIT(GPIOA_PUPDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
		case GPIOB:
			switch(Copy_u8Type){
				case PUSH_PULL:
					CLR_BIT(GPIOB_OTYPER,Copy_u8PinID);
					break;
				case OPEN_DRAIN:
					SET_BIT(GPIOB_OTYPER,Copy_u8PinID);
					break;
				case NO_PULL_UP_DOWM:
					CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_UP:
					SET_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
					SET_BIT(GPIOB_PUPDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
		case GPIOC:
			switch(Copy_u8Type){
				case PUSH_PULL:
					CLR_BIT(GPIOC_OTYPER,Copy_u8PinID);
					break;
				case OPEN_DRAIN:
					SET_BIT(GPIOC_OTYPER,Copy_u8PinID);
					break;
				case NO_PULL_UP_DOWM:
					CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_UP:
					SET_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2)+1);
					break;
				case PULL_DOWN:
					CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
					SET_BIT(GPIOC_PUPDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
		default :break;

	}
}

/************************************************************************************************/
/* Function Name : MGPIO_voidSetPinSpeed                                                        */
/* Description   : Initialization of Pin {Speed}                                                */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,FAST_SPEED,HIGH_SPEED}                            */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPinSpeed(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Speed ){
	switch(Copy_u8PortID){
		case GPIOA:
			switch(Copy_u8Speed){
				case LOW_SPEED:
					CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case MEDIUM_SPEED:
					SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case FAST_SPEED:
					CLR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
					SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case HIGH_SPEED:
					SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2)+1);
					SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
		case GPIOB:
			switch(Copy_u8Speed){
				case LOW_SPEED:
					CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case MEDIUM_SPEED:
					SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case FAST_SPEED:
					CLR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
					SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case HIGH_SPEED:
					SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2)+1);
					SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
		case GPIOC:
			switch(Copy_u8Speed){
				case LOW_SPEED:
					CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case MEDIUM_SPEED:
					SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
					CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case FAST_SPEED:
					CLR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
					SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				case HIGH_SPEED:
					SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2)+1);
					SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2)+1);
					break;
				default:break;
			}
			break;
	   	 }
		 default: break;
}

/******************************************************************************************/
/* Function Name : MGPIO_voidSetPinValueNonAtomic                                         */
/* Description   : Write value for one bit of the GPIO register                           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return   : void                                                                   */
/******************************************************************************************/
void MGPIO_voidSetPinValueNonAtomic(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value ){
	switch(Copy_u8Value){
		case HIGH:
			switch(Copy_u8PortID){
				case GPIOA: CLR_BIT(GPIOA_ODR,Copy_u8PinID); break;
				case GPIOB: CLR_BIT(GPIOB_ODR,Copy_u8PinID); break;
				case GPIOC: CLR_BIT(GPIOC_ODR,Copy_u8PinID); break;
				default : break;
			}
			break;
		case LOW:
			switch(Copy_u8PortID){
				case GPIOA: SET_BIT(GPIOA_ODR,Copy_u8PinID); break;
				case GPIOB: SET_BIT(GPIOB_ODR,Copy_u8PinID); break;
				case GPIOC: SET_BIT(GPIOC_ODR,Copy_u8PinID); break;
				default : break;
			}
			break;
		default :break;
	}
}
/****************************************************************************/
/* Function Name : MGPIO_u8GetPinValue                                      */
/* Description   : Read pin value from one bit of the Port register         */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                           */
/* Fun. Return   :  unsigned char   { HIGH , LOW }                          */
/****************************************************************************/
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ){
	u8 Local_u8Variable;
	switch(Copy_u8PortID){
		case GPIOA: Local_u8Variable = GET_BIT(GPIOA_IDR,Copy_u8PinID); break;
		case GPIOB: Local_u8Variable = GET_BIT(GPIOB_IDR,Copy_u8PinID); break;
		case GPIOC: Local_u8Variable = GET_BIT(GPIOC_IDR,Copy_u8PinID); break;
	}
	return Local_u8Variable;
}

/************************************************************************************************/
/* Function Name : MGPIO_voidPortInit                                                           */
/* Description   : Initialization of Port {Mode,Type,Speed}                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument4: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidPortInit(u8 Copy_u8PortID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed){
	MGPIO_voidSetPortMode(Copy_u8PortID,Copy_u8Mode);
	MGPIO_voidSetPortSpeed(Copy_u8PortID,Copy_u8Speed);
	MGPIO_voidSetPortType(Copy_u8PortID,Copy_u8Type);
}

/************************************************************************************************/
/* Function Name : MGPIO_voidSetPortMode                                                        */
/* Description   : Initialization of Port {Mode}                                                */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPortMode(u8 Copy_u8PortID , u8 Copy_u8Mode ){
	for(u8 pin = 0 ; pin < 16 ; pin++ ){
		MGPIO_voidSetPinMode(Copy_u8PortID,pin,Copy_u8Mode);
	}
}
/************************************************************************************************/
/* Function Name : MGPIO_voidSetPortType                                                        */
/* Description   : Initialization of Port {Type}                                                */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPortType(u8 Copy_u8PortID , u8 Copy_u8Type ){
	for(u8 pin = 0 ; pin < 16 ; pin++ ){
		MGPIO_voidSetPinType(Copy_u8PortID,pin,Copy_u8Type);
	}
}
/************************************************************************************************/
/* Function Name : MGPIO_voidSetPortSpeed                                                       */
/* Description   : Initialization of Port {Speed}                                               */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void MGPIO_voidSetPortSpeed(u8 Copy_u8PortID , u8 Copy_u8Speed ){
	for(u8 pin = 0 ; pin < 16 ; pin++ ){
			MGPIO_voidSetPinSpeed(Copy_u8PortID,pin,Copy_u8Speed);
		}
}

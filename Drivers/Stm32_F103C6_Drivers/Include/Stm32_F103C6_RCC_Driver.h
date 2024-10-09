/*
 * Stm32_F103C6_RCC_Driver.h
 *
 *  Created on: 8 Oct 2024
 *      Author: minak
 */

#ifndef INCLUDE_STM32_F103C6_RCC_DRIVER_H_
#define INCLUDE_STM32_F103C6_RCC_DRIVER_H_

//-------------------------
//Includes
//-------------------------
#include "Stm32f103x6.h"


#define HSI_RC_Clk	(uint32_t)(8000000)
#define HSE_Clk		(uint32_t)(16000000)


/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/
uint32_t MCAL_GetSYSCLK_Freq(void);
uint32_t MCAL_GetHCLK_Freq(void);
uint32_t MCAL_GetPCLK1_Freq(void);
uint32_t MCAL_GetPCLK2_Freq(void);

#endif /* INCLUDE_STM32_F103C6_RCC_DRIVER_H_ */

/*
 * Stm32_F103C6_RCC_Driver.c
 *
 *  Created on: 8 Oct 2024
 *      Author: minak
 */


//-----------------
//Includes
//-----------------
#include "Stm32_F103C6_RCC_Driver.h"

//-----------------
//Global Values
//-----------------
uint8_t APBprescalerTable[8]={0,0,0,0,1,2,3,4};
uint8_t AHBprescalerTable[16]={0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};

/**================================================================
 * @Fn				-MCAL_GetSYSCLK_Freq
 * @brief 			-Return the clock Frequency of the system
 * @param [in] 		-none
 * @retval 			-clock Frequency of the system
 * Note				-
 */

uint32_t MCAL_GetSYSCLK_Freq(void)
{
//	 Bits 3:2 SWS: System clock switch status
//	 Set and cleared by hardware to indicate which clock source is used as system clock.
//	 00: HSI oscillator used as system clock
//	 01: HSE oscillator used as system clock
//	 10: PLL used as system clock
//	 11: not applicable
	switch((RCC->CFGR >> 2) & 0b11)
	{
	case(0):
			return HSI_RC_Clk;
			break;
	case(1):
			return HSE_Clk;
			break;
	case(2):
			return HSE_Clk;
			break;
	default:
		return HSE_Clk;
	}
}

/**================================================================
 * @Fn				-MCAL_GetHCLK_Freq
 * @brief 			-Return the clock Frequency after the AHB Prescaler
 * @param [in] 		-none
 * @retval 			-clock Frequency after the AHB Prescaler
 * Note				-
 */

uint32_t MCAL_GetHCLK_Freq(void)
{
//	 Bits 7:4HPRE: AHB prescaler
//	 Set and cleared by software to control the division factor of the AHB clock.
//	 0xxx: SYSCLK not divided
//	 1000: SYSCLK divided by 2
//	 1001: SYSCLK divided by 4
//	 1010: SYSCLK divided by 8
//	 1011: SYSCLK divided by 16
//	 1100: SYSCLK divided by 64
//	 1101: SYSCLK divided by 128
//	 1110: SYSCLK divided by 256
//	 1111: SYSCLK divided by 512
	return (MCAL_GetSYSCLK_Freq() >> AHBprescalerTable[(RCC->CFGR >> 4) & 0xF]);
}

/**================================================================
 * @Fn				-MCAL_GetPCLK1_Freq
 * @brief 			-Return the clock Frequency after the APB1 Prescaler
 * @param [in] 		-none
 * @retval 			-clock Frequency after the APB1 Prescaler
 * Note				-
 */

uint32_t MCAL_GetPCLK1_Freq(void)
{
//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//	 Set and cleared by software to control the division factor of the APB low-speed clock
//	(PCLK1).
//	 Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//	 0xx: HCLK not divided
//	 100: HCLK divided by 2
//	 101: HCLK divided by 4
//	 110: HCLK divided by 8
//	 111: HCLK divided by 16
	return (MCAL_GetHCLK_Freq() >> APBprescalerTable[(RCC->CFGR >> 8) & 0b111]);
}

/**================================================================
 * @Fn				-MCAL_GetPCLK2_Freq
 * @brief 			-Return the clock Frequency after the APB2 Prescaler
 * @param [in] 		-none
 * @retval 			-clock Frequency after the APB2 Prescaler
 * Note				-
 */

uint32_t MCAL_GetPCLK2_Freq(void)
{
//	 Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//	 Set and cleared by software to control the division factor of the APB high-speed clock
//	(PCLK2).
//	 0xx: HCLK not divided
//	 100: HCLK divided by 2
//	 101: HCLK divided by 4
//	 110: HCLK divided by 8
//	 111: HCLK divided by 16
	return (MCAL_GetHCLK_Freq() >> APBprescalerTable[(RCC->CFGR >> 11) & 0b111]);
}

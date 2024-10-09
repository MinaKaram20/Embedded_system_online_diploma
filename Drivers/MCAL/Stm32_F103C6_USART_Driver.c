/*
 * Stm32_F103C6_USART_Driver.c
 *
 *  Created on: 8 Oct 2024
 *      Author: minak
 */


//-----------------------------
//Includes
//-----------------------------

#include "Stm32_F103C6_USART_Driver.h"

void (* GP_IRQ_CallBack[3])(void);

/**================================================================
 * @Fn				-MCAL_UART_Init
 * @brief 			-Initialize the specified USARTx according to the configuration in conf
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @param [in] 		-conf is a pointer points to the struct that holds the configuration of the USART
 * @retval 			-none
 * Note				-
 */

void MCAL_UART_Init(USART_Typedef* USARTx , USART_conf * conf)
{
	uint32_t pclk,BRR;
	uint8_t IRQ;
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_EN();
		IRQ = 0;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_EN();
		IRQ = 1;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_EN();
		IRQ = 2;
	}

	//	Enable the USART by writing the UE bit in USART_CR1 register to 1.
	USARTx->CR1 |= 1<<13;

	//	Program the M bit in USART_CR1 to define the word length.
	USARTx->CR1 |= conf->PayLoad;

	//	Program the number of stop bits in USART_CR2.
	USARTx->CR2 |= conf->StopBits;

	//	Enable the mode of USART TX/RX in USART_CR1.
	USARTx->CR1 |= conf->USART_MODE;

	//	Enable CTS/RTS in USART_CR3.
	USARTx->CR3 |= conf->HwFlowCtrl;

	//	Enable the Parity in USART_CR1.
	USARTx->CR1 |= conf->Parity;

	//	Select the desired baud rate using the USART_BRR register.

	if(USARTx == USART1)
	{
		pclk = MCAL_GetPCLK2_Freq();
	}
	else
	{
		pclk = MCAL_GetPCLK1_Freq();
	}

	BRR = USART_BRR_Register(pclk,conf->BaudRate);

	USARTx->BRR = BRR;

	if(conf->IRQ_EN !=USART_IRQ_EN_NONE)
	{
		USARTx->CR1 |= conf->IRQ_EN;
		if(USARTx == USART1)
		{
			NVIC_IRQ37_USART1_Enable;
		}
		else if(USARTx == USART2)
		{
			NVIC_IRQ38_USART2_Enable;
		}
		else if(USARTx == USART3)
		{
			NVIC_IRQ39_USART3_Enable;
		}
		GP_IRQ_CallBack[IRQ] = conf->P_IRQ_CallBack;
	}

}

/**================================================================
 * @Fn				-MCAL_UART_DeInit
 * @brief 			-Restet the specified USARTx
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @retval 			-none
 * Note				-
 */
void MCAL_UART_DeInit(USART_Typedef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_Disable();
		NVIC_IRQ37_USART1_Disable;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_Disable();
		NVIC_IRQ38_USART2_Disable;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_Disable();
		NVIC_IRQ39_USART3_Disable;
	}
}

/**================================================================
 * @Fn				-MCAL_UART_GPIO_Set_Pins
 * @brief 			-Set pin in GPIO to be as USART
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @retval 			-none
 * Note				-
 */
void MCAL_UART_GPIO_Set_Pins(USART_Typedef* USARTx, uint16_t HwFlowCtrl)
{
	GPIO_PINConfig_t PIN;
	if(USARTx == USART1)
	{
		//PA9 TX
		PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
		PIN.GPIO_PIN_Number = GPIO_PIN_9;
		MCAL_GPIO_Init(GPIOA, &PIN);

		//PA10 RX
		PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		PIN.GPIO_PIN_Number = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOA,&PIN);

		//PA11 CTS
		if(HwFlowCtrl == USART_HwFlowCtrl_CTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_11;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}

		//PA12 RTS
		if(HwFlowCtrl == USART_HwFlowCtrl_RTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			PIN.GPIO_PIN_Number = GPIO_PIN_12;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}
	}
	else if(USARTx == USART2)
	{
		//PA2 TX
		PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
		PIN.GPIO_PIN_Number = GPIO_PIN_2;
		MCAL_GPIO_Init(GPIOA, &PIN);

		//PA3 RX
		PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		PIN.GPIO_PIN_Number = GPIO_PIN_3;
		MCAL_GPIO_Init(GPIOA, &PIN);

		//PA0 CTS
		if(HwFlowCtrl == USART_HwFlowCtrl_CTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_0;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}

		//PA1 RTS
		if(HwFlowCtrl == USART_HwFlowCtrl_RTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			PIN.GPIO_PIN_Number = GPIO_PIN_1;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}
	}
	else if(USARTx == USART3)
	{
		//PB10 TX
		PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
		PIN.GPIO_PIN_Number = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOB, &PIN);

		//PB11 RX
		PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		PIN.GPIO_PIN_Number = GPIO_PIN_11;
		MCAL_GPIO_Init(GPIOB, &PIN);

		//PB13 CTS
		if(HwFlowCtrl == USART_HwFlowCtrl_CTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_13;
			MCAL_GPIO_Init(GPIOB, &PIN);
		}

		//PB14 RTS
		if(HwFlowCtrl == USART_HwFlowCtrl_RTS || HwFlowCtrl == USART_HwFlowCtrl_CTS_RTS)
		{
			PIN.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			PIN.GPIO_PIN_Number = GPIO_PIN_14;
			MCAL_GPIO_Init(GPIOB, &PIN);
		}
	}
}


void MCAL_UART_GPIO_Set_Pins_NO_CTS_RTS(USART_Typedef* USARTx )
{
	MCAL_UART_GPIO_Set_Pins(USARTx,USART_HwFlowCtrl_NONE);
}
void MCAL_UART_GPIO_Set_Pins_CTS_RTS(USART_Typedef* USARTx )
{
	MCAL_UART_GPIO_Set_Pins(USARTx,USART_HwFlowCtrl_CTS_RTS);
}
void MCAL_UART_GPIO_Set_Pins_CTS(USART_Typedef* USARTx )
{
	MCAL_UART_GPIO_Set_Pins(USARTx,USART_HwFlowCtrl_CTS);
}
void MCAL_UART_GPIO_Set_Pins_RTS(USART_Typedef* USARTx )
{
	MCAL_UART_GPIO_Set_Pins(USARTx,USART_HwFlowCtrl_RTS);
}

/**================================================================
 * @Fn				-MCAL_UART_SendData
 * @brief 			-Send the data
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @param [in] 		-data is a pointer points to the Buffer that holds the data that will be sent
 * @param [in] 		-Polling is an enum that will make the function waits till the TXE is 1
 * @retval 			-none
 * Note				-
 */


void MCAL_UART_SendData(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling,uint16_t Data_size)
{
	if(Polling == enable)
	{
		while(!(USARTx->SR & 1<<7))
		{
		}
	}
	if(Data_size == USART_PayLoad_8B)
	{
		USARTx->DR = (*data & (uint8_t)0xFF);
	}
	else if(Data_size == USART_PayLoad_9B)
	{
		USARTx->DR = (*data & (uint16_t)0x1FF);
	}
}

void MCAL_UART_SendData_8B(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_SendData(USARTx,data,Polling,USART_PayLoad_8B);
}
void MCAL_UART_SendData_9B(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_SendData(USARTx,data,Polling,USART_PayLoad_9B);
}

/**================================================================
 * @Fn				-MCAL_UART_ReceiveData
 * @brief 			-Receive the data
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @param [in] 		-data is a pointer points to the Buffer that holds the data that will be sent
 * @param [in] 		-Polling is an enum that will make the function waits till the RXNE is 1
 * @retval 			-none
 * Note				-
 */
void MCAL_UART_ReceiveData(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling,uint16_t Data_size,uint16_t Parity)
{
	if(Polling == enable)
	{
		while(!(USARTx->SR & 1<<5))
		{
		}
	}
	if(Data_size == USART_PayLoad_8B)
	{
		if(Parity == USART_Parity_Disable)
		{
			*data = USARTx->DR & 0xFF;
		}
		else
		{
			*data = USARTx->DR & 0x7F;
		}
	}
	else if(Data_size == USART_PayLoad_9B)
	{
		if(Parity == USART_Parity_Disable)
		{
			*data = USARTx->DR & 0x1FF;
		}
		else
		{
			*data = USARTx->DR & 0xFF;
		}
	}
}

void MCAL_UART_ReceiveData_8B_NO_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_ReceiveData(USARTx,data,Polling,USART_PayLoad_8B,USART_Parity_Disable);
}
void MCAL_UART_ReceiveData_8B_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_ReceiveData(USARTx,data,Polling,USART_PayLoad_8B,USART_Parity_Even);
}
void MCAL_UART_ReceiveData_9B_NO_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_ReceiveData(USARTx,data,Polling,USART_PayLoad_9B,USART_Parity_Disable);
}
void MCAL_UART_ReceiveData_9B_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling)
{
	MCAL_UART_ReceiveData(USARTx,data,Polling,USART_PayLoad_9B,USART_Parity_Odd);
}

/**================================================================
 * @Fn				-MCAL_UART_WAIT_TC
 * @brief 			-Waits till transmission is complete
 * @param [in] 		-USARTx : where x can be (1,2,3) to select the USART Peripheral
 * @retval 			-none
 * Note				-
 */
void MCAL_UART_WAIT_TC(USART_Typedef* USARTx)
{
	while(!(USARTx->SR & 1<<7));
}

void USART1_IRQHandler(void)
{
	GP_IRQ_CallBack[0]();
}
void USART2_IRQHandler(void)
{
	GP_IRQ_CallBack[1]();
}

void USART3_IRQHandler(void)
{
	GP_IRQ_CallBack[2]();
}

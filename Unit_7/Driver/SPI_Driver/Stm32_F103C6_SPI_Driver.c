/*
 * Stm32_F103C6_SPI_Driver.c
 *
 *  Created on: 19 Oct 2024
 *      Author: minak
 */


#include "Stm32_F103C6_SPI_Driver.h"

SPI_Config_t *G_SPI_Config[2] = {NULL, NULL};


/**================================================================
 * @Fn				-MCAL_SPI_Init
 * @brief 			-Initialize the SPI
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @param [in] 		-SPI_Config is a pointer to the struct that have the config
 * @retval 			-none
 * Note
 * ================================================================			-
 */

void MCAL_SPI_Init(SPI_Typedef *SPIx, SPI_Config_t* SPI_Config)
{
	uint16_t temp_CR1=0,temp_CR2=0;

	if(SPIx == SPI1)
	{
		G_SPI_Config[0]=SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		G_SPI_Config[1]=SPI_Config;
		RCC_SPI2_CLK_EN();
	}

//	 Bit 6 SPE: SPI enable
//	 0: Peripheral disabled
//	 1: Peripheral enabled
	temp_CR1 |= 1<<6;

	temp_CR1 |= SPI_Config->BaudRate_Prescaler;
	temp_CR1 |= SPI_Config->Data_Frame;
	temp_CR1 |= SPI_Config->SPI_Clk_Phase_Polarity;
	temp_CR1 |= SPI_Config->SPI_Comm_Mode;
	temp_CR1 |= SPI_Config->SPI_Operation;

	if(SPI_Config->SPI_NSS_Mode == SPI_NSS_Mode_Hard_Master_SS_Output_Enabled)
	{
		temp_CR2 |= SPI_Config->SPI_NSS_Mode;
	}
	else if(SPI_Config->SPI_NSS_Mode == SPI_NSS_Mode_Hard_Master_SS_output_disable)
	{
		temp_CR2 &= SPI_Config->SPI_NSS_Mode;
	}
	else
	{
		temp_CR1 |= SPI_Config->SPI_NSS_Mode;
	}

	if(SPI_Config->IRQ_Enable != SPI_IRQ_Disabled)
	{
		temp_CR2 |= SPI_Config->IRQ_Enable;
		if(SPIx ==SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else if(SPIx ==SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}

	SPIx->CR1 = temp_CR1;
	SPIx->CR2 = temp_CR2;
}
/**================================================================
 * @Fn				-MCAL_SPI_DeInit
 * @brief 			-Reset a specific SPI
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @retval 			-none
 * Note
 * ================================================================			-
 */
void MCAL_SPI_DeInit(SPI_Typedef *SPIx)
{
	if(SPIx == SPI1)
	{
		RCC_SPI1_CLK_Disable();
		NVIC_IRQ35_SPI1_Disable;
	}
	else if(SPIx == SPI2)
	{
		RCC_SPI2_CLK_Disable();
		NVIC_IRQ36_SPI2_Disable;
	}
}

/**================================================================
 * @Fn				-MCAL_SPI_GPIO_Set_Pins
 * @brief 			-Configure the GPIO ports to work as SPI
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @retval 			-none
 * Note
 * ================================================================			-
 */
void MCAL_SPI_GPIO_Set_Pins(SPI_Typedef *SPIx)
{
	GPIO_PINConfig_t PIN;
	if(SPIx == SPI1)
	{
		/*
			SPI1_NSS 	PA4
			SPI1_SCK 	PA5
			SPI1_MISO 	PA6
			SPI1_MOSI	PA7
		*/
		if(G_SPI_Config[0]->SPI_Operation == SPI_Operation_Master)
		{
			//NSS
			switch(G_SPI_Config[0]->SPI_NSS_Mode)
			{
			case SPI_NSS_Mode_Hard_Master_SS_output_disable :
				PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				PIN.GPIO_PIN_Number = GPIO_PIN_4;
				MCAL_GPIO_Init(GPIOA, &PIN);
				break;
			case SPI_NSS_Mode_Hard_Master_SS_Output_Enabled :
				PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
				PIN.GPIO_PIN_Number = GPIO_PIN_4;
				PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
				MCAL_GPIO_Init(GPIOA, &PIN);
				break;
			}
			//SCK
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_5;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PIN);

			//MISO
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_6;
			MCAL_GPIO_Init(GPIOA, &PIN);

			//MOSI
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_7;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}
		else
		{
			//SLAVE
			//NSS
			if(G_SPI_Config[0]->SPI_NSS_Mode == SPI_NSS_Mode_Hard_Slave)
			{
				PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				PIN.GPIO_PIN_Number = GPIO_PIN_4;
				MCAL_GPIO_Init(GPIOA, &PIN);
			}

			//SCK
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_5;
			MCAL_GPIO_Init(GPIOA, &PIN);

			//MISO
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_6;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PIN);

			//MOSI
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_7;
			MCAL_GPIO_Init(GPIOA, &PIN);
		}
	}
	else if(SPIx == SPI2)
	{
		/*
		SPI2_NSS 	PB12
		SPI2_SCK 	PB13
		SPI2_MISO 	PB14
		SPI2_MOSI	PB15
		*/
		if(G_SPI_Config[0]->SPI_Operation == SPI_Operation_Master)
		{
			//NSS
			switch(G_SPI_Config[0]->SPI_NSS_Mode)
			{
			case SPI_NSS_Mode_Hard_Master_SS_output_disable :
				PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				PIN.GPIO_PIN_Number = GPIO_PIN_12;
				MCAL_GPIO_Init(GPIOB, &PIN);
				break;
			case SPI_NSS_Mode_Hard_Master_SS_Output_Enabled :
				PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
				PIN.GPIO_PIN_Number = GPIO_PIN_12;
				PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
				MCAL_GPIO_Init(GPIOB, &PIN);
				break;
			}
			//SCK
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_13;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PIN);

			//MISO
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_14;
			MCAL_GPIO_Init(GPIOB, &PIN);

			//MOSI
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_15;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PIN);
		}
		else
		{
			//SLAVE
			//NSS
			if(G_SPI_Config[0]->SPI_NSS_Mode == SPI_NSS_Mode_Hard_Slave)
			{
				PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				PIN.GPIO_PIN_Number = GPIO_PIN_12;
				MCAL_GPIO_Init(GPIOB, &PIN);
			}

			//SCK
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_13;
			MCAL_GPIO_Init(GPIOB, &PIN);

			//MISO
			PIN.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			PIN.GPIO_PIN_Number = GPIO_PIN_14;
			PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PIN);

			//MOSI
			PIN.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			PIN.GPIO_PIN_Number = GPIO_PIN_15;
			MCAL_GPIO_Init(GPIOB, &PIN);
		}
	}

}

/**================================================================
 * @Fn				-MCAL_SPI_SendData
 * @brief 			-Send Data
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @param [in]		-data_buffer is a Pointer holds the data which will be sent
 * @param [in]		-Polling an enum to know if the function will work with Polling or Interrupt
 * @retval 			-none
 * Note
 * ================================================================			-
 */
void MCAL_SPI_SendData(SPI_Typedef *SPIx, uint16_t *data_buffer,Polling_mechanism Polling)
{
	if(Polling == enable)
	{
		while(!(SPIx->SR & 1<<1));
	}
	SPIx->DR = *data_buffer;
}
/**================================================================
 * @Fn				-MCAL_SPI_ReceiveData
 * @brief 			-Receive Data
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @param [Out]		-data_buffer is a Pointer holds the data which will be Received
 * @param [in]		-Polling an enum to know if the function will work with Polling or Interrupt
 * @retval 			-none
 * Note
 * ================================================================			-
 */
void MCAL_SPI_ReceiveData(SPI_Typedef *SPIx, uint16_t *data_buffer ,Polling_mechanism Polling)
{
	if(Polling == enable)
	{
		while(!(SPIx->SR & 1<<0));
	}
	*data_buffer = SPIx->DR;
}

/**================================================================
 * @Fn				-MCAL_SPI_TX_RX
 * @brief 			-Send and Receive at same time
 * @param [in] 		-SPIx is a pointer to the choosen SPI
 * @param [In/Out]	-data_buffer is a Pointer that holds the data which will be sent as Input,
 * 					 and after will hold the data received to be Output.
 * @param [in]		-Polling an enum to know if the function will work with Polling or Interrupt
 * @retval 			-none
 * Note
 * ================================================================			-
 */
void MCAL_SPI_TX_RX(SPI_Typedef *SPIx, uint16_t *data_buffer,Polling_mechanism Polling)
{
	if(Polling == enable)
	{
		while(!(SPIx->SR & 1<<1));
	}
	SPIx->DR = *data_buffer;
	if(Polling == enable)
	{
		while(!(SPIx->SR & 1<<0));
	}
	*data_buffer = SPIx->DR;
}

void SPI1_IRQHandler(void)
{
	IRQ_SOURCE irq;
	irq.TXE = (SPI1->SR >> 1 & 0x01);
	irq.RXNE = (SPI1->SR & 0x01);
	irq.ERRI = (SPI1->SR >> 4 & 0x01);
	G_SPI_Config[0]->P_Func_Call_Back(irq);
}

void SPI2_IRQHandler(void)
{
	IRQ_SOURCE irq;
	irq.TXE = (SPI2->SR >> 1 & 0x01);
	irq.RXNE = (SPI2->SR & 0x01);
	irq.ERRI = (SPI2->SR >> 4 & 0x01);
	G_SPI_Config[1]->P_Func_Call_Back(irq);
}

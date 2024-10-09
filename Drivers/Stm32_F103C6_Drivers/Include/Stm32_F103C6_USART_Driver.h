/*
 * Stm32_F103C6_USART_Driver.h
 *
 *  Created on: 8 Oct 2024
 *      Author: minak
 */

#ifndef INCLUDE_STM32_F103C6_USART_DRIVER_H_
#define INCLUDE_STM32_F103C6_USART_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32f103x6.h"
#include "Stm32_F103C6_USART_Driver.h"
#include "Stm32_F103C6_RCC_Driver.h"


//-----------------------------
//Macro Function
//-----------------------------

#define USARTDIV(_PCLK_,_BAUD_)						(uint32_t)(_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)				(uint32_t)((25*_PCLK_)/(4*_BAUD_))
#define DIV_MANTISSA_MUL100(_PCLK_,_BAUD_)			(uint32_t)(USARTDIV(_PCLK_,_BAUD_)*100)
#define DIV_MANTISSA(_PCLK_,_BAUD_)					(uint32_t)(USARTDIV(_PCLK_,_BAUD_))
#define DIV_FRACTION(_PCLK_,_BAUD_)					(uint32_t)(((USARTDIV_MUL100(_PCLK_,_BAUD_) - DIV_MANTISSA_MUL100(_PCLK_,_BAUD_))*16)/100)
#define USART_BRR_Register(_PCLK_,_BAUD_)			(uint32_t)((DIV_MANTISSA(_PCLK_,_BAUD_) << 4) |  (DIV_FRACTION(_PCLK_,_BAUD_) & 0xF))

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{

	uint8_t	USART_MODE;					//Specifies the TX/RX MODE.
										//This Parameter must be a value of @ref USART_MODE_define

	uint32_t BaudRate;					//Specifies the BaudRate.
										//This Parameter must be a value of @ref USART_BaudRate_define

	uint16_t PayLoad;					//Specifies number of data bits.
										//This Parameter must be a value of @ref USART_PayLoad_define

	uint16_t StopBits;					//Specifies number of stop bits.
										//This Parameter must be a value of @ref USART_StopBits_define

	uint16_t Parity;					//Specifies the type of parity.
										//This Parameter must be a value of @ref USART_Parity_define

	uint16_t HwFlowCtrl;				//Specifies whether the hardware flow mode is enabled or disabled.
										//This Parameter must be a value of @ref USART_HwFlowCtrl_define

	uint16_t IRQ_EN;					//Enable or Disable the USART Interrupt.
										//This Parameter must be a value of @ref USART_IRQ_EN_define
	void (* P_IRQ_CallBack)(void);
}USART_conf;

typedef enum{
	enable,
	disable
}Polling_mechanism;

//==================================================================================


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref USART_MODE_define

#define USART_MODE_TX		(uint8_t)(1<<3);
#define USART_MODE_RX		(uint8_t)(1<<2);
#define USART_MODE_TX_RX	(uint8_t)(3<<2);

//@ref USART_BaudRate_define

#define USART_BaudRate_2400			2400
#define USART_BaudRate_9600			9600
#define USART_BaudRate_19200		19200
#define USART_BaudRate_57600		57600
#define USART_BaudRate_115200		115200
#define USART_BaudRate_230400		230400
#define USART_BaudRate_460800		460800
#define USART_BaudRate_921600		921600
#define USART_BaudRate_2250000		2250000
#define USART_BaudRate_4500000		4500000

//@ref USART_PayLoad_define

//Bit 12 M: Word length
//This bit determines the word length. It is set or cleared by software.
//0: 1 Start bit, 8 Data bits, n Stop bit
//1: 1 Start bit, 9 Data bits, n Stop bit

#define USART_PayLoad_8B	(uint16_t)(0)
#define USART_PayLoad_9B	(uint16_t)(1<<12)

//@ref USART_StopBits_define

//Bits 13:12 STOP: STOP bits
// These bits are used for programming the stop bits.
// 00: 1 Stop bit
// 01: 0.5 Stop bit
// 10: 2 Stop bits
// 11: 1.5 Stop bit

#define USART_StopBits_1B			(uint16_t)(0)
#define USART_StopBits_HALF_B		(uint16_t)(1<<12)
#define USART_StopBits_2B			(uint16_t)(2<<12)
#define USART_StopBits_1_HALF_B		(uint16_t)(3<<12)

//@ref USART_Parity_define

//Bit 10 PCE: Parity control enable
//This bit selects the hardware parity control (generation and detection). When the parity
//control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
//if M=0) and parity is checked on the received data. This bit is set and cleared by software.
//Once it is set, PCE is active after the current byte (in reception and in transmission).
//0: Parity control disabled
//1: Parity control enabled
//Bit 9 PS: Parity selection
//This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
//bit set). It is set and cleared by software. The parity will be selected after the current byte.
//0: Even parity
//1: Odd parity

#define USART_Parity_Disable	(uint16_t)(0)
#define USART_Parity_Even		(uint16_t)(1<<10)
#define USART_Parity_Odd		(uint16_t)(3<<9)

//@ref USART_HwFlowCtrl_define

//Bit 9 CTSE: CTS enable
//0: CTS hardware flow control disabled
//1: CTS mode enabled
//Bit 8 RTSE: RTS enable
//0: RTS hardware flow control disabled
//1: RTS interrupt enabled

#define USART_HwFlowCtrl_NONE		(uint16_t)(0)
#define USART_HwFlowCtrl_CTS		(uint16_t)(1<<9)
#define USART_HwFlowCtrl_RTS		(uint16_t)(1<<8)
#define USART_HwFlowCtrl_CTS_RTS	(uint16_t)(3<<8)

//@ref USART_IRQ_EN_define

#define USART_IRQ_EN_NONE	(uint16_t)(0)
#define USART_IRQ_EN_TXE	(uint16_t)(1<<7)
#define USART_IRQ_EN_TC		(uint16_t)(1<<6)
#define USART_IRQ_EN_RXNE	(uint16_t)(1<<5)
#define USART_IRQ_EN_PE		(uint16_t)(1<<8)



//=============================================================

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_UART_Init(USART_Typedef* USARTx , USART_conf * conf);
void MCAL_UART_DeInit(USART_Typedef* USARTx);
void MCAL_UART_GPIO_Set_Pins_NO_CTS_RTS(USART_Typedef* USARTx );
void MCAL_UART_GPIO_Set_Pins_CTS_RTS(USART_Typedef* USARTx );
void MCAL_UART_GPIO_Set_Pins_CTS(USART_Typedef* USARTx );
void MCAL_UART_GPIO_Set_Pins_RTS(USART_Typedef* USARTx );
void MCAL_UART_SendData_8B(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_SendData_9B(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_ReceiveData_8B_NO_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_ReceiveData_8B_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_ReceiveData_9B_NO_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_ReceiveData_9B_Parity(USART_Typedef* USARTx, uint16_t *data, Polling_mechanism Polling);
void MCAL_UART_WAIT_TC(USART_Typedef* USARTx);


#endif /* INCLUDE_STM32_F103C6_USART_DRIVER_H_ */

/*
 * Stm32_F103C6_SPI_Driver.h
 *
 *  Created on: 19 Oct 2024
 *      Author: minak
 */

#ifndef INCLUDE_STM32_F103C6_SPI_DRIVER_H_
#define INCLUDE_STM32_F103C6_SPI_DRIVER_H_

#include "Stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"


typedef struct
{
	uint8_t TXE		:1;
	uint8_t RXNE	:1;
	uint8_t ERRI	:1;
	uint8_t RES		:5;

}IRQ_SOURCE;

typedef struct {
	uint16_t SPI_Comm_Mode;				//Specifies the Full/Half-duplex or Simplex MODE.
										//This Parameter must be a value of @ref SPI_Comm_Mode_define

	uint16_t Data_Frame;				//Specifies the 8/16 bit and  either MSB-first or LSB-first MODE.
										//This Parameter must be a value of @ref SPI_Data_Frame_define

	uint16_t SPI_NSS_Mode;				//Specifies the NSS MODE Software or Hardware.
										//This Parameter must be a value of @ref SPI_NSS_Mode_define

	uint8_t SPI_Operation;				//Specifies the Master or Slave MODE.
										//This Parameter must be a value of @ref SPI_Operation_define

	uint8_t SPI_Clk_Phase_Polarity;		//This Parameter must be a value of @ref SPI_Clk_Phase_Polarity_define

	uint8_t BaudRate_Prescaler;			//This Parameter must be a value of @ref SPI_BaudRate_Prescaler_define

	uint8_t IRQ_Enable;					//This Parameter must be a value of @ref SPI_IRQ_Enable_define

	void (*P_Func_Call_Back)(IRQ_SOURCE IRQ);

}SPI_Config_t;



//==================================================================================


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_Comm_Mode_define

//Bit 15 BIDIMODE: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected
//Note: This bit is not used in I2S mode
//Bit 14 BIDIOE: Output enable in bidirectional mode
//This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
//0: Output disabled (receive-only mode)
//1: Output enabled (transmit-only mode)
//Bit 10RXONLY: Receive only
//This bit combined with the BIDImode bit selects the direction of transfer in 2-line
//unidirectional mode. This bit is also useful in a multislave system in which this particular
//slave is not accessed, the output from the accessed slave is not corrupted.
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive-only mode)

#define SPI_Comm_Mode_2Lines			(uint16_t)(0)
#define SPI_Comm_Mode_2Lines_RXonly		(uint16_t)(1<<10)
#define SPI_Comm_Mode_1Line_RXonly		(uint16_t)(2<<14)
#define SPI_Comm_Mode_1Line_TXonly		(uint16_t)(3<<14)

//@ref SPI_Data_Frame_define

//Bit 11 DFF: Data frame format
//0: 8-bit data frame format is selected for transmission/reception
//1: 16-bit data frame format is selected for transmission/reception
//Bit 7 LSBFIRST: Frame format
//0: MSB transmitted first
//1: LSB transmitted first

#define SPI_Data_Frame_8Bit_MSB			(uint16_t)(0)
#define SPI_Data_Frame_8Bit_LSB			(uint16_t)(1<<7)
#define SPI_Data_Frame_16Bit_MSB		(uint16_t)(1<<11)
#define SPI_Data_Frame_16Bit_LSB		(uint16_t)((1<<11) | (1<<7))

//@ref SPI_Operation_define

//Bit 2MSTR: Master selection
//0: Slave configuration
//1: Master configuration

#define SPI_Operation_Slave 			(uint8_t)(0)
#define SPI_Operation_Master 			(uint8_t)(1<<2)

//@ref SPI_NSS_Mode_define

//Bit 9 SSM: Software slave management
//When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
//0: Software slave management disabled
//1: Software slave management enabled

#define SPI_NSS_Mode_Hard_Slave							(uint16_t)(0)
#define SPI_NSS_Mode_Hard_Master_SS_Output_Enabled		(uint16_t)(1<<2)
#define SPI_NSS_Mode_Hard_Master_SS_output_disable  	(uint16_t)(~(1<<2))

#define SPI_NSS_Mode_NSSInternalSoft_Reset				(uint16_t)(1<<9)
#define SPI_NSS_Mode_NSSInternalSoft_Set				(uint16_t)(3<<8)

//@ref SPI_Clk_Phase_Polarity_define

//Bit1 CPOL: Clock polarity
//0: CK to 0 when idle
//1: CK to 1 when idle
//Note: This bit should not be changed when communication is ongoing.
//It is not used in I2S mode
//Bit 0 CPHA: Clock phase
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge

#define SPI_Clk_Phase_Polarity_LOW_1st_Edge		(uint8_t)(0)
#define SPI_Clk_Phase_Polarity_LOW_2nd_Edge		(uint8_t)(1)
#define SPI_Clk_Phase_Polarity_HIGH_1st_Edge	(uint8_t)(2)
#define SPI_Clk_Phase_Polarity_HIGH_2nd_Edge	(uint8_t)(3)

//@ref SPI_BaudRate_Prescaler_define

//Bits 5:3BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256

#define SPI_BaudRate_Prescaler_2		(uint8_t)(0)
#define SPI_BaudRate_Prescaler_4		(uint8_t)(1<<3)
#define SPI_BaudRate_Prescaler_8		(uint8_t)(2<<3)
#define SPI_BaudRate_Prescaler_16		(uint8_t)(3<<3)
#define SPI_BaudRate_Prescaler_32		(uint8_t)(4<<3)
#define SPI_BaudRate_Prescaler_64		(uint8_t)(5<<3)
#define SPI_BaudRate_Prescaler_128		(uint8_t)(6<<3)
#define SPI_BaudRate_Prescaler_256		(uint8_t)(7<<3)

//@ref SPI_IRQ_Enable_define

//Bit 7 TXEIE: Tx buffer empty interrupt enable
//0: TXE interrupt masked
//1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
//Bit 6 RXNEIE: RX buffer not empty interrupt enable
//0: RXNE interrupt masked
//1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is
//set.
//Bit 5 ERRIE: Error interrupt enable
//This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
//OVR, MODF in SPI mode and UDR, OVR in I2S mode).
//0: Error interrupt is masked
//1: Error interrupt is enabled

#define SPI_IRQ_Disabled			(uint8_t)(0)
#define SPI_IRQ_Enable_TXEIE		(uint8_t)(1<<7)
#define SPI_IRQ_Enable_RXNEIE		(uint8_t)(1<<6)
#define SPI_IRQ_Enable_ERRIE		(uint8_t)(1<<5)

//API

void MCAL_SPI_Init(SPI_Typedef *SPIx, SPI_Config_t* SPI_Config);
void MCAL_SPI_DeInit(SPI_Typedef *SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_Typedef *SPIx);

void MCAL_SPI_SendData(SPI_Typedef *SPIx, uint16_t *data_buffer,Polling_mechanism Polling);
void MCAL_SPI_ReceiveData(SPI_Typedef *SPIx, uint16_t *data_buffer ,Polling_mechanism Polling);

void MCAL_SPI_TX_RX(SPI_Typedef *SPIx, uint16_t *data_buffer,Polling_mechanism Polling);

#endif /* INCLUDE_STM32_F103C6_SPI_DRIVER_H_ */

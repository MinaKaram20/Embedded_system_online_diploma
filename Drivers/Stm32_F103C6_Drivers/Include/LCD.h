/*
 * LCD.h
 *
 *  Created on: 21 Sept 2024
 *      Author: minak
 */

#ifndef LCD_H_
#define LCD_H_

#include "Stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include <stdlib.h>
#include <stdio.h>

#define LCD_PORT			GPIOA
#define DATA_shift			0 //0: 8 bit mode | 4: 4 bit mode
#define LCD_Control			GPIOA
#define EN_switch			GPIO_PIN_10
#define ReadWrite			GPIO_PIN_9
#define RS_switch			GPIO_PIN_8

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define LCD_REGISTER_SELECT_PIN		(0)
#define LCD_READ_WRITE_PIN			(1)
#define LCD_ENABLE_PIN				(2)
#define LCD_REGISTER_SELECT_ENABLE	(1)
#define LCD_REGISTER_SELECT_DISABLE	(0)
#define READ_FROM_LCD				(1)
#define WRITE_TO_LCD				(0)
#define LCD_ENABLE					(1)
#define LCD_DISABLE					(0)
#define LCD_FIRST_LINE				(0)
#define LCD_SECOND_LINE				(1)
#define LCD_FUNCTION_8BIT_2LINES	(0x38)
#define LCD_FUNCTION_4BIT_2LINES    (0x28)
#define LCD_MOVE_DISP_RIGHT         (0x1C)
#define LCD_MOVE_DISP_LEFT          (0x18)
#define LCD_MOVE_CURSOR_RIGHT       (0x14)
#define LCD_MOVE_CURSOR_LEFT        (0x10)
#define LCD_DISP_OFF                (0x08)
#define LCD_DISP_ON_CURSOR          (0x0E)
#define LCD_DISP_ON_CURSOR_BLINK    (0x0F)
#define LCD_DISP_ON_BLINK           (0x0D)
#define LCD_DISP_ON                 (0x0C)
#define LCD_ENTRY_DEC               (0x04)
#define LCD_ENTRY_DEC_SHIFT         (0x05)
#define LCD_ENTRY_INC_              (0x06)
#define LCD_ENTRY_INC_SHIFT         (0x07)
#define LCD_BEGIN_AT_FIRST_RAW      (0x80)
#define LCD_BEGIN_AT_SECOND_RAW     (0xC0)
#define LCD_CLEAR_SCREEN            (0x01)
#define LCD_ENTRY_MODE              (0x06)


void Check_LCD_is_busy(void);
void LCD_kick(void);
void LCD_send_a_command(unsigned char command);
void LCD_send_a_char(unsigned char character);
void LCD_send_a_string(char * string);
void LCD_init(void);
void LCD_clear_screen(void);
void LCD_GOTO_XY(unsigned char line,unsigned char position);

#endif /* LCD_H_ */

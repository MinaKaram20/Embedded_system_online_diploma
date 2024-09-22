/*
 * LCD.c
 *
 *  Created on: 21 Sept 2024
 *      Author: minak
 */

#include "LCD.h"


void Check_LCD_is_busy(void){
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	LCD_Control |= 1<<ReadWrite;
	LCD_Control &= ~(1<<RS_switch);
	LCD_kick();
	DataDir_LCD_PORT |= 0xFF;
	LCD_Control &= ~(1<<ReadWrite);
}
void LCD_kick(void){
	LCD_Control &= ~(1<<EN_switch);
	_delay_ms(50);
	LCD_Control |= 1<<EN_switch;
}
void LCD_send_a_command(unsigned char command){

#ifdef EIGHT_BIT_MODE
	Check_LCD_is_busy();
	LCD_PORT = command;
	LCD_Control &= ~(1<<RS_switch | 1<<ReadWrite);
	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE
	Check_LCD_is_busy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_Control &= ~(1<<RS_switch | 1<<ReadWrite);
	LCD_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_Control &= ~(1<<RS_switch | 1<<ReadWrite);
	LCD_kick();
#endif
}
void LCD_send_a_char(unsigned char character){

#ifdef EIGHT_BIT_MODE
	Check_LCD_is_busy();
	LCD_PORT = character;
	LCD_Control |= 1<<RS_switch;
	LCD_Control &= ~(1<<ReadWrite);
	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE
	Check_LCD_is_busy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_Control |= 1<<RS_switch;
	LCD_Control &= ~(1<<ReadWrite);
	LCD_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_Control |= 1<<RS_switch;
	LCD_Control &= ~(1<<ReadWrite);
	LCD_kick();
#endif
}
void LCD_send_a_string(char * string){
	Check_LCD_is_busy();
	int count = 0;
	while(*string > 0){
		count++;
		LCD_send_a_char(*string++);
		if(count==16){
			LCD_GOTO_XY(LCD_SECOND_LINE,0);
		}
		else if(count>=32){
			LCD_clear_screen();
			LCD_GOTO_XY(LCD_FIRST_LINE,0);
			count = 0;
		}
	}
}
void LCD_init(void){
	_delay_ms(20);
	DataDir_LCD_Control |= (1<<EN_switch | 1<<RS_switch | 1<<ReadWrite);
	LCD_Control &= ~(1<<EN_switch | 1<<RS_switch | 1<<ReadWrite);
	DataDir_LCD_PORT |= 0xFF;
	_delay_ms(15);

	LCD_clear_screen();

#ifdef EIGHT_BIT_MODE
	LCD_send_a_command(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	LCD_send_a_command(0x02);
	LCD_send_a_command(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_send_a_command(LCD_ENTRY_MODE);
	LCD_send_a_command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_send_a_command(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_clear_screen(void){
	LCD_send_a_command(LCD_CLEAR_SCREEN);
}
void LCD_GOTO_XY(unsigned char line,unsigned char position){
	if(line == 0){
		if(position < 16 && position >= 0){
			LCD_send_a_command(0x80 + position);
		}
	}
	else if(line == 1){
		if(position < 16 && position >= 0){
			LCD_send_a_command(0xC0 + position);
		}
	}
}


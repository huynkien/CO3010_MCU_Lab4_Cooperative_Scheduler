/*
 * led_7segment.c
 *
 *  Created on: Oct 30, 2025
 *      Author: Dell
 */

#include "led_7segment.h"

uint8_t clock_status = SEG0;

const uint8_t MAT_7SEG[10] = {
	0x3F, // 0: a b c d e f
	0x06, // 1:   b c
	0x5B, // 2: a b   d e   g
	0x4F, // 3: a b c d     g
	0x66, // 4:   b c   f   g
	0x6D, // 5: a   c d   f g
	0x7D, // 6: a   c d e f g
	0x07, // 7: a b c
	0x7F, // 8: a b c d e f g
	0x6F  // 9: a b c d   f g
};

uint8_t vertical_clock_buffer[2] = {0,0};
uint8_t horizontal_clock_buffer[2] = {0,0};

void update_clock_buffer() {
	vertical_clock_buffer[0] = (ver_clock) / 10;
	vertical_clock_buffer[1] = (ver_clock) % 10;
	horizontal_clock_buffer[0] = (hor_clock) / 10;
	horizontal_clock_buffer[1] = (hor_clock) % 10;
}

void display_all_clock() {
	update_clock_buffer();
	switch(clock_status) {
		case SEG0:
			enable_num(0);
			display_ver_num(MAT_7SEG[vertical_clock_buffer[0]]);
			clock_status = SEG1;
			break;
		case SEG1:
			enable_num(1);
			display_ver_num(MAT_7SEG[vertical_clock_buffer[1]]);
			clock_status = SEG2;
			break;
		case SEG2:
			enable_num(2);
			display_hor_num(MAT_7SEG[horizontal_clock_buffer[0]]);
			clock_status = SEG3;
			break;
		case SEG3:
			enable_num(3);
			display_hor_num(MAT_7SEG[horizontal_clock_buffer[1]]);
			clock_status = SEG0;
			break;
		default:
			break;
	}
}


void display_ver_num(uint8_t digit) {
	HAL_GPIO_WritePin(SEG0_0_GPIO_Port, SEG0_0_Pin, (digit & (1<<0)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_1_GPIO_Port, SEG0_1_Pin, (digit & (1<<1)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_2_GPIO_Port, SEG0_2_Pin, (digit & (1<<2)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_3_GPIO_Port, SEG0_3_Pin, (digit & (1<<3)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_4_GPIO_Port, SEG0_4_Pin, (digit & (1<<4)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_5_GPIO_Port, SEG0_5_Pin, (digit & (1<<5)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG0_6_GPIO_Port, SEG0_6_Pin, (digit & (1<<6)) ? 1 : 0 );
}

void display_hor_num(uint8_t digit) {
	HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, (digit & (1<<0)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, (digit & (1<<1)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, (digit & (1<<2)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, (digit & (1<<3)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, (digit & (1<<4)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, (digit & (1<<5)) ? 1 : 0 );
	HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, (digit & (1<<6)) ? 1 : 0 );
}

void disable_all_7seg() {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
}

void enable_num(uint8_t index) {
	switch (index)
	{
		case 0:
			disable_all_7seg();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			break;
		case 1:
			disable_all_7seg();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			break;
		case 2:
			disable_all_7seg();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			break;
		case 3:
			disable_all_7seg();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			break;
		default:
			break;
	}
}

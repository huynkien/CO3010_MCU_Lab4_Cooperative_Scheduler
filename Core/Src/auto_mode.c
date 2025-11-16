/*
 * fsm.c
 *
 *  Created on: Oct 2, 2025
 *      Author: Dell
 */

#include <auto_mode.h>
#include "config_mode.h"

uint8_t red_time = RED_TIME;
uint8_t grn_time = GRN_TIME;
uint8_t yel_time = YEL_TIME;

uint16_t ver_clock = 0;
uint16_t hor_clock = 0;

uint8_t traffic_light_status = INIT;

// Static counters (in 10ms ticks)
static uint16_t state_counter = 0;
static uint16_t clock_counter = 0;

void fsm_auto_traffic_light_run() {
	switch(traffic_light_status) {
		case INIT:
			traffic_light_status = AUTO_GRN_RED;
			ver_clock = grn_time;
			hor_clock = red_time;
			state_counter = grn_time * 100;  // Convert to ticks (100 ticks = 1 second)
			clock_counter = 100;
			break;
			
		case AUTO_GRN_RED:
			green_red();

			// Decrement counters
			if (clock_counter > 0) {
				clock_counter--;
			}
			if (state_counter > 0) {
				state_counter--;
			}
			
			// Update clock display every 100 ticks (1 second)
			if (clock_counter == 0) {
				if (ver_clock > 0) ver_clock--;
				if (hor_clock > 0) hor_clock--;
				clock_counter = 100;
			}
			
			// Transition to next state
			if (state_counter == 0) {
				traffic_light_status = AUTO_YEL_RED;
				ver_clock = yel_time;
				hor_clock = yel_time;
				state_counter = yel_time * 100;
				clock_counter = 100;
			}

			// Button handling
			if (isButtonPressed(&button0)) {
				disable_all_tfl();
				traffic_light_status = CFG_RED;
				init_cfg_red();
			}
			break;
			
		case AUTO_YEL_RED:
			yellow_red();

			if (clock_counter > 0) {
				clock_counter--;
			}
			if (state_counter > 0) {
				state_counter--;
			}
			
			if (clock_counter == 0) {
				if (ver_clock > 0) ver_clock--;
				if (hor_clock > 0) hor_clock--;
				clock_counter = 100;
			}
			
			if (state_counter == 0) {
				traffic_light_status = AUTO_RED_GRN;
				ver_clock = red_time;
				hor_clock = grn_time;
				state_counter = grn_time * 100;
				clock_counter = 100;
			}

			if (isButtonPressed(&button0)) {
				disable_all_tfl();
				traffic_light_status = CFG_RED;
				init_cfg_red();
			}
			break;
			
		case AUTO_RED_GRN:
			red_green();

			if (clock_counter > 0) {
				clock_counter--;
			}
			if (state_counter > 0) {
				state_counter--;
			}
			
			if (clock_counter == 0) {
				if (ver_clock > 0) ver_clock--;
				if (hor_clock > 0) hor_clock--;
				clock_counter = 100;
			}
			
			if (state_counter == 0) {
				traffic_light_status = AUTO_RED_YEL;
				ver_clock = yel_time;
				hor_clock = yel_time;
				state_counter = yel_time * 100;
				clock_counter = 100;
			}

			if (isButtonPressed(&button0)) {
				disable_all_tfl();
				traffic_light_status = CFG_RED;
				init_cfg_red();
			}
			break;
			
		case AUTO_RED_YEL:
			red_yellow();

			if (clock_counter > 0) {
				clock_counter--;
			}
			if (state_counter > 0) {
				state_counter--;
			}
			
			if (clock_counter == 0) {
				if (ver_clock > 0) ver_clock--;
				if (hor_clock > 0) hor_clock--;
				clock_counter = 100;
			}
			
			if (state_counter == 0) {
				traffic_light_status = AUTO_GRN_RED;
				ver_clock = grn_time;
				hor_clock = red_time;
				state_counter = grn_time * 100;
				clock_counter = 100;
			}

			if (isButtonPressed(&button0)) {
				disable_all_tfl();
				traffic_light_status = CFG_RED;
				init_cfg_red();
			}
			break;
			
		default:
			break;
	}
}

void disable_all_tfl() {
	// Vertical road
	HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 1);
	HAL_GPIO_WritePin(YEL0_GPIO_Port, YEL0_Pin, 1);
	HAL_GPIO_WritePin(GRN0_GPIO_Port, GRN0_Pin, 1);

	// Horizontal road
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, 1);
	HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 1);
}

void green_red() {
	// Vertical road
	HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 1);
	HAL_GPIO_WritePin(YEL0_GPIO_Port, YEL0_Pin, 1);
	HAL_GPIO_WritePin(GRN0_GPIO_Port, GRN0_Pin, 0);

	// Horizontal road
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, 1);
	HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 1);
}
void yellow_red() {
	// Vertical road
	HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 1);
	HAL_GPIO_WritePin(YEL0_GPIO_Port, YEL0_Pin, 0);
	HAL_GPIO_WritePin(GRN0_GPIO_Port, GRN0_Pin, 1);

	// Horizontal road
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, 1);
	HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 1);
}
void red_green() {
	// Vertical road
	HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
	HAL_GPIO_WritePin(YEL0_GPIO_Port, YEL0_Pin, 1);
	HAL_GPIO_WritePin(GRN0_GPIO_Port, GRN0_Pin, 1);

	// Horizontal road
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, 1);
	HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 0);
}
void red_yellow() {
	// Vertical road
	HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
	HAL_GPIO_WritePin(YEL0_GPIO_Port, YEL0_Pin, 1);
	HAL_GPIO_WritePin(GRN0_GPIO_Port, GRN0_Pin, 1);

	// Horizontal road
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, 0);
	HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 1);
}


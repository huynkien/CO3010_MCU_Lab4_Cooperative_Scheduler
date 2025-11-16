/*
 * tasks.c
 *
 *  Created on: Nov 16, 2025
 *      Author: Dell
 */

#include "tasks.h"

void task_toggle_status_led(void) {
	HAL_GPIO_TogglePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin);
}

// Task: Run traffic light FSM (auto mode + config mode)
void task_traffic_light_fsm(void) {
	// Run appropriate FSM based on current state
	getKeyInput(&button0);
	getKeyInput(&button1);
	getKeyInput(&button2);
	if (traffic_light_status <= AUTO_RED_YEL) {
		fsm_auto_traffic_light_run();
	} else {
		fsm_config_traffic_light_run();
	}
	display_all_clock();
}

// Task: Scan all buttons
void task_button_scan(void) {
	getKeyInput(&button0);
	getKeyInput(&button1);
	getKeyInput(&button2);
}

// Task: Display 7-segment LED
void task_display_7seg(void) {
	display_all_clock();
}

/*
 * tasks.h
 *
 *  Created on: Nov 16, 2025
 *      Author: Dell
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "main.h"
#include "global.h"
#include "auto_mode.h"
#include "config_mode.h"
#include "button.h"
#include "led_7segment.h"

// Task functions for scheduler
void task_toggle_status_led(void);
void task_traffic_light_fsm(void);
void task_button_scan(void);
void task_display_7seg(void);

#endif /* INC_TASKS_H_ */

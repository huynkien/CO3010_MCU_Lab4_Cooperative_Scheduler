/*
 * led_7segment.h
 *
 *  Created on: Oct 30, 2025
 *      Author: Dell
 */

#ifndef INC_LED_7SEGMENT_H_
#define INC_LED_7SEGMENT_H_

#include "main.h"
#include "global.h"

extern uint8_t clock_status;

void update_clock_buffer();

void display_all_clock();
void vertical_clock();
void horizontal_clock();

void display_ver_num(uint8_t num);
void display_hor_num(uint8_t num);

//void display_num(uint8_t num);
void disable_all_7seg();
void enable_num(uint8_t index);

#endif /* INC_LED_7SEGMENT_H_ */

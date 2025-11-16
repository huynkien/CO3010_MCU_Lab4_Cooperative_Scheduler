/*
 * fsm.h
 *
 *  Created on: Oct 2, 2025
 *      Author: Dell
 */

#ifndef INC_AUTO_MODE_H_
#define INC_AUTO_MODE_H_

#include "main.h"
#include "button.h"
#include "global.h"
#include "led_7segment.h"

void fsm_auto_traffic_light_run();

void disable_all_tfl();
void green_red();
void yellow_red();
void red_green();
void red_yellow();


#endif /* INC_AUTO_MODE_H_ */

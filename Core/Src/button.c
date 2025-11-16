/*
 * button.c
 *
 *  Created on: Oct 23, 2025
 *      Author: Dell
 */

#include "button.h"
//#define MAX_BUTTON 4
//
//uint8_t KeyReg0 = NORMAL_STATE;
//uint8_t KeyReg1 = NORMAL_STATE;
//uint8_t KeyReg2 = NORMAL_STATE;
//uint8_t KeyReg3 = NORMAL_STATE;
//
//uint16_t TimeOutForKeyPress = 500;
//uint8_t button_flag[MAX_BUTTON];
//uint8_t button_long_flag[MAX_BUTTON];
//
//uint8_t isButtonPressed(uint8_t index){
//	if (button_flag[index] == 1) {
//		button_flag[index] = 0;
//		return 1;
//	}
//	return 0;
//}
//
//uint8_t isButtonLongPressed(uint8_t index){
//	if(button_long_flag[index] == 1){
//		button_long_flag[index] = 0;
//		return 1;
//	}
//	return 0;
//}
//
//
//void getKeyInput(){
//  KeyReg2 = KeyReg1;
//  KeyReg1 = KeyReg0;
//  // Add your key
//  KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//
//  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
//    if (KeyReg2 != KeyReg3){
//      KeyReg3 = KeyReg2;
//
//      if (KeyReg3 == PRESSED_STATE){
//        TimeOutForKeyPress = 500;
//        //subKeyProcess();
//        HAL_GPIO_TogglePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin);
//        button1_flag = 1;
//      }
//
//    }else{
//      TimeOutForKeyPress --;
//      if (TimeOutForKeyPress == 0){
//        TimeOutForKeyPress = 500;
//        if (KeyReg3 == PRESSED_STATE){
//      	  //subKeyProcess();
//          HAL_GPIO_TogglePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin);
//      	  button1_long_flag = 1;
//        }
//      }
//    }
//  }
//}

struct ButtonStruct button0 = {
		{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
		150,
		0,
		0,
		BUTTON0_GPIO_Port,
		BUTTON0_Pin
};

struct ButtonStruct button1 = {
		{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
		150,
		0,
		0,
		BUTTON1_GPIO_Port,
		BUTTON1_Pin
};

struct ButtonStruct button2 = {
		{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
		150,
		0,
		0,
		BUTTON2_GPIO_Port,
		BUTTON2_Pin
};

void getKeyInput(struct ButtonStruct* button) {
	button->keyBuffer[2] = button->keyBuffer[1];
	button->keyBuffer[1] = button->keyBuffer[0];

	button->keyBuffer[0] = HAL_GPIO_ReadPin(button->PORT, button->PIN);

	if ((button->keyBuffer[0] == button->keyBuffer[1]) && (button->keyBuffer[1] == button->keyBuffer[2]))
	{
		if (button->keyBuffer[2] != button->keyBuffer[3])
		{
			button->keyBuffer[3] = button->keyBuffer[2];

			if (button->keyBuffer[3] == PRESSED_STATE)
			{
				button->timeOutForPressed = 150;
				button->isPressed = 1;
			}
		}
		else // button->keyBuffer[2] == button->keyBuffer[3]
		{
			--button->timeOutForPressed;
			if (button->timeOutForPressed <= 0)
			{
				button->timeOutForPressed = 150;
				if (button->keyBuffer[3] == PRESSED_STATE)
				{
					button->isLongPressed = 1;
				}
			}
		}
	}
}

uint8_t isButtonPressed(struct ButtonStruct *button) {
	if (button->isPressed == 1)
	{
		button->isPressed = 0;
		return 1;
	}
	return 0;
}

uint8_t isButtonLongPressed(struct ButtonStruct *button) {
	if (button->isLongPressed == 1)
	{
		button->isLongPressed = 0;
		return 1;
	}
	return 0;
}

void resetButton(struct ButtonStruct *button) {
	button->isPressed = 0;
	button->isLongPressed = 0;
}

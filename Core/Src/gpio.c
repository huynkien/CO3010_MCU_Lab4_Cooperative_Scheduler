/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SEG0_0_Pin|SEG0_1_Pin|SEG0_2_Pin|SEG0_3_Pin
                          |SEG0_4_Pin|SEG0_5_Pin|SEG0_6_Pin|SEG0_7_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |STATUS_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin|SEG1_1_Pin|SEG1_2_Pin|GRN0_Pin
                          |RED1_Pin|YEL1_Pin|GRN1_Pin|SEG1_3_Pin
                          |SEG1_4_Pin|SEG1_5_Pin|SEG1_6_Pin|SEG1_7_Pin
                          |RED0_Pin|YEL0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SEG0_0_Pin SEG0_1_Pin SEG0_2_Pin SEG0_3_Pin
                           SEG0_4_Pin SEG0_5_Pin SEG0_6_Pin SEG0_7_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           STATUS_LED_Pin */
  GPIO_InitStruct.Pin = SEG0_0_Pin|SEG0_1_Pin|SEG0_2_Pin|SEG0_3_Pin
                          |SEG0_4_Pin|SEG0_5_Pin|SEG0_6_Pin|SEG0_7_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |STATUS_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG1_0_Pin SEG1_1_Pin SEG1_2_Pin GRN0_Pin
                           RED1_Pin YEL1_Pin GRN1_Pin SEG1_3_Pin
                           SEG1_4_Pin SEG1_5_Pin SEG1_6_Pin SEG1_7_Pin
                           RED0_Pin YEL0_Pin */
  GPIO_InitStruct.Pin = SEG1_0_Pin|SEG1_1_Pin|SEG1_2_Pin|GRN0_Pin
                          |RED1_Pin|YEL1_Pin|GRN1_Pin|SEG1_3_Pin
                          |SEG1_4_Pin|SEG1_5_Pin|SEG1_6_Pin|SEG1_7_Pin
                          |RED0_Pin|YEL0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON0_Pin BUTTON1_Pin BUTTON2_Pin */
  GPIO_InitStruct.Pin = BUTTON0_Pin|BUTTON1_Pin|BUTTON2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

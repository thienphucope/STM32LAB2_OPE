/*
 * global.c
 *
 *  Created on: Sep 24, 2024
 *      Author: HPVictus
 */
#include "global.h"

int status;
void run()
{
	if (timer_flag[0] == 1)
		  {
			  setTimer(0, 50);
		  switch (status)
		  {
		  case 0:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			  display7SEG(1);
			  status = 1;
			  break;
		  case 1:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			  display7SEG(2);
			  status = 2;
			  break;
		  case 2:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			  display7SEG(3);
			  status = 3;
			  break;
		  case 3:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			  display7SEG(0);
			  status = 0;
			  break;
		  default:
			  break;
		  }
		  }
	if (timer_flag[1] == 1) {
		setTimer(1, 100);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		}
}

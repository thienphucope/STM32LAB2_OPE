/*
 * global.c
 *
 *  Created on: Sep 24, 2024
 *      Author: HPVictus
 */
#include "global.h"

int status;

const int MAX_LED = 4;  // We've got 4 segments to play with
int index_led = 0;      // Keeps track of which 7-segment display to update
int led_buffer[4] = {5, 6, 7, 8};  // Buffer holds values for each segment

void update7SEG(int index) {
    switch (index) {
        case 0:
            // Display the first 7-segment display with led_buffer[0]
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            display7SEG(led_buffer[0]);  // Assuming there's a function to show the value

            break;
        case 1:
            // Display the second 7-segment display with led_buffer[1]
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            display7SEG(led_buffer[1]);

            break;
        case 2:
            // Display the third 7-segment display with led_buffer[2]
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            display7SEG(led_buffer[2]);
            break;
        case 3:
            // Display the fourth 7-segment display with led_buffer[3]
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
            display7SEG(led_buffer[3]);
            break;
        default:
            // Just in case something wild happens and index is out of range
            break;
    }
}

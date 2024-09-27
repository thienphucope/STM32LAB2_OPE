/*
 * global.c
 *
 *  Created on: Sep 24, 2024
 *      Author: HPVictus
 */
#include "global.h"


const int MAX_LED = 4;  // We've got 4 segments to play with
int index_led = 0;      // Keeps track of which 7-segment display to update
int led_buffer[4] = {5, 6, 7, 8};  // Buffer holds values for each segment
int hour = 15, minute = 8, second = 50;
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

	const int MAX_LED_MATRIX = 8;
	int index_led_matrix = 0;
	uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

	void updateLEDMatrix(int index) {
	    switch (index) {
	        case 0:
	            // Set the appropriate bits in matrix_buffer for character "A"
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);

	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	            break;
	        case 1:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 2:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 3:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 4:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 5:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 6:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        case 7:
	        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
	        	if (matrix_buffer[index] & (1 << 0)) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 1)) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 2)) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 3)) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 4)) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 5)) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 6)) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	        	if (matrix_buffer[index] & (1 << 7)) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	        	break;
	        // Add cases for other indices if needed
	        default:
	            // Handle invalid index (optional)
	            break;
	    }
	}

void updateMatrixBuffer()
{
    matrix_buffer[0] = 0b00111100;
    matrix_buffer[1] = 0b01000010;
    matrix_buffer[2] = 0b01000010;
    matrix_buffer[3] = 0b01111110;
    matrix_buffer[4] = 0b01000010;
    matrix_buffer[5] = 0b01000010;
    matrix_buffer[6] = 0b01000010;
    matrix_buffer[7] = 0b00000000;
}
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}

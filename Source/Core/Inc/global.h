/*
 * global.h
 *
 *  Created on: Sep 24, 2024
 *      Author: HPVictus
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "led7.h"
#include "software_timer.h"

extern int counter;
extern int blink;


extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void update7SEG(int index);

extern int hour;
extern int minute;
extern int second;
void updateClockBuffer();
#endif /* INC_GLOBAL_H_ */

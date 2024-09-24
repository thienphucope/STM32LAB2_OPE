/*
 * software_timer.h
 *
 *  Created on: 21 Sep 2024
 *      Author: HPVictus
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];
#define TICK 1//
void setTimer(int index, int counter);
void timerRun();



#endif /* INC_SOFTWARE_TIMER_H_ */

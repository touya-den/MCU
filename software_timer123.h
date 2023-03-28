/*
 * software_timer.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int led7[10][7];
extern int dot;
extern int led_buffer[4];
extern int index;

void setTimer1(int duration);
void timerRun();
void ledoff();
void display7SEG(int c);
void check_buffer();
void update7SEG(int index);
void setDot(int dot);

#endif /* INC_SOFTWARE_TIMER_H_ */

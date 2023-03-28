/*
 * software_timer.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Admin
 */

#include "software_timer.h"
#include "main.h"

int timer1_counter = 0;
int timer1_flag = 0;
int led7[10][7] = {
		  {0,0,0,0,0,0,1},	//0
		  {1,0,0,1,1,1,1},	//1
		  {0,0,1,0,0,1,0},	//2
		  {0,0,0,0,1,1,0},	//3
		  {1,0,0,1,1,0,0},	//4
		  {0,1,0,0,1,0,0},	//5
		  {0,1,0,0,0,0,0},	//6
		  {0,0,0,1,1,1,1},	//7
		  {0,0,0,0,0,0,0},	//8
		  {0,0,0,0,1,0,0}	//9
  };
int dot = 1;
int index = 0;
int led_buffer[4] = {1,2,3,4};

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
void ledoff(){
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, SET);
  }
void display7SEG(int c){
	  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, led7[c][0]);
	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, led7[c][1]);
	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, led7[c][2]);
	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, led7[c][3]);
	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, led7[c][4]);
	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, led7[c][5]);
	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, led7[c][6]);
}
void check_buffer(){
	if(led_buffer[3] == 10) {
		led_buffer[0] = 1;
		led_buffer[1] = 2;
		led_buffer[2] = 3;
		led_buffer[3] = 4;
	}
}
void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}
void setDot(int dot){
		switch(dot){
			case 1:
				  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, SET);
				  break;
			case 2:
				  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, RESET);
				  break;
			default:
				break;
		}
}



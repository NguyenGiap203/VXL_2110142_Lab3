/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

		status = AUTO_RED;
		setTimer(0, 5000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

		if(isTimerExpired(0) == 1){
			status = AUTO_GREEN;
			setTimer(0, 3000);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer(0, 10000);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		if(isTimerExpired(0) == 1){
			status = AUTO_YELLOW;
			setTimer(0, 2000);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);

		if(isTimerExpired(0) == 1){
			status = AUTO_RED;
			setTimer(0, 5000);
		}
		break;
	default:
		break;
	}
}

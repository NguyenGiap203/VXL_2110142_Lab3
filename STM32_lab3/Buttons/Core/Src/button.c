/*
 * button.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "button.h"

int button1_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE; // Trang thai on dinh truoc do (su dung cho nhan de)
int TimerForKeyPress = 200; // 2000ms

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	button1_flag = 1;
}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				//TODO
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				//TODO
				if(KeyReg2 == PRESSED_STATE){
					subKeyProcess();
				}
				TimerForKeyPress = 200;
			}
		}
	}
}

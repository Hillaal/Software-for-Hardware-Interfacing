/*
============================================================================
 Name        : keypad.c
 Author      : Ahmed Khaled Hilal
 Description : keypad driver source file
 ============================================================================
*/

#include "Keypad.h"
#include "GPIO.h"
#include "stm32f401cc_interface.h"


unsigned char state=RELEASED;
unsigned char Keymap_array[4][3]={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};
unsigned char key;

void Keypad_Init(){

	GPIO_EnableClock(Keypad_Port);
	GPIO_Init(Keypad_Port,0,OUTPUT,PUSH_PULL);
	GPIO_Init(Keypad_Port,1,OUTPUT,PUSH_PULL);
	GPIO_Init(Keypad_Port,2,OUTPUT,PUSH_PULL);

	GPIO_Init(Keypad_Port,3,INPUT,PULL_UP);
	GPIO_Init(Keypad_Port,4,INPUT,PULL_UP);
	GPIO_Init(Keypad_Port,5,INPUT,PULL_UP);
	GPIO_Init(Keypad_Port,6,INPUT,PULL_UP);

}


void Keypad_Manage(){
	unsigned char i,j;

	if(state == RELEASED){
		for(i=0;i<3;i++){
			GPIO_WritePin(Keypad_Port,i,0);
			for(j=0;j<4;j++){

				if(GPIO_ReadPin(Keypad_Port, j+3)==0){
					delay30ms();
					if(GPIO_ReadPin(Keypad_Port, j+3)==0){
						key=Keymap_array[j][i];
						state=PRESSED;
						KeypadCallouts_KeyPressNotificaton();
					}
				}

			}
			GPIO_WritePin(Keypad_Port,i,1);
		}

	}
}


unsigned char Keypad_GetKey(){

	if(state == PRESSED){
		state = RELEASED;
		return key;
	}

	else {
		return -1;
	}
}

void delay30ms() {
  unsigned int i;
  for (i = 0; i < 30000; i++) {
  }
}

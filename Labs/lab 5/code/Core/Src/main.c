/*
============================================================================
 Name        : lab 5
 Author      : Ahmed Khaled Hilal
 Description : software that display a number on a seven-segment display after pressing a button on a keypad.
 ============================================================================
*/

#include "GPIO.h"
#include "Keypad.h"

unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void SevenSeg_Init();


int main(void) {

  Keypad_Init();
  SevenSeg_Init();

  while (1) {
  
	  Keypad_Manage();

  }

  return 0;
}


void KeypadCallouts_KeyPressNotificaton(){

	unsigned char key_number,i;
	key_number=Keypad_GetKey();

	 for (i = 0; i < 7; i++){
		            GPIO_WritePin('A', i, (sevenSegHex[key_number] & (1 << i)) >> i);
		    }
}


void SevenSeg_Init(){

	  unsigned char i=0;

	  GPIO_EnableClock('A');
	  for (; i < 7; i++) {
		  GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	  }

}



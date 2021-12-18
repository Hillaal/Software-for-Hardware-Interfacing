/*
============================================================================
 Name        : lab 6
 Author      : Ahmed Khaled Hilal
 Description : Led blinking to test the GPIO driver
 ============================================================================
*/


#include "GPIO.h"

int main(void) {
	int i;

	GPIO_EnableClock(0);		/*enable GPIO clock*/

	GPIO_Init(0, 0,OUTPUT,PUSH_PULL);		/*GPIO pin configuration*/

  while (1) {

	  GPIO_WritePin(0, 0, 1); /*Led ON*/

	  for (i = 0; i < 1000000; i++)	{}	  /*delay 1 sec*/

	  GPIO_WritePin(0, 0, 0);		  /*Led OFF*/

	  for (i = 0; i < 1000000; i++)	{}	  /*delay 1 sec*/

  }
  return 0;
}

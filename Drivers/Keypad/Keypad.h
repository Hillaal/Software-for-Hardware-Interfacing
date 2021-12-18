/*
============================================================================
 Name        : keypad.h
 Author      : Ahmed Khaled Hilal
 Description : keypad driver header file
 ============================================================================
*/

#ifndef KEYPAD_H
#define KEYPAD_H

#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

#define PRESSED	(0)
#define RELEASED (1)

#define Keypad_Port ('B')

void Keypad_Init();
void Keypad_Manage();
unsigned char Keypad_GetKey();
void KeypadCallouts_KeyPressNotificaton();
void delay30ms();

#endif /* KEYPAD_H */

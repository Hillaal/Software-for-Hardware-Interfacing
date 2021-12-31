/*
============================================================================
 Name        : GPIO.c
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC GPIO driver source file
 ============================================================================
*/

#include "GPIO.h"

static unsigned int Port[3]={GPIOA,GPIOB,GPIOC}; 	/*array of ports addresses*/

/*static because it will be used only in this file and doesn't want any other file to use it */


void GPIO_EnableClock(char PortNo)
{

	RCC_REG (RCC_AHB1ENR)  |= (0x01 << PortNo);  /*Enable clock for the port that will be used*/

}

/* GPIO initialize function, takes arguments (port number, pin number, pin mode, pin default state)*/

void GPIO_Init(unsigned char PortNo, unsigned char PinNum, unsigned char PinMode, unsigned char DefaultState)
{

  GPIO_REG(Port[PortNo],GPIO_MODER) &= ~(0x03 << 2 * PinNum);
  GPIO_REG(Port[PortNo],GPIO_MODER) |= PinMode << 2 * PinNum;

  GPIO_REG(Port[PortNo],GPIO_OTYPER) &= ~(1 << PinNum);
  GPIO_REG(Port[PortNo],GPIO_OTYPER)|= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

  GPIO_REG(Port[PortNo],GPIO_PUPDR) &= ~(0x03 << 2 * PinNum);
  GPIO_REG(Port[PortNo],GPIO_PUPDR) |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);

}

/*function to write GPIO pin takes arguments(port number,pin number, the data to be written 0 or 1)*/

unsigned char GPIO_WritePin(unsigned char PortNo, unsigned char PinNum,unsigned char Data)
{

  unsigned char result;

      if (((GPIO_REG(Port[PortNo],GPIO_MODER) & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
        	GPIO_REG(Port[PortNo],GPIO_ODR) |= (1 << PinNum);
        } else {
        	GPIO_REG(Port[PortNo],GPIO_ODR) &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

/*function to read GPIO pin takes arguments(port number,pin number) and return data 0 or 1 */

unsigned char GPIO_ReadPin(unsigned char PortNo, unsigned char PinNum) {
	unsigned char data = 0;

	data = (GPIO_REG(Port[PortNo],GPIO_IDR) & (1 << PinNum)) >> PinNum;

  return data;
}

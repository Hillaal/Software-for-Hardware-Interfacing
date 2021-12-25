/*
============================================================================
 Name        : lab 7
 Author      : Ahmed Khaled Hilal
 Description : A software to perform an LED toggle based on a button press. (exercise on interrupts)
 ============================================================================
*/


#include "GPIO.h"

#define A (0)
#define B (1)


#define REG(BASE,OFFSET) 		   *((unsigned int*)(BASE + OFFSET))

#define RCC 			(0x40023800) /*RCC Base*/
#define RCC_APB2ENR		(0x44)		/*RCC_APB2ENR Offset*/

#define SYSCFG			(0x40013800)	/*SYSCFG Base*/
#define SYSCFG_EXTICR1 	(0x08)			/*SYSCFG_EXTICR1 Offset*/


#define EXTI			(0x40013C00)	/*External interrupt Base*/

/*External Interrupt registers Offsets*/

#define EXTI_IMR		(0x00)
#define EXTI_EMR		(0x04)
#define EXTI_RSTR		(0x08)
#define EXTI_FSTR		(0x0C)
#define EXTI_SWIER		(0x10)
#define EXTI_PR			(0x14)

#define NVIC			(0xE000E100)	/*Nested Vector Interrupt Controller Base*/
#define NVIC_ISER0		(0x00)			/*interrupt set enable register 0 Offset*/

int main(void) {

	GPIO_EnableClock(A);		/*enable GPIO clock*/ /* 0 for GPIOA and 1 for GPIOB */

	GPIO_Init(A, 0,OUTPUT,PUSH_PULL);		/*GPIOA pin0 output configuration for the led*/
	GPIO_Init(A, 1,INPUT,PULL_UP);		/*GPIO pin1 input configuration for the button*/
	GPIO_WritePin(0, 0, 0); /*Led OFF*/

	REG(RCC,RCC_APB2ENR) |= (1<<14);  /*Enable clock for SYSCFG register*/

	REG(SYSCFG,SYSCFG_EXTICR1) &= ~(0x0F<<4);	/*setting external interrupt 1 on GPIOA*/

	REG(EXTI,EXTI_IMR) |= (1<<1);		/*un-mask external interrupt 1*/
	REG(EXTI,EXTI_FSTR) |= (1<<1);	/*configure external interrupt 1 to falling edge */
	REG(EXTI,EXTI_RSTR) &= ~(1<<1);	/*disable external interrupt 1 rising edge */

	REG(NVIC,NVIC_ISER0) |= (1<<7);	/*enable external interrupt 1 */


  while (1) {

  }
  return 0;
}


void EXTI1_IRQHandler (void){
	unsigned char out;
	out=1^GPIO_ReadPin(A,0);	/*reading led status and toggle it*/
	GPIO_WritePin(0, 0, out);	/*write to the led the toggled value*/
	REG(EXTI,EXTI_RSTR)  |= 1;  /*clear pending flag*/
}

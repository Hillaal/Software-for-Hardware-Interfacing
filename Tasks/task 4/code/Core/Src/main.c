/*
============================================================================
 Name        : Task 4
 Author      : Ahmed Khaled Hilal
 Description : A software to perform a decimal counter on a 7-segment display. (using interrupts)
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

void SevenSeg_Init(); /*seven segment initialization function declaration*/
void sevenSeg_display(unsigned char value); /*seven segment display function declaration*/

const unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
			                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};	/*look-up array for seven-segment */

unsigned char counter=0;	/*initializing the value of the counter to be equal 0 */

int main(void) {

	GPIO_EnableClock(A);		/*enable GPIO clock*/ /* 0 for GPIOA and 1 for GPIOB */

	GPIO_Init(A, 0,INPUT,PULL_UP);		/*GPIO pin1 input configuration for the button*/
	GPIO_Init(A, 1,INPUT,PULL_UP);		/*GPIO pin1 input configuration for the button*/

	REG(RCC,RCC_APB2ENR) |= (1<<14);  /*Enable clock for SYSCFG register*/

	REG(SYSCFG,SYSCFG_EXTICR1) &= ~(0x0F<<0);	/*setting external interrupt 0 on GPIOA*/
	REG(SYSCFG,SYSCFG_EXTICR1) &= ~(0x0F<<4);	/*setting external interrupt 1 on GPIOA*/

	REG(EXTI,EXTI_IMR) |= (1<<0);		/*un-mask external interrupt 0*/
	REG(EXTI,EXTI_IMR) |= (1<<1);		/*un-mask external interrupt 1*/

	REG(EXTI,EXTI_FSTR) |= (1<<0);	/*configure external interrupt 0 to falling edge */
	REG(EXTI,EXTI_RSTR) &= ~(1<<0);	/*disable external interrupt 0 rising edge */

	REG(EXTI,EXTI_FSTR) |= (1<<1);	/*configure external interrupt 1 to falling edge */
	REG(EXTI,EXTI_RSTR) &= ~(1<<1);	/*disable external interrupt 1 rising edge */

	REG(NVIC,NVIC_ISER0) |= (1<<6);	/*enable external interrupt 0 */
	REG(NVIC,NVIC_ISER0) |= (1<<7);	/*enable external interrupt 1 */

	SevenSeg_Init();	/*seven segment initialization function call*/

	sevenSeg_display(counter);	/*display the initial value of the counter*/


  while (1) {

  }
  return 0;
}



void SevenSeg_Init(){
								/*seven segment initialization function definition*/
	  unsigned char i=0;
	  GPIO_EnableClock(B);
	  for (; i < 7; i++) {
		  GPIO_Init(B, i, OUTPUT, PUSH_PULL);
	  }
}


void sevenSeg_display(unsigned char value){
	 unsigned char i=0;							/*seven segment display function definition*/
	 for (i = 0; i < 7; i++){
			            GPIO_WritePin(B, i, (sevenSegHex[value] & (1 << i)) >> i);
			    }
	 	 	 	 	 	 /*write 0 or 1 to each pin of the seven segment depending on the hex value*/
}


void EXTI0_IRQHandler (void){
	REG(NVIC,NVIC_ISER0) &= ~(1<<7);	/*disable external interrupt 1 */

	counter++;
	if(counter>9){
		counter=0;
	}
	sevenSeg_display(counter);
	REG(NVIC,NVIC_ISER0) |= (1<<7);	/*enable external interrupt 1 */
}


void EXTI1_IRQHandler (void){
	REG(NVIC,NVIC_ISER0) &= ~(1<<6);	/*disable external interrupt 0 */

	if(0==counter){
			counter=9;
		}
	else {
		counter--;
	}
	sevenSeg_display(counter);

	REG(NVIC,NVIC_ISER0) |= (1<<6);	/*enable external interrupt 0 */

}

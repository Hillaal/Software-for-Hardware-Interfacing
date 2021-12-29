/*
============================================================================
 Name        : Task 4
 Author      : Ahmed Khaled Hilal
 Description : A software to perform a decimal counter on a 7-segment display. (using interrupts)
 ============================================================================
*/

#include "GPIO.h"
#include "MYHEADER.h"


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

	unsigned char i,copy;

  while (1) {

	  REG(NVIC,NVIC_ICER0) |= (1<<7);	/*disable external interrupt 1 */
	  REG(NVIC,NVIC_ICER0) |= (1<<6);	/*disable external interrupt 0 */

	  copy=counter;		/*copy counter value*/

	  REG(NVIC,NVIC_ISER0) |= (1<<6);	/*enable external interrupt 0 */
	  REG(NVIC,NVIC_ISER0) |= (1<<7);	/*enable external interrupt 1 */

	  for (i = 0; i < 7; i++){
		  	  GPIO_WritePin(B, i, (sevenSegHex[copy] & (1 << i)) >> i);		/*display counter value we copied*/
	  	  }
	  	 	 	 	 	 	 /*write 0 or 1 to each pin of the seven segment depending on the hex value*/

  }
  return 0;
}



void SevenSeg_Init(){
								/*seven segment initialization function definition*/
	  unsigned char i=0;
	  GPIO_EnableClock(B);
	  for (; i < 7; i++) {
		  GPIO_Init(B, i, OUTPUT, PUSH_PULL);		/*configure seven segment pins*/
	  }
}



void EXTI0_IRQHandler (void){

	REG(NVIC,NVIC_ICER0) |= (1<<7);	/*disable external interrupt 1 */

	counter++;
						/*incrementing the counter and setting it to 0 if it's greater than 9*/
	if(counter>9){
		counter=0;
	}
	REG(NVIC,NVIC_ISER0) |= (1<<7);	/*enable external interrupt 1 */

	REG(EXTI,EXTI_PR)|= (1<<0);	/*clearing the flag for interrupt 0*/
}


void EXTI1_IRQHandler (void){
	REG(NVIC,NVIC_ICER0) |= (1<<6);	/*disable external interrupt 0 */

	if(0==counter){
			counter=9;
		}
	else {						/*decrementing the counter and setting it to 9 if it's already equal 0*/
		counter--;
	}

	REG(NVIC,NVIC_ISER0) |= (1<<6);	/*enable external interrupt 0 */

	REG(EXTI,EXTI_PR)|= (1<<1); 	/*clearing the flag for interrupt 1*/

}

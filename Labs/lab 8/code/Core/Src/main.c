/*
============================================================================
 Name        : lab 8
 Author      : Ahmed Khaled Hilal
 Description : working with UART - displaying "Hello world" on terminal
 ============================================================================
*/


#include "GPIO.h"

#define A (0)	/*GPIO selection*/
#define B (1)


#define REG(BASE,OFFSET)   *((unsigned int*)(BASE + OFFSET))	/*my macro to write in specific register*/

#define RCC 			(0x40023800) /*RCC Base*/
#define RCC_APB1ENR		(0x40)		/*RCC_APB1ENR Offset*/
#define RCC_APB2ENR		(0x44)		/*RCC_APB2ENR Offset*/

#define USART2		(0x40004400)	/*USART2 Base*/

/*USART registers offsets*/

#define USART_SR	(0x00)
#define USART_DR	(0x04)
#define USART_BRR	(0x08)
#define USART_CR1	(0x0C)
#define USART_CR2	(0x10)


#define TC 		(REG(USART2,USART_SR)&(1<<6))	/*Transmission complete bit*/



int main(void) {

	GPIO_EnableClock(A);		/*enable GPIO clock*/ /* 0 for GPIOA and 1 for GPIOB */
	REG(GPIOA,GPIO_AFRL) |= (0x07<<8);		/*AF7 (USART2) on pin 2 */
	GPIO_Init(A, 2,ALTERNATE_FUN,PUSH_PULL);		/*GPIOA pin2 Tx2 configuration */

	REG(RCC,RCC_APB1ENR) |= (1<<17);		/*USART2 peripheral clock Enable*/

	REG(USART2,USART_CR1) |= (1<<13);		/*USART2 Enable*/
	REG(USART2,USART_CR1) |= (1<<3);		/*USART2 transmitter Enable*/
	REG(USART2,USART_CR1) &= ~(1<<15);		/*USART2 configuration: over sampling by 16*/
	REG(USART2,USART_CR1) &= ~(1<<12);		/*USART2 configuration: 1 Start bit, 8 Data bits*/

	REG(USART2,USART_CR2) &= ~(0x3<<12);		/*USART2 configuration 1 Stop bit*/

	REG(USART2,USART_BRR) |= 0x683;				/*USART2 9600 baud rate generation configuration */

	unsigned char string[]="Hello World";	/*array of characters that will be sent */
	unsigned char i;

	for(i=0;string[i] != '\0';i++){			/*loop over the string*/
		REG(USART2,USART_DR) = string[i];	/*put the character in the data register*/
		while(TC==0){		/*Waiting for TC to SET meaning that the data has been transmitted */
			}
	}

    while (1) {

    }
  return 0;
}


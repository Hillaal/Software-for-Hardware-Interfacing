/*
============================================================================
 Name        : MYHEADER.h
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC header file for the macros and the bases and offsets i use
 ============================================================================
*/
#ifndef MYHEADER_H
#define MYHEADER_H

#define A (0) 	/* for GPIO choose*/
#define B (1)	/* for GPIO choose*/


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
#define NVIC_ICER0		(0x180)			/*interrupt Clear enable register 0 Offset*/

void SevenSeg_Init(); /*seven segment initialization function declaration*/
void sevenSeg_display(unsigned char value); /*seven segment display function declaration*/


#endif /* MYHEADER_H */

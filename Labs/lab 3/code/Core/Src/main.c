#include "stm32f401cc_interface.h"

int main(void) {

	int i=0;

	RCC_AHB1ENR |= (1<<0);

	GPIOA_MODER &= ~(3<<0);
	GPIOA_MODER |= (1<<0);
	GPIOA_OTYPER &= ~(1<<0);

	GPIOA_ODR &= ~(1<<0);

  while (1) {

	GPIOA_ODR |=(1<<0);

	for(i=0;i<1000000;i++){}
	GPIOA_ODR &= ~(1<<0);

	for(i=0;i<1000000;i++){}

  }
  return 0;
}

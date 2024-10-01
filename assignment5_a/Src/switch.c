
#include "switch.h"

void SwitchInit()
{
	RCC->AHB1ENR |= BV(GPIO_CLK);
	GPIO_SWITCH->MODER &= ~(BV(SWITCH_PIN<<1) | BV((SWITCH_PIN<<1)+1));
	GPIO_SWITCH->PUPDR &= ~(BV(SWITCH_PIN<<1) | BV((SWITCH_PIN<<1)+1));

	EXTI->FTSR |= BV(SWITCH_EXTI);
	EXTI->IMR |= BV(SWITCH_EXTI);
	SYSCFG->EXTICR[0] &= ~(BV(0)|BV(1)|BV(2)|BV(3));
	NVIC_EnableIRQ(EXTI0_IRQn);
}

volatile uint32_t flag=0;
volatile uint32_t count = 0 ;

void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(SWITCH_EXTI);
	flag=1;
	count++;
}

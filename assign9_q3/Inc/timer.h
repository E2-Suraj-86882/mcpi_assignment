

#ifndef TIMER_H_
#define TIMER_H_

#include"stm32f4xx.h"

#define TCLK 16000000UL
#define PR 16000

void TimerInit(uint32_t ms);
void TIM7_IRQHandler();

extern volatile uint32_t count;
#endif /* TIMER_H_ */

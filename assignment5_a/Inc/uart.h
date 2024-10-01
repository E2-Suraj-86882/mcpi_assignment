


#ifndef UART_H_
#define UART_H_
#include"stm32f4xx.h"

#define UART USART2
#define UART_CLK 17
#define GPIO_UART GPIOA
#define GPIO_CLK 0

#define TX_PIN 2
#define RX_PIN 3

#define UBRR_9600 0x683
#define UBRR_38400 0x1A1
#define UBRR_115200 0x8B

void UartInit(uint32_t baud);
void UartPutch(uint8_t ch);
void UartPuts(char str[]);
#endif /* UART_H_ */

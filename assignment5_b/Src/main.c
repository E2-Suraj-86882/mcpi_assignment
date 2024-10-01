

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"
#include<string.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	int choice;
	char ch[8];
	SystemInit();
	UartInit(9600);
	ledinit(GPIO_GREEN_PIN);
	ledinit(GPIO_ORANGE_PIN);
	ledinit(GPIO_RED_PIN);
	ledinit(GPIO_BLUE_PIN);

	do{
		UartPuts("0.Exit\r\n1.Red Led on\r\n2.Red Led Off\r\n3.Blue Led on\r\n4.Blue Led off\r\nEnter the choice: \r\n");
		UartGets(ch);
		sscanf(ch,"%d",&choice);
		UartPuts(ch);
		switch(choice)
		{
		   case 0:break;
		   case 1:ledon(GPIO_RED_PIN);
			     break;
		   case 2:ledoff(GPIO_RED_PIN);
		   	     break;
		   case 3:ledon(GPIO_BLUE_PIN);
		   	     break;
		   case 4:ledoff(GPIO_BLUE_PIN);
		   	     break;
		   default:
			    UartPuts("Enter valid choice!!\r\n");
		   break;
		}
	}while(choice!=0);
	return 0;
}






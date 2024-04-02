/*
 * main.c
 *
 *  Created on: Apr 2, 2024
 *      Author: jitendra2
 */



#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "uart.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	UartInit(BAUD_9600);

	int cnt = 0;
	char str[16];
	SwitchInit(SWITCH);
	while(1) {

		while(exti0_flag == 0);

		sprintf(str, "CNT=%d", cnt);
		UartPuts( str);

         cnt++;
		exti0_flag = 0;

	}
	return 0;
}

#ifndef _PRINTF_H
#define _PRINTF_H


#include "stdio.h"
#include "stm32f1xx_hal.h"

int fputc(int ch, FILE *f);
int fgetc(FILE *f);


extern UART_HandleTypeDef huart1;

#endif

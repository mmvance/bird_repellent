









#include "printf_reload.h"

#pragma import(__use_no_semihosting)
 
/* 定义 _sys_exit() 以避免使用半主机模式 */
 
void _sys_exit(int x)
 
{
 
    x = x;
 
}
 
/* 标准库需要的支持类型 */
 
struct __FILE
 
{
 
    int handle;
 
};
 
FILE __stdout;



//发送一个字节
int fputc(int ch, FILE *f)
{
		HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
		return ch;
}
//接收一个字节
int fgetc(FILE *f)
{
		uint8_t ch = 0;
		HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
		return ch;
}

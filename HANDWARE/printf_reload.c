









#include "printf_reload.h"

#pragma import(__use_no_semihosting)
 
/* ���� _sys_exit() �Ա���ʹ�ð�����ģʽ */
 
void _sys_exit(int x)
 
{
 
    x = x;
 
}
 
/* ��׼����Ҫ��֧������ */
 
struct __FILE
 
{
 
    int handle;
 
};
 
FILE __stdout;



//����һ���ֽ�
int fputc(int ch, FILE *f)
{
		HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
		return ch;
}
//����һ���ֽ�
int fgetc(FILE *f)
{
		uint8_t ch = 0;
		HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
		return ch;
}

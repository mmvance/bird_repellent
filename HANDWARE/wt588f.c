/*****************************************************
WT588F02B语音芯片驱动程序
Chip:stm32f103c8t6
Coding scheme:GB2312
修改日期:2023/6/14
版本：V1.0
author:vance
All rights reserved
******************************************************/


/*--------------------------------------
模块名称:Line_1A_WT588F_Single(UC8 DDATA)
功能:实现一线串口通信函数
入参: DDATA 为发送数据
出参:
P_DATA 控制IO
-------------------------------------*/
#include "wt588f.h"

void Line_1A_WT588F(uint16_t DDATA)
{
    uint8_t S_DATA, j;
    uint8_t B_DATA;
    S_DATA = DDATA;
    P_DATA_OFF;
    delay_ms(5); //延时5ms
    B_DATA = S_DATA & 0X01;
    for(j = 0; j < 8; j++)
    {
        if(B_DATA == 1)
        {
            P_DATA_ON;
            delay_us(600); //延时600us
            P_DATA_OFF;
            delay_us(200); //延时200us
        }
        else
        {
           P_DATA_ON;
            delay_us(200); //延时200us
            P_DATA_OFF;
            delay_us(600); //延时600us
        }
        S_DATA = S_DATA >> 1;
        B_DATA = S_DATA & 0X01;
        
    }
    P_DATA_ON;
}

/*--------------------------------------
模块名称:Line_2A_WT588F(UC8 DDATA)
功能:实现二线串口通信函数
入参:DDATA 为发送数据
出参:
CLK_2A 时钟线
P_DATA_2A 数据线
-------------------------------------*/

void Line_2A_WT588F(UC8 DDATA)
{
    UC8 S_DATA, j;
    UC8 B_DATA;
    CLK_2A = 1; //拉高CLK
    P_DATA_2A = 1; //拉高DATA
    S_DATA = DDATA;
    CLK_2A = 0; //拉低CLK
    delay_ms(5); //延时5ms
    B_DATA = S_DATA & 0X01;
    for(j = 0; j < 8; j++)
    {
        CLK_2A = 0; //拉低CLK
        P_DATA_2A = B_DATA; //传输数据一位
        delay_us(300); //延时300us
        CLK_2A = 1; //拉高CLK
        delay_us(300); //延时300us
        S_DATA = S_DATA >> 1;
        B_DATA = S_DATA & 0X01;
    }
    P_DATA_2A = 1;
    CLK_2A = 1;
}

/*--------------------------------------
模块名称:List_2A_Play_WT588F()
功能:实现二线串口单字节连码发送函数
入参:
出参:
各码功能详情请见数据手册
-------------------------------------*/
void List_2A_Play_WT588F(void)
{
    Line_2A_WT588F(0xF3);
    delay_ms(2); //延时2ms
    Line_2A_WT588F(0x01);//第一段语音
    delay_ms(5); //延时5ms
    Line_2A_WT588F(0xF3);
    delay_ms(2); //延时2ms
    Line_2A_WT588F(0x02);//第二段语音
    delay_ms(5); //延时5ms
    Line_2A_WT588F(0xF3);
    delay_ms(2); //延时2ms
    Line_2A_WT588F(0x03);//第三段语音
    delay_ms(5); //延时5ms
}


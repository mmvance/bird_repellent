/*****************************************************
WT588F02B����оƬ��������
Chip:stm32f103c8t6
Coding scheme:GB2312
�޸�����:2023/6/14
�汾��V1.0
author:vance
All rights reserved
******************************************************/


/*--------------------------------------
ģ������:Line_1A_WT588F_Single(UC8 DDATA)
����:ʵ��һ�ߴ���ͨ�ź���
���: DDATA Ϊ��������
����:
P_DATA ����IO
-------------------------------------*/
#include "wt588f.h"

void Line_1A_WT588F(uint16_t DDATA)
{
    uint8_t S_DATA, j;
    uint8_t B_DATA;
    S_DATA = DDATA;
    P_DATA_OFF;
    delay_ms(5); //��ʱ5ms
    B_DATA = S_DATA & 0X01;
    for(j = 0; j < 8; j++)
    {
        if(B_DATA == 1)
        {
            P_DATA_ON;
            delay_us(600); //��ʱ600us
            P_DATA_OFF;
            delay_us(200); //��ʱ200us
        }
        else
        {
           P_DATA_ON;
            delay_us(200); //��ʱ200us
            P_DATA_OFF;
            delay_us(600); //��ʱ600us
        }
        S_DATA = S_DATA >> 1;
        B_DATA = S_DATA & 0X01;
        
    }
    P_DATA_ON;
}

/*--------------------------------------
ģ������:Line_2A_WT588F(UC8 DDATA)
����:ʵ�ֶ��ߴ���ͨ�ź���
���:DDATA Ϊ��������
����:
CLK_2A ʱ����
P_DATA_2A ������
-------------------------------------*/

void Line_2A_WT588F(UC8 DDATA)
{
    UC8 S_DATA, j;
    UC8 B_DATA;
    CLK_2A = 1; //����CLK
    P_DATA_2A = 1; //����DATA
    S_DATA = DDATA;
    CLK_2A = 0; //����CLK
    delay_ms(5); //��ʱ5ms
    B_DATA = S_DATA & 0X01;
    for(j = 0; j < 8; j++)
    {
        CLK_2A = 0; //����CLK
        P_DATA_2A = B_DATA; //��������һλ
        delay_us(300); //��ʱ300us
        CLK_2A = 1; //����CLK
        delay_us(300); //��ʱ300us
        S_DATA = S_DATA >> 1;
        B_DATA = S_DATA & 0X01;
    }
    P_DATA_2A = 1;
    CLK_2A = 1;
}

/*--------------------------------------
ģ������:List_2A_Play_WT588F()
����:ʵ�ֶ��ߴ��ڵ��ֽ����뷢�ͺ���
���:
����:
���빦��������������ֲ�
-------------------------------------*/
void List_2A_Play_WT588F(void)
{
    Line_2A_WT588F(0xF3);
    delay_ms(2); //��ʱ2ms
    Line_2A_WT588F(0x01);//��һ������
    delay_ms(5); //��ʱ5ms
    Line_2A_WT588F(0xF3);
    delay_ms(2); //��ʱ2ms
    Line_2A_WT588F(0x02);//�ڶ�������
    delay_ms(5); //��ʱ5ms
    Line_2A_WT588F(0xF3);
    delay_ms(2); //��ʱ2ms
    Line_2A_WT588F(0x03);//����������
    delay_ms(5); //��ʱ5ms
}


#include "stm32f1xx_hal.h"
#include "stdint.h"
#include "sys.h"
#include "delay.h"



#define      VOICE_1                    00H
#define      VOICE_2                    01H

#define      VOICE_3                    02H

#define      VOICE_CYC                  F1H
#define      VOICE_CYC_CURRENT          F2H
#define      VOICE_CYC_MB               F3H

#define      VOICE_STOP                 FEH

#define UC8 unsigned char
#define CLK_2A PBout(10)
#define P_DATA_2A PBout(11)


#define P_DATA_ON HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET)   	//LED0
#define P_DATA_OFF HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);


void Line_1A_WT588F(uint16_t DDATA);
void Line_2A_WT588F(UC8 DDATA);
void List_2A_Play_WT588F(void);




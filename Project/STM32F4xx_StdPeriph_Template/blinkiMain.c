
/**
  ******************************************************************************
  * @file    GPIO/IOToggle/main.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#include "TI_Lib.h"
//#include "tft.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup IOToggle
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void PortA_Output_Init(void)
{
	/* GPIOA Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

/* Configure PA0 PA4 PA5 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void PortF_Output_Init(void)
{
	/* GPIOF Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

/* Configure PF9 PF10 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
}

void PortH_Output_Init(void)
{
	/* GPIOH Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);

/* Configure PH11 PH13 PH14 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOH, &GPIO_InitStructure);	
}

void PortI_Output_Init(void)
{
	/* GPIOI Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);

/* Configure PI4 ... PI7 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOI, &GPIO_InitStructure);	
}

void PortI_Input_Init(void)
{
/* Configure PI9 in input mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOI, &GPIO_InitStructure);
}

void PortC_Input_Init(void)
{
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
/* Configure PC2 in input mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void PortF_Input_Init(void)
{
/* Configure PF6 PF7 PF8 in input mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
}

void PortH_Input_Init(void)
{
/* Configure PH10 PH12 PH15 in input mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOH, &GPIO_InitStructure);
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main2(void)
{
  	SystemCoreClockUpdate();                      	/* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { 	/* SysTick 1 msec interrupts  */
    while (1);                                  	/* Capture error              */
  }
			PortA_Output_Init();
			PortF_Output_Init();
			PortH_Output_Init();
			PortI_Output_Init();
			PortC_Input_Init();
			PortF_Input_Init();
			PortH_Input_Init();
			PortI_Input_Init();
	
//		I2C_Config();
//	  TFT_terminal_on();
//		while(1){
//				TFT_putc('U');	
//		}
	
//		TFT_putc('H');
//	  TFT_putc('a');
//		TFT_putc('l');
//		TFT_putc('l');
//		TFT_putc('o');
	
	
	
			/* Reset PF9 PF10 */
			GPIOF->BSRRH = GPIO_Pin_9 | GPIO_Pin_10;
			/* Reset PH11 PH13 PH14 */
			GPIOI->BSRRH = GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
			/* Reset PI4 ... PI7 */
			GPIOI->BSRRH = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;

	
  while (1)
  {
			/* Set Bits */
			GPIO_SetBits(GPIOA, GPIO_Pin_0);
			Delay(500);
			GPIO_SetBits(GPIOH, GPIO_Pin_11);
			Delay(500);		
			GPIO_SetBits(GPIOH, GPIO_Pin_13);
			Delay(500);
			GPIO_SetBits(GPIOH, GPIO_Pin_14);
			Delay(500);
			GPIO_SetBits(GPIOI, GPIO_Pin_4);
			Delay(500);
			GPIO_SetBits(GPIOI, GPIO_Pin_5);
			Delay(500);
			GPIO_SetBits(GPIOI, GPIO_Pin_6);
			Delay(500);
			GPIO_SetBits(GPIOI, GPIO_Pin_7);
			Delay(500);
			/* Reser Bits */
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			GPIO_ResetBits(GPIOH, GPIO_Pin_11);
			GPIO_ResetBits(GPIOH, GPIO_Pin_13);
			GPIO_ResetBits(GPIOH, GPIO_Pin_14);
			GPIO_ResetBits(GPIOI, GPIO_Pin_4);
			GPIO_ResetBits(GPIOI, GPIO_Pin_5);
			GPIO_ResetBits(GPIOI, GPIO_Pin_6);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);
			Delay(500);

			/* Set and Reset Bits */
			GPIO_SetBits(GPIOA, GPIO_Pin_4);
			GPIO_SetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle " */
			Delay(500);
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle */
			Delay(500);
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			GPIO_SetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle " */
			Delay(500);
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle */
			Delay(500);

			/* Set and Reset Bits */
			GPIO_SetBits(GPIOF, GPIO_Pin_9);
			GPIO_SetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle " */
			Delay(500);
			GPIO_ResetBits(GPIOF, GPIO_Pin_9);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle */
			Delay(500);
			GPIO_SetBits(GPIOF, GPIO_Pin_10);
			GPIO_SetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle " */
			Delay(500);
			GPIO_ResetBits(GPIOF, GPIO_Pin_10);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle */
			Delay(500);
			
			GPIO_SetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle " */

/*	Button read PE0 ... PE7 */
				
		while (GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_9) == Bit_SET);
		GPIO_ResetBits(GPIOI, GPIO_Pin_7);	/* LED zur Kontrolle */
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == Bit_SET);
		GPIO_SetBits(GPIOH, GPIO_Pin_11);

		while (GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_6) == Bit_SET);
		GPIO_SetBits(GPIOH, GPIO_Pin_13);

		while (GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_7) == Bit_SET);
		GPIO_SetBits(GPIOH, GPIO_Pin_14);

		while (GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_8) == Bit_SET);
		GPIO_SetBits(GPIOI, GPIO_Pin_4);

		while (GPIO_ReadInputDataBit(GPIOH, GPIO_Pin_10) == Bit_SET);
		GPIO_SetBits(GPIOI, GPIO_Pin_5);
		
		while (GPIO_ReadInputDataBit(GPIOH, GPIO_Pin_12) == Bit_SET);
		GPIO_SetBits(GPIOI, GPIO_Pin_6);
		
		while (GPIO_ReadInputDataBit(GPIOH, GPIO_Pin_15) == Bit_SET);
		GPIO_SetBits(GPIOI, GPIO_Pin_7);
		Delay(500);

			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			GPIO_ResetBits(GPIOH, GPIO_Pin_11);
			GPIO_ResetBits(GPIOH, GPIO_Pin_13);
			GPIO_ResetBits(GPIOH, GPIO_Pin_14);
			GPIO_ResetBits(GPIOI, GPIO_Pin_4);
			GPIO_ResetBits(GPIOI, GPIO_Pin_5);
			GPIO_ResetBits(GPIOI, GPIO_Pin_6);
			GPIO_ResetBits(GPIOI, GPIO_Pin_7);			
	}
}

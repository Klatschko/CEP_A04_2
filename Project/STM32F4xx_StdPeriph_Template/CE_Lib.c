/**
  ******************************************************************************
  * @file    TI_Board.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    30-August-2012
  * @brief   TI Board Utility
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 HAW-Hamburg</center></h2>
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
/* Here are the definition of the ... */
#include "main.h"
#include "CE_Lib.h"
	
extern void USART1_Init (void);
extern void USART1_Buffer_Init(void);
//extern void Init_IO(void);
//extern void Init_System_Clock(void);
//extern void TFT_Init(void);
//extern void SPI_hardware_send(void);


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
/* Private function prototypes -----------------------------------------------*/
  /**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
  //SPI_hardware_send();
}


void initCEP_Board(void){
  
	//initCEP_GPIO();
  //7Init_System_Clock();
  initIO();
  USART1_Buffer_Init();                          /* init RX / TX buffers             */
  USART1_Init();
  //TFT_Init();
  //Delay(1);  
}


void initIO(void){

	GPIO_InitTypeDef  gpio;
	
	//Enable trace port
	DBGMCU->CR=0x20;
	
	
	/* GPIOI Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	
	// LEDs
	gpio.GPIO_Mode  = GPIO_Mode_OUT;
	gpio.GPIO_OType = GPIO_OType_PP;
	gpio.GPIO_PuPd  = GPIO_PuPd_UP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;

  gpio.GPIO_Pin   = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	
	GPIO_Init(GPIOI, &gpio);
	
	gpio.GPIO_Pin    = GPIO_Pin_11 | GPIO_Pin_13  | GPIO_Pin_14;
	GPIO_Init(GPIOH, &gpio);
	
	gpio.GPIO_Pin    = GPIO_Pin_0;
	GPIO_Init(GPIOA, &gpio);
	

  //Buttons (H15-H12-H10-F8-F7-F6-C2-I9)
	gpio.GPIO_Mode  = GPIO_Mode_IN;
	gpio.GPIO_OType = GPIO_OType_PP;
	gpio.GPIO_PuPd  = GPIO_PuPd_UP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	
	gpio.GPIO_Pin    = GPIO_Pin_15 | GPIO_Pin_12  | GPIO_Pin_10;
  GPIO_Init(GPIOH, &gpio);
	
	gpio.GPIO_Pin    = GPIO_Pin_8 | GPIO_Pin_7  | GPIO_Pin_6;
  GPIO_Init(GPIOF, &gpio);
	
	gpio.GPIO_Pin    = GPIO_Pin_2;
  GPIO_Init(GPIOC, &gpio);
	
	gpio.GPIO_Pin    = GPIO_Pin_9;
  GPIO_Init(GPIOI, &gpio);
	
	
	
}


void setLED( uint32_t pins ){
	 
	 if ( (pins & 0x01)==0x01 ) {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0);
	 }
	 if ( (pins & 0x02)==0x02 ) {
		  GPIO_SetBits(GPIOH, GPIO_Pin_11);
	 }	 
	 if ( (pins & 0x04)==0x04 ) {
		  GPIO_SetBits(GPIOH, GPIO_Pin_13);
	 }	 
	 if ( (pins & 0x08)==0x08 ) {
		  GPIO_SetBits(GPIOH, GPIO_Pin_14);
	 }
	 if ( (pins & 0x10)==0x10 ) {
		  GPIO_SetBits(GPIOI, GPIO_Pin_4);
	 }
	 if ( (pins & 0x20)==0x20 ) {
		  GPIO_SetBits(GPIOI, GPIO_Pin_5);
	 }
	 if ( (pins & 0x40)==0x40 ) {
		  GPIO_SetBits(GPIOI, GPIO_Pin_6);
	 }
	 if ( (pins & 0x80)==0x80 ) {
		  GPIO_SetBits(GPIOI, GPIO_Pin_7);
	 }
}

void resetLED( uint32_t pins ){
	 
	 if ( (pins & 0x01)==0x01 ) {
		  GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	 }
	 if ( (pins & 0x02)==0x02 ) {
		  GPIO_ResetBits(GPIOH, GPIO_Pin_11);
	 }	 
	 if ( (pins & 0x04)==0x04 ) {
		  GPIO_ResetBits(GPIOH, GPIO_Pin_13);
	 }	 
	 if ( (pins & 0x08)==0x08 ) {
		  GPIO_ResetBits(GPIOH, GPIO_Pin_14);
	 }
	 if ( (pins & 0x10)==0x10 ) {
		  GPIO_ResetBits(GPIOI, GPIO_Pin_4);
	 }
	 if ( (pins & 0x20)==0x20 ) {
		  GPIO_ResetBits(GPIOI, GPIO_Pin_5);
	 }
	 if ( (pins & 0x40)==0x40 ) {
		  GPIO_ResetBits(GPIOI, GPIO_Pin_6);
	 }
	 if ( (pins & 0x80)==0x80 ) {
		  GPIO_ResetBits(GPIOI, GPIO_Pin_7);
	 }
}





#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

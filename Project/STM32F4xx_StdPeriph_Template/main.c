/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "CE_Lib.h"
#include "stm32f4xx_tim.h" // fur Timer
#include "stm32f4xx_gpio.h"

/*Sinusgenerator*/
const int tabelle_sinus[257] = {
         0,   804,  1608,  2411,  3212,  4011,  4808,  5602,  6393,  7180,
      7962,  8740,  9512, 10279, 11039, 11793, 12540, 13279, 14010, 14733,
     15447, 16151, 16846, 17531, 18205, 18868, 19520, 20160, 20788, 21403,
     22006, 22595, 23170, 23732, 24279, 24812, 25330, 25833, 26320, 26791,
     27246, 27684, 28106, 28511, 28899, 29269, 29622, 29957, 30274, 30572,
     30853, 31114, 31357, 31581, 31786, 31972, 32138, 32286, 32413, 32522,
     32610, 32679, 32729, 32758, 32768, 32758, 32729, 32679, 32610, 32522,
     32413, 32286, 32138, 31972, 31786, 31581, 31357, 31114, 30853, 30572,
     30274, 29957, 29622, 29269, 28899, 28511, 28106, 27684, 27246, 26791,
     26320, 25833, 25330, 24812, 24279, 23732, 23170, 22595, 22006, 21403,
     20788, 20160, 19520, 18868, 18205, 17531, 16846, 16151, 15447, 14733,
     14010, 13279, 12540, 11793, 11039, 10279,  9512,  8740,  7962,  7180,
      6393,  5602,  4808,  4011,  3212,  2411,  1608,   804,     0,  -804,
     -1608, -2411, -3212, -4011, -4808, -5602, -6393, -7180, -7962, -8740,
     -9512,-10279,-11039,-11793,-12540,-13279,-14010,-14733,-15447,-16151,
    -16846,-17531,-18205,-18868,-19520,-20160,-20788,-21403,-22006,-22595,
    -23170,-23732,-24279,-24812,-25330,-25833,-26320,-26791,-27246,-27684,
    -28106,-28511,-28899,-29269,-29622,-29957,-30274,-30572,-30853,-31114,
    -31357,-31581,-31786,-31972,-32138,-32286,-32413,-32522,-32610,-32679,
    -32729,-32758,-32768,-32758,-32729,-32679,-32610,-32522,-32413,-32286,
    -32138,-31972,-31786,-31581,-31357,-31114,-30853,-30572,-30274,-29957,
    -29622,-29269,-28899,-28511,-28106,-27684,-27246,-26791,-26320,-25833,
    -25330,-24812,-24279,-23732,-23170,-22595,-22006,-21403,-20788,-20160,
    -19520,-18868,-18205,-17531,-16846,-16151,-15447,-14733,-14010,-13279,
    -12540,-11793,-11039,-10279, -9512, -8740, -7962, -7180, -6393, -5602,
     -4808, -4011, -3212, -2411, -1608,  -804,     0
    };

const int tabelle_dreieck[257] = {
		 0,   512,  1024,  1536,  2048,  2560,  3072,  3584,  4096,  4608,
	5120,  5632,  6144,  6656,  7168,  7680,  8192,  8704,  9216,  9728,
 10240, 10752, 11264, 11776, 12288, 12800, 13312, 13824, 14336, 14848,
 15360, 15872, 16384, 16896, 17408, 17920, 18432, 18944, 19456, 19968,
 20480, 20992, 21504, 22016, 22528, 23040, 23552, 24064, 24576, 25088,
 25600, 26112, 26624, 27136, 27648, 28160, 28672, 29184, 29696, 30208,
 30720, 31232, 31744, 32256, 32768, 32256, 31744, 31232, 30720, 30208,
 29696, 29184, 28672, 28160, 27648, 27136, 26624, 26112, 25600, 25088,
 24576, 24064, 23552, 23040, 22528, 22016, 21504, 20992, 20480, 19968,
 19456, 18944, 18432, 17920, 17408, 16896, 16384, 15872, 15360, 14848,
 14336, 13824, 13312, 12800, 12288, 11776, 11264, 10752, 10240,  9728,
	9216,  8704,  8192,  7680,  7168,  6656,  6144,  5632,  5120,  4608,
	4096,  3584,  3072,  2560,  2048,  1536,  1024,   512,     0,  -512,
 -1024, -1536, -2048, -2560, -3072, -3584, -4096, -4608, -5120, -5632,
 -6144, -6656, -7168, -7680, -8192, -8704, -9216, -9728,-10240,-10752,
-11264,-11776,-12288,-12800,-13312,-13824,-14336,-14848,-15360,-15872,
-16384,-16896,-17408,-17920,-18432,-18944,-19456,-19968,-20480,-20992,
-21504,-22016,-22528,-23040,-23552,-24064,-24576,-25088,-25600,-26112,
-26624,-27136,-27648,-28160,-28672,-29184,-29696,-30208,-30720,-31232,
-31744,-32256,-32768,-32256,-31744,-31232,-30720,-30208,-29696,-29184,
-28672,-28160,-27648,-27136,-26624,-26112,-25600,-25088,-24576,-24064,
-23552,-23040,-22528,-22016,-21504,-20992,-20480,-19968,-19456,-18944,
-18432,-17920,-17408,-16896,-16384,-15872,-15360,-14848,-14336,-13824,
-13312,-12800,-12288,-11776,-11264,-10752,-10240, -9728, -9216, -8704,
 -8192, -7680, -7168, -6656, -6144, -5632, -5120, -4608, -4096, -3584,
 -3072, -2560, -2048, -1536, -1024,  -512,     0
};


/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MESSAGE1   "     STM32F2xx      " 
#define MESSAGE2   " Device running on  " 
#define MESSAGE3   "   STM322xG-EVAL    " 

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef timInitStruct;
NVIC_InitTypeDef NVIC_InitStructure_Own;
int cnt = 1;
u8 sysTickCounter;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

void TIM8_UP_TIM13_IRQHandler (void) {
TIM8->SR = ~(1 << 0);
GPIO_ToggleBits(GPIOA,GPIO_Pin_0);		
}

void TIM3_UP_IRQHandler (void) {
	cnt++;
TIM3->SR = ~(1 << 0);
GPIO_ToggleBits(GPIOH,GPIO_Pin_11);		
}

/*++++++++++++++++++++++++++initTimer++++++++++++++++++++++++++++++++++++++++++++++++++*/
void initTimer(void){
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN; // ClockEnable fur Port I
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;  // Takt fuer Timer 8 einschalten
	TIM8->CR1 = 0;  // Timer disabled
	TIM8->CR2 = 0;
	TIM8->PSC = 168000000/5000 - 1;  // Prescaler (5 kHz)
	TIM8->ARR = 5000*0.5 - 1;  // Auto reload register (500msec)
	TIM8->DIER = TIM_DIER_UIE;  // Interrupt einschalten 
	TIM8->CR1 = TIM_CR1_CEN | TIM_CR1_ARPE;  // Enable Timer, enable preload
	
	RCC->APB2ENR |= RCC_APB1ENR_TIM3EN;  // Takt fuer Timer 3 einschalten
	TIM3->CR1 = 0;  // Timer disabled
	TIM3->CR2 = 0;
	TIM3->PSC = 168000000/3809 - 1;  // Prescaler (5 kHz)
	TIM3->ARR = 3809*0.5 - 1;  // Auto reload register (500msec)
	TIM3->DIER = TIM_DIER_UIE;  // Interrupt einschalten 
	TIM3->CR1 = TIM_CR1_CEN | TIM_CR1_ARPE;  // Enable Timer, enable preload 

	}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++initGPIO++++++++++++++++++++++++++++++++++++++++++++++++++*/
void initGPIO(void){
	//PI7 ist LED D23 
	//GPIOI->MODER = (GPIOI->MODER & ~(3 << (7 * 2))) | (GPIO_Mode_OUT << (7 * 2));
	// Speed: 2 MHz 
	//GPIOI->OSPEEDR = (GPIOI->OSPEEDR & ~(3 << (7 * 2))) | (GPIO_Speed_2MHz << (7 * 2));
	// Driver: push-pull
	//GPIOI->OTYPER = (GPIOI->OTYPER & ~(1 << (7))) | (GPIO_OType_PP << (7));
	// No pull-up or pull-down
	//GPIOI->PUPDR = (GPIOI->PUPDR & ~(3 << (7 * 2))) | (GPIO_PuPd_NOPULL << (7 * 2));
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*++++++++++++++++++++++++++initNVIC++++++++++++++++++++++++++++++++++++++++++++++++++*/
void initNVIC(void){
	// NVIC initialisieren
	NVIC_SetPriorityGrouping(2);  // 4 Prioritaetsgruppen jeweils 4 Subprioritaeten
	NVIC_SetPriority(TIM8_UP_TIM13_IRQn, 8);
	NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
	}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	
/*++++++++++++++++++++++++++main++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main(void)
{
  RCC_ClocksTypeDef RCC_Clocks;

	initCEP_Board();	
	
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f2xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f2xx.c file
     */  

  /* SysTick end of count event each 10ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  //SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);	
	
	initTimer();
	//initGPIO();
	initNVIC();

  /* Infinite loop */
  do{
		if ( GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_9) == 0 )
		{
			cnt++;
			GPIO_SetBits(GPIOI,GPIO_Pin_4);
		}
		else
		{
			GPIO_ResetBits(GPIOI,GPIO_Pin_4);
		}
	} while (1);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
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

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

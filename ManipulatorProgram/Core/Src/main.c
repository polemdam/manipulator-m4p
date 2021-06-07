/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "checksum.h"
#include "pid.h"
#include "AOM.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile int pulse;
volatile int pulse_count;
volatile uint8_t flag;
volatile uint8_t inc;
char Message[17];
uint8_t sign;
volatile int adc_flag;
volatile int adc_value;
volatile int dac_value;
volatile int dac_control;
volatile uint16_t dac_index;
volatile uint8_t dac_nperiod;
int step_desired;
cpid_t pid;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

int _write(int file, char *ptr, int len){
	HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, 50);
	return len;
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim10) {
		flag=1;
	}
}
void createMessage(uint16_t joint1, uint16_t joint2, uint16_t joint3){
	uint16_t values[9], len ,crc, help1, help2;

	values[0]=joint1/100;
	values[3]=joint2/100;
	values[6]=joint3/100;

	values[1]=(joint1-values[0]*100)/10;
	values[4]=(joint2-values[3]*100)/10;
	values[7]=(joint3-values[6]*100)/10;

	values[2]=(joint1-values[0]*100-values[1]*10);
	values[5]=(joint2-values[3]*100-values[4]*10);
	values[8]=(joint3-values[6]*100-values[7]*10);
	len=sprintf(Message, "A%d%d%dB%d%d%dC%d%d%d",values[0],values[1],values[2], values[3],values[4],values[5],values[6],values[7],values[8]);
	crc=crc_8(Message, len);
	help1=crc/100;
	help2=(crc-help1*100)/10 ;


	printf("A%d%d%dB%d%d%dC%d%d%d%d%d%d\r\n",values[0],values[1],values[2], values[3],values[4],values[5],values[6],values[7],values[8],
			    help1,help2, crc%10);

}
void setup_uart(){
	HAL_Delay(1000);
	printf("AT+BAUD4");
	HAL_Delay(100);
	printf("AT+NAMEep_bt");
	HAL_Delay(100);
	printf("AT+PIN3498");
	HAL_Delay(100);
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint16_t joint1=0, joint2=0, joint3=0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM10_Init();
  MX_TIM4_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  pid_init(&pid, 7.0f, 0.1f, 0.03f, 10, 1);
  pid.p_max = pid_scale(&pid, 4095);
  pid.p_min = pid_scale(&pid, -4095);
  pid.i_max = pid_scale(&pid, 4095);
  pid.i_min = pid_scale(&pid, -4095);
  pid.d_max = pid_scale(&pid, 4095);
  pid.d_min = pid_scale(&pid, -4095);
  pid.total_max = pid_scale(&pid, 4095);
  pid.total_min = pid_scale(&pid, 0);
  HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim10);

  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);



  HAL_GPIO_WritePin(SEN1_GPIO_Port, SEN1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(SEN2_GPIO_Port, SEN2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(SEN3_GPIO_Port, SEN3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
  //setup_uart();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_Delay(1000);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1,999);
  HAL_Delay(1000);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
  while (1)
  {
	  if(flag == 1){
		  pulse_count=TIM1->CNT;
		  joint1=pulse_count*3/40;
		  pulse_count=TIM2->CNT;
		  joint2=pulse_count*3/40;
		  pulse_count=TIM3->CNT;
		  joint3=pulse_count*3/40;


		  createMessage(joint1,  joint2,  joint3);
		  flag=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

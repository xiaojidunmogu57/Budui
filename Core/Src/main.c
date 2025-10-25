/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ax_ps2.h"

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
JOYSTICK_TypeDef ps2;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  AX_PS2_Init();

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    AX_PS2_ScanKey(&ps2);
    HAL_Delay(10);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    if (ps2.btn1==16) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);//直行
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn1==64) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);//后退
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 800);
    }
    if (ps2.btn1==128) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);//左转
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 800);
    }
    if (ps2.btn1==32) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);//右转
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn1==48) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);//右上
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn1==144) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);//左上
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn1==48) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);//右下
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn1==96) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);//坐下
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 800);
    }
    if (ps2.btn2==4) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);//左旋
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    }
    if (ps2.btn2==8) {
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);//右旋
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 800);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 800);
    }
    if (ps2.btn2==1) {
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
    }
    if (ps2.btn2==2) {
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 2085);
    }
    HAL_Delay(20);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

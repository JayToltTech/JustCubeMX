/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"
#include "app_conf.h"
#include "app_entry.h"
#include "app_common.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OUTPUT_2_DETECT_Pin GPIO_PIN_2
#define OUTPUT_2_DETECT_GPIO_Port GPIOA
#define WAKE_VBUS_Pin GPIO_PIN_1
#define WAKE_VBUS_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_7
#define LED_B_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_5
#define LED_G_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_4
#define LED_R_GPIO_Port GPIOB
#define POWER_DETECT_Pin GPIO_PIN_2
#define POWER_DETECT_GPIO_Port GPIOB
#define OUTPUT_1_DETECT_Pin GPIO_PIN_4
#define OUTPUT_1_DETECT_GPIO_Port GPIOC
#define OUTPUT_1_Pin GPIO_PIN_8
#define OUTPUT_1_GPIO_Port GPIOA
#define OUTPUT_2_Pin GPIO_PIN_9
#define OUTPUT_2_GPIO_Port GPIOA
#define TRACE_USER_Pin GPIO_PIN_7
#define TRACE_USER_GPIO_Port GPIOA
#define TRACE_RI_Pin GPIO_PIN_6
#define TRACE_RI_GPIO_Port GPIOA
#define TRACE_LF_Pin GPIO_PIN_5
#define TRACE_LF_GPIO_Port GPIOA
#define TRACE_RV_Pin GPIO_PIN_4
#define TRACE_RV_GPIO_Port GPIOA
#define TRACE_FW_Pin GPIO_PIN_3
#define TRACE_FW_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

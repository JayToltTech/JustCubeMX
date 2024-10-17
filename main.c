// Copyright Tolt Technologies LLC

#include "main.h"
#include "app_entry.h"
#include "stm32wbxx_hal.h"

#include "version.h"

void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
void MX_GPIO_Init(void);
void MX_DMA_Init(void);
void MX_I2C1_Init(void);
void MX_IPCC_Init(void);
void MX_LPUART1_UART_Init(void);
void MX_RTC_Init(void);
void MX_USB_PCD_Init(void);
void MX_RF_Init(void);

int _IllegalRead(void);

int main(void) {

  // Turn off some optimizations to make debugging easier
  // See: https://interrupt.memfault.com/blog/cortex-m-hardfault-debug
  //      https://community.st.com/t5/stm32-mcus-products/how-to-disable-the-write-buffer-actlr-disdefwbuf/td-p/492742
  uint32_t *ACTLR = (uint32_t *)0xE000E008; *ACTLR |= 2U;
  
  // Turn on the individual fault handlers
  SCB->SHCSR |= (SCB_SHCSR_USGFAULTENA_Msk |
                SCB_SHCSR_BUSFAULTENA_Msk |
                SCB_SHCSR_MEMFAULTENA_Msk);

  HAL_Init();
  MX_APPE_Config();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_IPCC_Init();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_LPUART1_UART_Init();
  MX_RTC_Init();
  MX_USB_PCD_Init();
  MX_RF_Init();
  MX_APPE_Init();

  int countdown = 3 ;
  while (true) {
    MX_APPE_Process();
    
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    HAL_Delay(2500);

    if (--countdown == 0)
      _IllegalRead();
  }
}
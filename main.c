// Copyright Tolt Technologies LLC

#include "main.h"
#include "app_entry.h"
#include "stm32wbxx_hal.h"

#include "version.h"

void main_cubemx(void);
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

  main_cubemx();

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
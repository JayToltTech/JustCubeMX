#include "main.h"
#include "stm32wbxx_hal.h"

static volatile unsigned int _Continue;

void Error_Handler(void)
{
  _Continue = 0;
  __disable_irq();

  HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);

  // Rough code to calculate a delay of 50ms
  const int TicksPerForLoop = 4;
  const int MS50 = 1000 / 50;
  int delayTicks = HSE_VALUE / (MS50 * TicksPerForLoop);
  // HAL_Delay(50); // Cannot use HAL_Delay as __disable_irq() shuts down the systick timer

  while (_Continue == 0) {
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET); // Red
    for (int i = 0; i < delayTicks; i++) {
    }
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    for (int i = 0; i < delayTicks; i++) {
    }
  }
}
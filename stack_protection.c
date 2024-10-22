// Copyright Tolt Technologies LLC
//
// See: https://embeddedartistry.com/blog/2020/05/18/implementing-stack-smashing-protection-for-microcontrollers-and-embedded-artistrys-libc/

#include <stdint.h>
#include "libraries/cubemx_wb5m/Core/Inc/main.h"

#define STACK_CHK_GUARD_VALUE 0xa5f3cc8d

uintptr_t __stack_chk_guard = STACK_CHK_GUARD_VALUE;

__attribute__((weak)) void __stack_chk_fail(void)
{
    Error_Handler();
}
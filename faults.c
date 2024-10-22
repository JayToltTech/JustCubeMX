 #include <string.h>

 int _IllegalRead(void) {
   int r;
   volatile unsigned int* p;
 
   p = (unsigned int*)0x00100000;  // 0x00100000-0x07FFFFFF is reserved on STM32F4
   r = *p;
 
   return r;
 }

// See: https://developer.arm.com/documentation/dui0774/l/Compiler-Command-line-Options/-fstack-protector---fstack-protector-all---fstack-protector-strong---fno-stack-protector
void get_input(char *data)
{
  strcpy(data, "0123456789ABCDEF");
}

int overflow_stack() {
  char buffer[9];
  get_input(buffer);
  return buffer[0];
}


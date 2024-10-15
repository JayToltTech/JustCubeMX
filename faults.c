 int _IllegalRead(void) {
   int r;
   volatile unsigned int* p;
 
   p = (unsigned int*)0x00100000;  // 0x00100000-0x07FFFFFF is reserved on STM32F4
   r = *p;
 
   return r;
 }
#include "leds.h"
#include "uart.h"

void wait(volatile unsigned long dly)
{
    while(dly--)
        ;
}

unsigned char cmd[24];
unsigned int st;
int main(void)
{
    unsigned char num;
    // LED1,LED2,LED3,LED4对应的4根引脚设为输出
    GPFCON = GPF5_out | GPF6_out | GPF7_out | GPF8_out;
    Uart0_Init();

    puts("Init mini boot.\n\r");
    puts("version 0.0.0.1\n\r");
    puts("miniboot:");

    st = 0;

    while(1) {
	num = echo();
	cmd[st++] = num;
	if(num == 13) {
	    puts("miniboot:");
   	    st = 0;
  	}
    }
    return 0;
}



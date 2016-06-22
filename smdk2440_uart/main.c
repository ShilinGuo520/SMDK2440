#include "leds.h"
#include "uart.h"
#include <string.h>


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
			memset(cmd, 0, 24);
  		}
    }
    return 0;
}



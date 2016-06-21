#include "leds.h"
#include "uart.h"

void wait(volatile unsigned long dly)
{
    while(dly--)
        ;
}

int main(void)
{
    unsigned char num = 67;
    // LED1,LED2,LED3,LED4对应的4根引脚设为输出
    GPFCON = GPF5_out | GPF6_out | GPF7_out | GPF8_out;
    Uart0_Init();
    while(1){
        GPFDAT = 0x0; 
	GPFDAT = 0xffff;
	echo();
    }
    return 0;
}



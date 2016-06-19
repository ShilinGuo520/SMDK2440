#include "leds.h"
#include "uart.h"

void wait(volatile unsigned long dly)
{
    while(dly--)
        ;
}

int main(void)
{
    // LED1,LED2,LED3,LED4对应的4根引脚设为输出
    GPFCON = GPF5_out | GPF6_out | GPF7_out | GPF8_out;
    Uart0_Init(115200);
    while(1){
	wait(10000);
        GPFDAT = 0x0;         // 根据i的值，点亮LED1,2,3,4
	wait(10000);
	GPFDAT = 0xffff;
//	putc(97);
    }
    return 0;
}


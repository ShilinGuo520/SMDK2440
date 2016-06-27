#include "leds.h"
#include "uart.h"


void wait(volatile unsigned long dly)
{
    while(dly--)
        ;
}


int strncmp ( char * s1, char * s2, int n) 
{
	if (!n) //n为无符号整形变量;如果n为0,则返回0
		return(0);

		//第一个循环条件：--n,如果比较到前n个字符则退出循环
		//第二个循环条件：*s1,如果s1指向的字符串末尾退出循环
		//第二个循环条件：*s1 == *s2,如果两字符比较不等则退出循环

	while (--n && *s1 && *s1 == *s2)
	{
		s1++;//S1指针自加1,指向下一个字符
		s2++;//S2指针自加1,指向下一个字符
	}

	return( *s1 - *s2 );//返回比较结果
}


void cmd_rc(unsigned char *cmd)
{
	if(strncmp(cmd, "sdram", 5)) {
		mem_test();
	} else if(strncmp(cmd, "xmodem", 6)) {
		Xmodem_test();
	} else {

	}
}

unsigned char cmd[24];
unsigned int st;
int main(void)
{
    unsigned char num;
    GPFCON = GPF5_out | GPF6_out | GPF7_out | GPF8_out;
    Uart0_Init();

	mem_test();

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



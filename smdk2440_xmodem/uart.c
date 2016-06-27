#include "uart.h"

void Uart0_Init()
{ 
	GPHCON&=~((3<<4)|(3<<6));//GPH2--TXD0;GPH3--RXD0
	GPHCON|=((2<<4)|(2<<6));//设置GPH2、GPH3为TXD0、RXD0功能 
	GPHUP=0x00;//上拉电阻使能 
	ULCON0|=0x03;//设置数据发送格式：8个数据位，1个停止位，无校验位
	UCON0=0x05; //发送模式和接收模式都使用查询模式 
	UBRDIV0 = (int)UART_BRD;
	URXH0=0;//将URXH0清零
} 

void putc(unsigned char c)
{
	UTXH0=c; 
	while(!(UTRSTAT0&(1<<2)));//等待发送完成 
}

void puts(unsigned char *s)  
{
	while(*s != 0) 
		putc(*s++);
}


unsigned char getc(void)
{ 
	unsigned char c; 
	while(!(UTRSTAT0&(1<<0)));//查询是否接收到有效数据 
	c=URXH0;
	return c;
}

unsigned char echo(void)
{
        unsigned char c;
        while(!(UTRSTAT0&(1<<0)));//查询是否接收到有效数据 
        c=URXH0;
	if(c == 13) {
	    putc(10);
	    putc(c);
	}
	else if(c == 8) {
	    putc(c);
            putc(' ');
	    putc(c);
	}
	else
            putc(c);
        return c;
}

#include "uart.h"

#define PCLK 50000000 
#define UART_BRD (int)((PCLK/( 115200 * 16))-1) 

#define GPHCON 	(*(volatile unsigned long *)0x56000070)
#define GPHUP	(*(volatile unsigned long *)0x56000078)

#define ULCON0	(*(volatile unsigned long *)0x50000000)
#define UCON0	(*(volatile unsigned long *)0x50000004)
#define UBRDIV0	(*(volatile unsigned long *)0x50000028)
#define URXH0	(*(volatile unsigned long *)0x50000024)
#define UTXH0   (*(volatile unsigned long *)0x50000020)
#define UTRSTAT0   (*(volatile unsigned long *)0x50000010)

/***********************************************
*函数名称：voidUart0_Init(unsigned int baudrate)
*参数说明：baudrate：波特率*返回值：无*全局变量:无*功 能：对UART0进行初始化 
************************************************/
void Uart0_Init(unsigned int baudrate)
{ 
	GPHCON&=~((3<<4)|(3<<6));//GPH2--TXD0;GPH3--RXD0
	GPHCON|=((2<<4)|(2<<6));//设置GPH2、GPH3为TXD0、RXD0功能 
	GPHUP=0x00;//上拉电阻使能 
	ULCON0|=0x03;//设置数据发送格式：8个数据位，1个停止位，无校验位
	UCON0=0x05; //发送模式和接收模式都使用查询模式 
	UBRDIV0=UART_BRD;//设置波特率，其中波特率作为一个参数传递到该初始化函 数 
	URXH0=0;//将URXH0清零
} 

/***********************************************
*函数名称：voidputc(unsignedcharc) 
*参数说明：c:通过串口接收到的字符，注意这里是8位数据*返回值：无
*全局变量:无
*功能：将通过串口接收到的字符发送给PC机并显示在
* 串口调试工具。 
************************************************/
void putc(unsigned char c){
	UTXH0=c; 
	while(!(UTRSTAT0&(1<<2)));//等待发送完成 
} 
/***********************************************
*函数名称：unsignedchargetc(void)
*参数说明：无 
*返回值：c:通过串口接收到的字符，注意这里是8位数据
*全局变量:无
*功 能：接收并保存通过串口输入的数据 
************************************************/
unsigned char getc(void)
{ 
	unsigned char c; 
	while(!(UTRSTAT0&(1<<0)));//查询是否接收到有效数据 
	c=URXH0;
	return c;
}

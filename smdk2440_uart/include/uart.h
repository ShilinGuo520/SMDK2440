#ifndef __UART_H__
#define __UART_H__ 

#define PCLK            100000000 
#define baudrate        9600
#define UART_BRD ((PCLK/( baudrate * 16))-1) 

#define GPHCON  (*(volatile unsigned long *)0x56000070)
#define GPHUP   (*(volatile unsigned long *)0x56000078)

#define ULCON0  (*(volatile unsigned long *)0x50000000)
#define UCON0   (*(volatile unsigned long *)0x50000004)
#define UBRDIV0 (*(volatile unsigned long *)0x50000028)
#define URXH0   (*(volatile unsigned long *)0x50000024)
#define UTXH0   (*(volatile unsigned long *)0x50000020)
#define UTRSTAT0   (*(volatile unsigned long *)0x50000010)

void Uart0_Init();
void putc(unsigned char c); 
unsigned char getc(void);

#endif

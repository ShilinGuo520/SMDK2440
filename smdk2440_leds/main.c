
#define GPBCON (*(volatile unsigned long *)0x56000050) // 物理地址0x56000010
#define GPBDAT (*(volatile unsigned long *)0x56000054) // 物理地址0x56000014

/*
 * LED1,LED2,LED4对应GPB5、GPB6、GPB7、GPB8
 */
#define    GPB5_out    (1<<(4*2))
#define    GPB6_out    (1<<(5*2))
#define    GPB7_out    (1<<(6*2))
#define    GPB8_out    (1<<(7*2))

/*
 * wait函数加上“static inline”是有原因的，
 * 这样可以使得编译leds.c时，wait嵌入main中，编译结果中只有main一个函数。
 * 于是在连接时，main函数的地址就是由连接文件指定的运行时装载地址。
 * 而连接文件mmu.lds中，指定了leds.o的运行时装载地址为0xB4004000，
 * 这样，head.S中的“ldr pc, =0xB4004000”就是跳去执行main函数。
 */
void wait(volatile unsigned long dly)
{
    while(dly--)
	;
}


int main(void)
{
    // LED1,LED2,LED3,LED4对应的4根引脚设为输出
    GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out;
    while(1){
	wait(10000);
        GPBDAT = 0x0;         // 根据i的值，点亮LED1,2,3,4
	wait(10000);
	GPBDAT = 0xffff;
    }
    return 0;
}



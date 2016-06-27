#define GPFCON (*(volatile unsigned long *)0x56000050) // 物理地址0x56000010
#define GPFDAT (*(volatile unsigned long *)0x56000054) // 物理地址0x56000014

/*
 * LED1,LED2,LED4对应GPB5、GPB6、GPB7、GPB8
 */
#define    GPF5_out    (1<<(4*2))
#define    GPF6_out    (1<<(5*2))
#define    GPF7_out    (1<<(6*2))
#define    GPF8_out    (1<<(7*2))


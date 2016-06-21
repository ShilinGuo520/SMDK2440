
# define pWTCON		0x53000000
# define INTMSK		0x4A000008	/* Interupt-Controller base addresses */
# define INTSUBMSK	0x4A00001C
# define CLKDIVN	0x4C000014	/* clock divisor register */
# define MPLLCON	0x4C000004	/* MPLL configuration register */

.text
.global _start
_start:
    ldr R1, =0x53000000
    mov R0,#0x0  
    str R0, [R1]  

/*
 * mask all IRQs by setting all bits in the INTMR - default
 */
    mov	r1, #0xffffffff
    ldr	r0, =INTMSK
    str	r1, [r0]
    ldr	r1, =0x7fff
    ldr	r0, =INTSUBMSK
    str	r1, [r0]

    /* FCLK:HCLK:PCLK = 1:4:4 */
    ldr r0, =CLKDIVN
    mov r1, #4
    str r1, [r0]

    /* default FCLK is 400 MHz ! */
    ldr     R0, =0x0005C011
    ldr     R1, =MPLLCON
    str     R0,[R1]

    ldr SP,=1024*4
    bl main

halt_loop:
    b halt_loop


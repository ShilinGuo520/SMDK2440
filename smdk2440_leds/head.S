.text
.global _start
_start:
    ldr R1, =0x53000000
    mov R0,#0x0  
    str R0, [R1]  
  
    ldr SP,=1024*4
    bl main

halt_loop:
    b halt_loop


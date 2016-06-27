
#include "uart.h"

#define SOH 0x01
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
#define CAN 0x18


void Xmodem_test()
{
	unsigned char rx_num;
	unsigned char rx_num_blk;
	unsigned char rx_buff[128];
	int time;
	int i;
		
	putc(NAK);

	while(1) {
		time ++ ;
		if(getc() == SOH)
			break;
		if(time > 3000){
			putc(NAK);
			time = 0;
		}
	}

	while(1) {
		rx_num = getc();
		if(rx_num == EOT) {
			rx_num = 256 - rx_num_blk;
			break;
		}

		rx_num_blk = getc();
		if(rx_num == (256-rx_num_blk)){
			for(i = 0; i < 128; i++) {
				rx_buff[i] = getc();
			}
			putc(ACK);
		}
		else
			putc(NAK);
	}

	putc(ACK);
	getc();
	putc(ACK);

	return rx_num;
}



#define SOH 01H
#define EOT 04H
#define ACK 06H
#define NAK 15H
#define CAN 18H


void Xmodem(unsigned char * buff)
{
	unsigned char rx_num;
	unsigned char rx_num_blk;
	unsigned char rx_buff[128];
	int time;
	int i;
	if(!(UTRSTAT0&(1<<0)))
		putc(NAK);

	while(1) {
		time ++ ;
		if(URXH0 == SOH)
			break;
		if(time > 30000){
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


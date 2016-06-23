

void mem_test()
{
	unsigned int n;
	unsigned char *p;
	p = 0x30000000;

	n = 26;
	while(n--) {
		*p = 90 + n;
		p++;
	}

	p = 0x30000000;

	n = 26;
	while(n--) {
		putc(*p);
		p++;
	}
}


void code_to_mem()
{
	unsigned char *flash, *sdram;
	long st;
	flash = 0x0;
	sdram = 0x30000000;

	for(st = 0; st < 0x20000; st++) {
		*sdram = *flash;
		sdram++;
		flash++;
	}
}


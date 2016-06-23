

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



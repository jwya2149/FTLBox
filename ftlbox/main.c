#include "ftl_box.h"

/*
 * Number of blocks: 151552
 * Number of pages per block: 128
 * Number of pages: 19398656 (=151552*128) (Phyiscal key space)
 * Page size: 4 Byte (integer)
 * Key range: 0 ~ 16777215 (Logical key space)
 */

/* 
 * Argument to main: trace file (trace1.bin, trace2.bin, trace3.bin
 * trace: A large sequence of 1-byte type('r' or 'w'), 4-byte key, 4-byte value
 * You can input your arbitrary trace 
 */

/*
 * Trace file format
 * File size: 1.3GB (total 3 files)
 * Total cycle: 11 times (sequential init + repeat 10 times)
 * No duplicate values (Not important)
 */

/*
 * trace1.bin: sequential key
 * cycle 1: write 0 ~ 16,777,215 keys sequentially
 * cycle 2: read/write(5:5) 0 ~ 16,777,215 keys sequentailly
 * repeat cycle 2 10 times
 */

/*
 * trace2.bin: random key
 * cycle 1: write 0 ~ 16,777,215 keys sequentially
 * cycle 2: read/write(5:5) 0 ~ 16,777,215 keys randomly
 * repeat cycle 2 10 times
 */

/*
 * trace3.bin: random & skewed key
 * cycle 1: write 0 ~ 16,777,215 keys sequentially
 * cycle 2: read/write(5:5) 0 ~ 16,777,215 keys randomly (20% of keys occupy 80%)
 * repeat cycle 2 10 times
 */

/*
 * Implement your own FTL (Page FTL or Anything else)
 * This main function starts FTLBox and reads traces
 */

int main(int argc, char *argv[])
{
	FILE * fp;
	char *buf;
	int trace_key, trace_value;

	if (argc > 2 || argc <= 1) {
		puts("argument error");
		abort();
	}
	if (!fopen(argv[1], "rt")) {
		puts("trace open error");
		abort();
	}
	printf("Input Trace File : %s\n", (argv[1])); 

	fp = fopen(argv[1], "rb");
	buf = (char*)malloc(sizeof(char) * 1);

	box_create();

	/* Read Trace file */
	while (1) {
		if (!fread((void*)buf, 1, 1, fp)) {
			if (feof(fp)) {
				puts("trace eof");
				break;
			}
			puts("fread error");
			abort();
		}

		if (*buf == 'w') {
			fread((void*)&trace_key, 4, 1, fp);
			fread((void*)&trace_value, 4, 1, fp);

			/* Trace check */
			printf("type: %c, key: %d, value: %d\n", *buf, trace_key, trace_value);

			/* Implement your page_write function */
			//page_write(trace_key, trace_value);
		}
		else if (*buf == 'r') {
			fread((void*)&trace_key, 4, 1, fp);
			
			/* Trace check */
			printf("type: %c, key: %d, value: %d\n", *buf, trace_key, trace_value);

			/* Implement your page_read function */
			//page_read(trace_key, trace_value);
		}
		else {
			puts("trace error");
			abort();
		}
	}

	puts("ftl_box end");
	fclose(fp);
	box_destroy();

	return 0;
}

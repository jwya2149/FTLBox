#include "ftl_box.h"

/*
 * Number of blocks: 151552
 * Number of pages per block: 128
 * Number of pages: 19398656 (=151552*128)
 * Page size: 4 Byte (integer)
 * Key range: 0 ~ 16777215
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

			/* Implement your page_write function */
			//page_write(trace_key, trace_value);
		}
		else if (*buf == 'r') {
			fread((void*)&trace_key, 4, 1, fp);
			
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

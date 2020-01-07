#ifndef __H_FTL_BOX__
#define __H_FTL_BOX__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOB (151552)
#define PPB (128)
#define NOP ((NOB)*(PPB)) // 19398656
#define PAGESIZE (4)

#define NUMKEY 16777216

#define NIL -1
#define PAGE_READ 0
#define PAGE_WRITE 1
#define BLOCK_ERASE 2

typedef struct flash_block {
	int32_t min_page;
	int32_t *pages;
	int32_t erase_cnt;
} _flash_block;

static inline void error_print(int8_t op_type) {
	printf("[ERROR] ");
	switch (op_type) {
		case PAGE_READ:
			printf("flash_page_read error: ");
			break;
		case PAGE_WRITE:
			printf("flash_page_write error: ");
			break;
		case BLOCK_ERASE:
			printf("flash_block_erase error: ");
			break;
	}
}

static inline void range_check(int32_t b_idx, int32_t p_idx, int8_t op_type) {

	if ((b_idx < 0) || (b_idx >= NOB)) {
		error_print(op_type);
		printf("block index range\n");
		abort();
	}
	if (op_type != BLOCK_ERASE) {
		if ((p_idx < 0) || (p_idx >= PPB)) {
			error_print(op_type);
			printf("page index range\n");
			abort();
		}
	}
}

static inline void write_collision(int32_t b_idx, int32_t p_idx) {
	error_print(PAGE_WRITE);
	printf("write collision (b_idx: %d, p_idx: %d)\n", b_idx, p_idx);
	abort();
}

int32_t box_create();
int32_t box_destroy();
int32_t flash_page_write(int32_t b_idx, int32_t p_idx, int32_t value);
int32_t flash_page_read(int32_t b_idx, int32_t p_idx);
int32_t flash_block_erase(int32_t b_idx);

#endif // !__H_FTL_BOX__

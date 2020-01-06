#include "ftl_box.h"

_flash_block *flash_blocks;

int32_t box_create() {
	flash_blocks = (_flash_block*)malloc(sizeof(_flash_block) * NOB);
	for (int i=0; i<NOB; i++) {
		flash_blocks[i].min_page = -1;
		flash_blocks[i].pages = (int32_t*)malloc(sizeof(int32_t) * PPB);
		memset(flash_blocks[i].pages, 255, sizeof(int32_t) * PPB);
	}
}
	
int32_t box_destroy() {
	for (int i=0; i<NOB; i++) {
		free(flash_blocks[i].pages);
	}
	free(flash_blocks);
	return 1;
}

int32_t flash_page_read(int32_t b_idx, int32_t p_idx) {
	range_check(b_idx, p_idx, PAGE_READ);
	return flash_blocks[b_idx].pages[p_idx]; // if -1, read empty page..
}

int32_t flash_page_write(int32_t b_idx, int32_t p_idx, int32_t value) {
	range_check(b_idx, p_idx, PAGE_WRITE);
	if (p_idx > flash_blocks[b_idx].min_page) {
		flash_blocks[b_idx].pages[p_idx] = value;
		flash_blocks[b_idx].min_page = p_idx;
		return 1;
	}
	else {
		write_collision(b_idx, p_idx);
		return 0;
	}
}


int32_t flash_block_erase(int32_t b_idx) {
	range_check(b_idx, NIL, BLOCK_ERASE);
	flash_blocks[b_idx].min_page = -1;
	memset(flash_blocks[b_idx].pages, 255, sizeof(int32_t) * PPB);
	return 1;
}


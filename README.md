# FTLBox
A Very Very Simple FTL drawing paper

FTLBox is derived from DGIBox, one of projects in DGIST Class: Computer Algorithms (SE380)


## Topic
Develop an algorithms providing basic operations (write & read) that operate on a pseudo flash memory simulator, FTLBox.

FTLBox is composed of a large number of small blocks
	Each block looks like an array, indexed by an integer number

Each block provides simple three operations:
	flash_page_write(block index, page index, value)
	flash_page_read(block index, page index, value)
	flash_block_erase(block index)

In this setting, each block has 128 pages and one page has only one 4-byte integer value.
There are 151552 blocks and the target key value is 0~16777215 integers.
Therefore, total pages can have 19,398,656 integers which are larger than key ranges.
If the trace is a multiple number of full sequential (or random) writes for all key ranges, 
   out-of-place updates and GCs should be implemented depending on the characteristics of the NAND flash memory.

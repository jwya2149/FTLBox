# FTLBox
A Very Very Simple FTL simulator

FTLBox is derived from DGIBox, one of projects in DGIST Class: Computer Algorithms (SE380)


## Topic
Develop an algorithms providing basic operations (write & read) that operate on a pseudo flash memory simulator, FTLBox.

FTLBox is composed of a large number of small blocks
	Each block looks like an array, indexed by an integer number

Each block provides simple three operations:
	flash_page_write(block index, page index, value)
	flash_page_read(block index, page index, value)
	flash_block_erase(block index)

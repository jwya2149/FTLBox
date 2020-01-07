# FTLBox
A Very Very Simple FTL drawing paper

FTLBox is derived from DGIBox, one of projects in DGIST Class: Computer Algorithms (SE380)


## Topic
Develop an algorithms providing basic operations (write & read) that operate on a pseudo flash memory simulator, FTLBox.

FTLBox is composed of a large number of small blocks.	Each block looks like an array, indexed by an integer number.

FTLBox provides simple three operations:  
- flash_page_write(block index, page index, value)
- flash_page_read(block index, page index, value)
- flash_block_erase(block index)

In this setting, each block has 128 pages and one page has only one 4-byte integer value.
There are 151552 blocks and the target key value is 0~16777215 integers.
Therefore, total pages can have 19,398,656 integers which are larger than key ranges.  
Key ranges in trace files (0 ~ 16,777,215) represents the space of logical page addresses and Page ranges in FTLBox (0 ~ 19,398,656) represents the space of physical page addresses in flash storage device.  

Out-of-place updates and GCs should be implemented depending on the characteristics of the NAND flash memory (see Lecture note: Storage-Firmware Part)


## Todo
Implement your own page_read() and page_write() function with data structures for FTL.  
You should implement your FTL so that all traces work well.  


## Current FTLBox setting
  Number of blocks: 151552  
  Number of pages per block: 128  
  Number of pages: 19398656 (=151552*128) (Phyiscal key space)  
  Page size: 4 Byte (integer)  
  Key range: 0 ~ 16777215 (Logical key space)  
  
  Argument to main: trace file (trace1.bin, trace2.bin, trace3.bin  
  trace: A large sequence of 1-byte type('r' or 'w'), 4-byte key, 4-byte value  
  You can input your arbitrary trace  
 
  Trace file format  
  File size: 1.3GB (total 3 files)  
  Total cycle: 11 times (sequential init + repeat 10 times)  
  No duplicate values (Not important)  
 
  trace1.bin: sequential key  
  cycle 1: write 0 ~ 16,777,215 keys sequentially  
  cycle 2: read/write(5:5) 0 ~ 16,777,215 keys sequentailly  
  repeat cycle 2 10 times  
 
  trace2.bin: random key  
  cycle 1: write 0 ~ 16,777,215 keys sequentially  
  cycle 2: read/write(5:5) 0 ~ 16,777,215 keys randomly  
  repeat cycle 2 10 times  
 
  trace3.bin: random & skewed key  
  cycle 1: write 0 ~ 16,777,215 keys sequentially  
  cycle 2: read/write(5:5) 0 ~ 16,777,215 keys randomly (20% of keys occupy 80%)  
  repeat cycle 2 10 times

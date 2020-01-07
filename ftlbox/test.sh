#!/bin/bash

make clean

echo "make FTLBox.." 
make

echo "input trace1 into FTL.."
./ftl trace/trace1.bin

echo "bye bye!"

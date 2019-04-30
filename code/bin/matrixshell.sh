#!/bin/sh
for i in {1..10}
do
    COTTON_WORKERS=4 ; ./Matrix.e $i 2000
    echo $i
done

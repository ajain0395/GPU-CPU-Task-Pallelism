#!/bin/sh
for i in {1..10}
do
    COTTON_WORKERS=8 ; ./Matrix.e
    echo $i
done

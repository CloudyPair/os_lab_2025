#!/bin/bash
sum=0
for n in "$@"; do
    sum=$(echo "$sum + $n" | bc)
done
echo $# $(echo "$sum / $#" | bc -l)
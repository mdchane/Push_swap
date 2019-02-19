#!/bin/bash

rm res
echo -e '\033[0mGetting an average in a range from 0 to 29'
ERR=0
for i in `seq 1 100`;
        do
                ARG=`ruby -e "puts (0..74).to_a.shuffle.join(' ')"`
                ./push_swap $ARG | wc -l >> res
done

./a.out res
rm res

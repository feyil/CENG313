#!/bin/bash

read X  
max=$X # first input is largest 

while [ "${X}" != "end" ] #loop until X becomes end
do
    if [ $X -gt $max ] # check whether input is greater than current max
    then
	max=$X # update max variable
    fi

    read X # take input from command line
done

echo "Maximum : ${max}" # print result

#fey

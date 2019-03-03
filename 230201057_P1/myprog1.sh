#!/bin/bash

#take file name from $1 and read file with cat command
content=$(cat $1) 

for i in $content
do
    line=""
    while [ $i -ne 0 ] # loop until i equals 0
    do
	line="${line}*" #concatenate stars
	i=$(expr $i - 1) #decrement i 
    done
    echo "${line}" #print completed line
done

#I assume file is in valid format

#fey

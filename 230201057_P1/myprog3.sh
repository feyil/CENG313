#/bin/bash

if [ -z "$1" ] #check whether argument is given for $1 or not
then
    find . -size 0 -delete #find zero length files in current directory(.)
else
    find $1 -size 0 -delete #find zero length files in given directory
fi

# In first look I thought to do it with wc but when I searched in the internet it will be more easy doing with find.

#fey


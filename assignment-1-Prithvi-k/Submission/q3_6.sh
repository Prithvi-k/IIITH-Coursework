#!/bin/bash

( (cat words.txt; echo;) | while read word; do
    uniqueLettersNumber=`echo $word | grep -o . | sort | uniq | wc -l`;
    if [ $uniqueLettersNumber == ${#word} ]
    then
        echo "$word"
    fi
    done) >> output_3.txt

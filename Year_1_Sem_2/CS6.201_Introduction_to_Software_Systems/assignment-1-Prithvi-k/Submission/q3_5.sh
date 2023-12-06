#!/bin/bash

( (cat words.txt; echo;) | while read word;
    do 
    if [[ ! -z "$word" && "$word" != " " ]]; then 
        [ $word == `echo $word | rev` ] && echo "$word";
    fi
done;) >> output_3.txt

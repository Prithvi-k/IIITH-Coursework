#!/bin/bash

INPUT_FILE="$1"
OUTPUT_FILE="$2"
max_length=0

if [ ! -f "$INPUT_FILE" ]; then
    exit 1
fi

echo "" >> $INPUT_FILE

while read -r word
do
    len=${#word}
    if (( len > max_length ))
    then
        max_length=$len
    fi
done < "$INPUT_FILE"

count_vowels()
{
    echo $(grep -o '[aeiou]' <<< "$1" | wc -l)
}

(for (( c=0; c<=$max_length; c++ ))
do
    count=0
    (while read -r word && [ -n "$word" ];
    do
        if (( $(count_vowels "$word") == c ))
        then
            count=$((count+1))
            echo "$word"
        fi
    done < "$INPUT_FILE"
    if (( count > 0 && c != 0 ))
    then
        echo ""
    fi
    ) > temp.txt

    sort temp.txt

done) >> "$OUTPUT_FILE"

rm temp.txt
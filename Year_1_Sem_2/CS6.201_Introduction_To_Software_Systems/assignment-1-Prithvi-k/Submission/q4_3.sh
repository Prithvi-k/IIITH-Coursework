#!/bin/bash

INPUT_FILE="$1"
OUTPUT_FILE="$2"

if [ ! -f "$INPUT_FILE" ]; then
    exit 1
fi

(cat "$INPUT_FILE"; echo;) | while read word;do
    tr '[:upper:]' '[:lower:]' <<< "$word"
    done >> "$OUTPUT_FILE"
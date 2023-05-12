#!/bin/bash

INPUT_FILE="$1"
OUTPUT_FILE="$2"

if [ ! -f "$INPUT_FILE" ]; then
    exit 1
fi

grep -E "\b\w{3,}\b" "$INPUT_FILE" >> "$OUTPUT_FILE"
#!/bin/bash

INPUT_FILE="$1"
OUTPUT_FILE="$2"

if [ ! -f "$INPUT_FILE" ]; then
    exit 1
fi

grep -E "\b[^j[:space:]]+\b" "$INPUT_FILE" >> "$OUTPUT_FILE"
#!/bin/bash

grep -w "s" words.txt >> output_3.txt
grep -E "^s[^a]\w*" words.txt >> output_3.txt
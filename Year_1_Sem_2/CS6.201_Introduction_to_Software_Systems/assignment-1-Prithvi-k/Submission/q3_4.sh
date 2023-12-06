#!/bin/bash

grep -E "\w*[aeiouAEIOU][^aeiouAEIOU\W]{3}[aeiouAEIOU]\w*|^[^aeiouAEIOU\W]{3}[aeiouAEIOU\W]\w*|\b^[^aeiouAEIOU\W]{3}\b|\w*[aeiouAEIOU\W][^aeiouAEIOU\W]{3}$" words.txt >> output_3.txt
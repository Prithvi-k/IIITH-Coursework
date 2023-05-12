#!/bin/bash

echo "fname,lname,mobile,office" > contacts.csv # create file and write headers

while read -r line; do
  # generate random values for each field
  fname=$(cat /dev/urandom | tr -dc 'a-zA-Z' | fold -w 10 | head -n 1)
  lname=$(cat /dev/urandom | tr -dc 'a-zA-Z' | fold -w 10 | head -n 1)
  mobile=$(shuf -i 1000000000-9999999999 -n 1)
  office=$(cat /dev/urandom | tr -dc 'a-zA-Z' | fold -w 10 | head -n 1)

  # check if each field is unique
  if ! grep -q "^$fname,$lname,$mobile,$office$" contacts.csv; then
    echo "$fname,$lname,$mobile,$office" >> contacts.csv # add line to file
  fi
done < <(seq 1 100) # generate 1000 unique lines

echo "contacts.csv file generated successfully!"

#!/bin/bash

if test "$1" = ""
then
  echo "No first value"
	exit
fi

if test "$2" = ""
then
	echo "No second value"
	exit
fi

gcd() {
  if [ $2 -eq 0 ]; then
    echo $1
  else
    gcd $2 $(($1 % $2))
  fi
}

lcm() {
  product=$(($1 * $2))
  gcd_result=$(gcd $1 $2)
  echo $(($product/$gcd_result))
}

gcd_result=$(gcd $1 $2)
echo "GCD: $gcd_result"

lcm_result=$(lcm $1 $2)
echo "LCM: $lcm_result"
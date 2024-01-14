#!/bin/bash

if test "$1" == ""
then
	echo "No input IP address"
	exit
fi

IP_address=$1

D2B=({0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1})
converted_binary_string=""

for ((i=1;i<=4;i++))
do
    if ((i==4))
	then
		converted_binary_string+="$(echo "$((10#${D2B[$(echo $IP_address | cut -d '.' -f $i)]}))")"
		break
	fi
	converted_binary_string+="$(echo "$((10#${D2B[$(echo $IP_address | cut -d '.' -f $i)]})) ")"
done

echo "$converted_binary_string"
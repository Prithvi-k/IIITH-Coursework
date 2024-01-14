#!/bin/bash

echo -n "Enter Name: "
read name

echo -n "Enter DOB: "
read month year

current_year=`date +%Y`
current_month=`date +%m`

age=$(( (current_year - $((10#$year))) * 12 + (current_month - $((10#$month))) ))

echo "Hello $name, your age is $age months"

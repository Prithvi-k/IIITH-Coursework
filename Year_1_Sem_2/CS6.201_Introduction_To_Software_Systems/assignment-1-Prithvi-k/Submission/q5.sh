#!/bin/bash

print_tree() {
  local directory=$1
  local prefix=$2

  local elements=($(ls $directory))
  local count=${#elements[@]}

  for x in "${!elements[@]}"; do 
    local element="${elements[$x]}"
    local element_prefix="|   "
    local curr_prefix="|-- "

    echo "${prefix}${curr_prefix}$element"
    [ -d "$directory/$element" ] && print_tree "$directory/$element" "${prefix}$element_prefix"
  done
}

print_hidden(){
  local directory=$1
  local prefix=$2

  local elements=($(ls -a $directory))
  local count=${#elements[@]}

  for x in "${!elements[@]}"; do 
    local element="${elements[$x]}"
    local element_prefix="|   "
    local curr_prefix="|-- "

    echo "${prefix}${curr_prefix}$element"
    [ -d "$directory/$element" ] && print_tree "$directory/$element" "${prefix}$element_prefix"
  done
}

print_rev() {
  local directory=$1
  local prefix=$2

  local elements=($(ls -r $directory))
  local count=${#elements[@]}

  for x in "${!elements[@]}"; do 
    local element="${elements[$x]}"
    local element_prefix="|   "
    local curr_prefix="|-- "

    echo "${prefix}${curr_prefix}$element"
    [ -d "$directory/$element" ] && print_tree "$directory/$element" "${prefix}$element_prefix"
  done
}

print_by_size(){
  local directory=$1
  local prefix=$2

  cd $directory
  local elements=($(ls -lSr  | awk '{print $9}'))
  local count=${#elements[@]}

  for x in "${!elements[@]}"; do 
    local element="${elements[$x]}"
    local element_prefix="|   "
    local curr_prefix="|-- "

    echo "${prefix}${curr_prefix}$element"
    [ -d "$directory/$element" ] && print_tree "$directory/$element" "${prefix}$element_prefix"
  done
}

if [ "$1" == "-A" ]
then
  root="$2"
  echo "$root"
  print_hidden $root ""
  exit 0
elif [ "$1" == "-d" ]
then
  root="$2"
  echo "$root"
  print_rev $root ""
  exit 0
elif [ "$1" == "-a" ]
then
  root="$2"
  echo "$root"
  print_tree $root ""
  exit 0
elif [ "$1" == "-s" ]
then
  root="$2"
  echo "$root"
  print_by_size $root ""
  exit 0
else
  root="$1"
  if [ -z "$root" ]
  then
    root="."
  fi
  echo "$root"
  print_tree $root ""
  exit 0
fi
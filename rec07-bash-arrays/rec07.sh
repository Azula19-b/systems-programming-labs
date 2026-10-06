#!/bin/bash

# function to curve grades
curve()
{
    incr=$1            # curve amount
    shift              # remove first argument
    arr=("$@")         # remaining arguments -> array
    index=0            # start index

    # add curve to each grade
    for i in "${arr[@]}"
    do
        let grades[$index]=$i+$incr
        let index=$index+1
    done
}

# check if curve amount argument exists
if [ $# -ne 1 ]
then
    echo "usage: ./rec07.sh <curve amount>"
    exit 1
fi

# array to store quiz grades
grades=()

# ask user for 5 quiz grades
for i in 1 2 3 4 5
do
    echo -n "Enter QUIZ #$i: "
    read grade
    grades[$((i-1))]=$grade
done

# apply curve
curve "$1" "${grades[@]}"

# spacing like sample output
echo
echo "Curved Grades:"
echo

# print curved grades
for ((i=0; i<${#grades[@]}; i++))
do
    echo "Quiz $((i+1)) Grade: ${grades[$i]}"
done

# Name: Bahar Ozer

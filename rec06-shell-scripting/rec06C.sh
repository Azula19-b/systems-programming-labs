#!/bin/bash

# Name: Bahar Ozer
# Description: Generates a random number between 1 and 10 and repeatedly asks the user
# to guess it until the correct number is entered.

number=$((RANDOM % 10 + 1))

guess=0

while [ $guess -ne $number ]
do
    echo "Enter a number between 1 and 10:"
    read guess

    if [ $guess -eq $number ]
    then
        echo "Congratulations, the number is $number."
    else
        echo "Sorry, you are not correct. Try again!"
    fi
done

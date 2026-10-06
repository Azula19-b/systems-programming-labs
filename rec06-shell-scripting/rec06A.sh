#!/bin/bash

# Name: Bahar Ozer
# Description: Prints a greeting message using the name passed as a command-line argument.
# If no name is provided, prints a general greeting message.

if [ $# -eq 0 ]
then
    echo "Hope you have a great day!"
else
    echo "Good day, $1! Nice to meet you!"
fi

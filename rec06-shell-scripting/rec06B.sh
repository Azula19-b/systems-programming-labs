#!/bin/bash

# Name: Bahar Ozer
# Description: Prompts the user to enter a Linux command, displays it, and executes it.

echo "Enter Linux command to perform:"
read command

echo "Command to be executed: $command"

$command

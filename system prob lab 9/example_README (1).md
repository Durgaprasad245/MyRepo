# Fork and Execute C Program

## Overview

This C program demonstrates forking a child process and executing a command using `execvp`. The parent process waits for the child process to finish and handles signals such as Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP) in the child process. Additionally, the parent process waits for a quit signal (Ctrl+\) to terminate.

## Instructions

# Compile the program:
   ```bash
   gcc forkexecvp.c -o forkexecvp

# Run the program with a command as an argument:

bash
./forkexecvp <command>

Replace <command> with the desired command to execute in the child process.

#Ctrl+C (SIGINT): Interrupts the child process and prints a message indicating the interruption.
#Ctrl+Z (SIGTSTP): Suspends the child process and prints a message indicating the suspension.
#Ctrl+\ (SIGQUIT): Quits the parent process. Press this combination to exit the program.

# Example
# Running the program with a simple command:

./forkexecvp ls

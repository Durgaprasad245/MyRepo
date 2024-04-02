# Threaded Sum Calculation Program with Structured Arguments

## Overview

This C program calculates the sum of elements in an array using multiple threads. Instead of using global variables, it utilizes a structure to pass thread-specific arguments to the thread creation function. Each thread is responsible for computing the sum of a partition of the array, and the main thread aggregates the partial sums to obtain the total sum.

## Instructions

1. Compile the program:
   ```bash
   gcc -o pthread_sum pthread_sum.c -lpthread


2. Run the program
   ./pthread_sum <array size> <number of threads>

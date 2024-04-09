# Makefile for Job Scheduler

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = dnuthala_HW04.c

# Executable name
TARGET = dnuthala_HW04

all: $(TARGET)

$(TARGET): $(SRCS)
    $(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
    rm -f $(TARGET)

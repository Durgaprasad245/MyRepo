# Makefile for Job Scheduler

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = job_scheduler.c

# Executable name
TARGET = job_scheduler

all: $(TARGET)

$(TARGET): $(SRCS)
    $(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
    rm -f $(TARGET)

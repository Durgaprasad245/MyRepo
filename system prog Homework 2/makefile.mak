# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -g

# Executable name
EXEC := dnuthala_HW02

# Source files
SRCS := dnuthala_HW02.c

# Object files
OBJS := $(SRCS:.c=.o)

# Dependency files
DEPS := $(OBJS:.o=.d)

# Phony targets
.PHONY: all clean

# Default target
all: $(EXEC)

# Linking target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Compilation target
%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean target
clean:
	rm -f $(OBJS) $(DEPS) $(EXEC)

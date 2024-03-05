CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = dnuthala.c
OBJS = $(SRCS:.c=.o)
EXEC = search
SYMLINK = search_sym

.PHONY: all clean symlink

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS) $(SYMLINK)

symlink:
	ln -sf $(EXEC) $(SYMLINK)

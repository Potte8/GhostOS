CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/ghost_main.c src/debug/debug.c src/system/log_manager.c apps/log_viewer/log_viewer.c
OBJ = $(SRC:.c=.o)
EXEC = ghostos.elf

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

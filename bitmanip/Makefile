CC      = gcc
CFLAGS  = -Wall -Wextra -std=gnu99 -O2
TARGET  = bitmanip
SRCS    = main.c bit_utils.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

CC      = gcc
CFLAGS  = -Wall -Wextra -std=gnu99 -O2
TARGET  = gpio-blink
SRCS    = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

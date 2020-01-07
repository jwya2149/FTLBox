CC = gcc
CFLAGS = -W -g

all: ftl

ftl: main.c ftl_box.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm ftl

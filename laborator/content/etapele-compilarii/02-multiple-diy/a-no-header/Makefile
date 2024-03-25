CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -no-pie -m32

.DEFAULT_GOAL: all

.PHONY: all clean

all: main

main: main.o div.o mul.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c

add.o: div.c

sub.o: mul.c

clean:
	-rm -f main main.o mil.o div.o
	-rm -f *~

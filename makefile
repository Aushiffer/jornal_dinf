CFLAGS = -g -Wall -Wextra -pedantic
PROGRAM = jornal_dinf
CC = gcc

all: $(PROGRAM)

$(PROGRAM): main.o jornal.o
	$(CC) -o $(PROGRAM) main.o jornal.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

jornal.o: jornal.c jornal.h
	$(CC) -c jornal.c $(CFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)

CC = gcc
CFLAGS = -std=gnu99 -Wall -g -O2
LDFLAGS = -lm -lpthread
SRCS = *.c *.h
OBJ = main.o utils.o temp*.o

all: build

build:
	$(CC) $(CFLAGS) -c $(SRCS) $(LDFLAGS)
	$(CC) $(CFLAGS) -o crtmp crtmp.o utils.o

link:
	$(CC) -c temp*.c
	$(CC) $(OBJ) -o exec $(LDFLAGS) 

clean:
	rm -f exec *.o
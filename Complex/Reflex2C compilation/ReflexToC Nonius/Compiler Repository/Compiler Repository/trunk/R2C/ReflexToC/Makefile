CC=gcc
CFLAGS=-c -g -Wall

all: r2c
r2c: rcsl86.o seml86.o sinl86.o strl86.o subl86.o
	$(CC) rcsl86.o seml86.o sinl86.o strl86.o subl86.o -o r2c

rcsl86.o:
	$(CC) $(CFLAGS) rcsl86.c

seml86.o:
	$(CC) $(CFLAGS) seml86.c

sinl86.o:
	$(CC) $(CFLAGS) sinl86.c

strl86.o:
	$(CC) $(CFLAGS) strl86.c

subl86.o:
	$(CC) $(CFLAGS) subl86.c

clean:
	rm -rf *.o r2c

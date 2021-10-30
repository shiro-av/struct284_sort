CC=gcc
CFLAGS=-c -Wall
MKFLAGS=-Wall -lm -o

bubble: functions.o bubblesort.o main.o
	$(CC) main.o bubblesort.o functions.o $(MKFLAGS) bubble

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

bubblesort.o: bubblesort.c
	$(CC) $(CFLAGS) bubblesort.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o bubble
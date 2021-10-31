CC=gcc
CFLAGS=-c -Wall
MKFLAGS=-Wall -lm -o

bubble: functions.o bubblesort.o tests.o main.o
	$(CC) main.o bubblesort.o functions.o tests.o $(MKFLAGS) bubble

insert: functions.o insertsort.o tests.o main.o
	$(CC) main.o insertsort.o functions.o tests.o $(MKFLAGS) insert

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

bubblesort.o: bubblesort.c
	$(CC) $(CFLAGS) bubblesort.c

tests.o: tests.c
	$(CC) $(CFLAGS) tests.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

insertsort.o: insertsort.c
	$(CC) $(CFLAGS) insertsort.c

clean:
	rm -rf *.o bubble
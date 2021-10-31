CC=gcc
CFLAGS=-c -Wall
MKFLAGS=-Wall -lm -o

bubble: functions.o bubblesort.o tests.o bubble.o
	$(CC) bubble.o bubblesort.o functions.o tests.o $(MKFLAGS) bubble

insert: functions.o insertsort.o tests.o insert.o
	$(CC) insert.o insertsort.o functions.o tests.o $(MKFLAGS) insert

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

bubblesort.o: bubblesort.c
	$(CC) $(CFLAGS) bubblesort.c

tests.o: tests.c
	$(CC) $(CFLAGS) tests.c

bubble.o: bubble.c
	$(CC) $(CFLAGS) bubble.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

insertsort.o: insertsort.c
	$(CC) $(CFLAGS) insertsort.c

insert.o: insert.c
	$(CC) $(CFLAGS) insert.c

clean:
	rm -rf *.o bubble insert
CC=		gcc
CFLAGS=		-g -Wall -std=gnu99 -Iinclude -c

all:		bminor


encoder.o: 	encoder.c encoder.h
	$(CC) $(CFLAGS) -o $@ $<

bminor.o: bminor.c 
	$(CC) $(CFLAGS) -o $@ $<

bminor: bminor.o encoder.o
	$(CC) -Wall -std=gnu99 $^ -o $@


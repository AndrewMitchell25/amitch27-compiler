CC=		gcc
CFLAGS=		-g -Wall -std=gnu99 -Iinclude -c

all:		bminor


scanner.c:	scanner.flex
	flex -oscanner.c scanner.flex

scanner.o:	scanner.c
	$(CC) $(CFLAGS) -o scanner.o scanner.c

token.o:	token.c token.h
	$(CC) $(CFLAGS) -o token.o token.c

encoder.o: 	encoder.c encoder.h
	$(CC) $(CFLAGS) -o $@ $<

bminor.o: bminor.c 
	$(CC) $(CFLAGS) -o $@ $<

bminor: bminor.o encoder.o scanner.o token.o
	$(CC) -Wall -std=gnu99 $^ -o $@


test: bminor
	./runtest.sh

clean: 
	rm -f bminor *.o
CC=		gcc
CFLAGS=		-g -Wall -std=gnu99 -Iinclude -c

all:		bminor

label.o: label.c label.h
	$(CC) $(CFLAGS) -o label.o label.c

scratch.o: scratch.c scratch.h
	$(CC) $(CFLAGS) -o scratch.o scratch.c

hash_table.o: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -o hash_table.o hash_table.c

scope.o: scope.c scope.h
	$(CC) $(CFLAGS) -o scope.o scope.c

symbol.o: symbol.c symbol.h
	$(CC) $(CFLAGS) -o symbol.o symbol.c

expr.o:	expr.c expr.h
	$(CC) $(CFLAGS) -o expr.o expr.c

decl.o:	decl.c decl.h
	$(CC) $(CFLAGS) -o decl.o decl.c

stmt.o:	stmt.c stmt.h
	$(CC) $(CFLAGS) -o stmt.o stmt.c

type.o:	type.c type.h
	$(CC) $(CFLAGS) -o type.o type.c

param_list.o:	param_list.c param_list.h
	$(CC) $(CFLAGS) -o param_list.o param_list.c

indent.o:	indent.c indent.h
	$(CC) $(CFLAGS) -o indent.o indent.c

parser.c:	parser.bison
	bison --defines=token2.h --output=parser.c -v parser.bison

parser.o:	parser.c scanner.o
	$(CC) $(CFLAGS) -o parser.o parser.c

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

bminor: bminor.o encoder.o scanner.o token.o parser.o expr.o decl.o stmt.o type.o param_list.o indent.o scope.o symbol.o hash_table.o scratch.o label.o
	$(CC) -Wall -std=gnu99 $^ -o $@


test: bminor
	./runtest.sh

clean: 
	rm -f bminor *.o
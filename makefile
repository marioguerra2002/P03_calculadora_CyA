CC=g++
CFLAGS=-O0 -g -Wall
DEPS = alphabet.h chain.h symbol.h language.h calculator.h
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o P03_calculator


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: chain

language: main.o
	g++ -o chain main.cc alphabet.cc chain.cc symbol.cc language.cc calculator.cc

clean:
	rm -f *.o
CC=gcc
FLAGS= -Wall -g

all: txtfind isort
isort: isort.c 
	$(CC) $(FLAGS) -o isort isort.o
isort.o: isort.c isort.H
	$(CC) $(FLAGS) -c isort.c 
txtfind: txtfind.c 
	$(CC) $(FLAGS) -o txtfind txtfind.o
txtfind.o: txtfind.c txtfind.H
	$(CC) $(FLAGS) -c txtfind.c 
.PHONY: clean all
clean:
	rm -f *.o *.a *.so txtfind isort 
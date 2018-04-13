all: bstree

bstree: main.o bstree.o
	gcc -Wall main.o bstree.o -o bstree

main.o: main.c
	gcc -Wall -c main.c

bstree.o: bstree.c
	gcc -Wall -c bstree.c


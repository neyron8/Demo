launch: testik
	./testik
testik: func.o test1.o main.o 
	gcc -Wall main.o func.o test1.o -o testik

func.o: func.c
	gcc -c func.c

test1.o: test1.c
	gcc -c test1.c

main.o: main.c
	gcc -c main.c




all: task1 task2 task3

task1: main1.o
	gcc -o task1 main1.o

main1.o: main1.c
	gcc -c -o main1.o main1.c

task2: main2.o
	gcc -o task2 main2.o

main2.o: main2.c
	gcc -c -o main2.o main2.c

task3: main3.o
	gcc -o task3 main3.o

main3.o: main3.c
	gcc -c -o main3.o main3.c

clean:
	del *.o
	del *.exe

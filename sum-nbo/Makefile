#Makefile
all: sum-nbo

sum-nbo: main.o sum-nbo.o
	g++ -o sum-nbo main.o sum-nbo.o
	rm -f *.o

main.o: sum-nbo.h main.cpp
	g++ -c -o main.o main.cpp

sum-nbo.o: sum-nbo.h sum-nbo.cpp
	g++ -c -o sum-nbo.o sum-nbo.cpp

clean:
	rm -f sum-nbo

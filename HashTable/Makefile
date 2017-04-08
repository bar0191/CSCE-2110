all: bar0191

bar0191: main.o Node.o HashTable.o
		g++ -std=c++0x main.o Node.o HashTable.o -o bar0191

main.o: main.cpp
		g++ -std=c++0x -c main.cpp

Node.o: Node.cpp
		g++ -std=c++0x -c Node.cpp

HashTable.o: HashTable.cpp
		g++ -std=c++0x -c HashTable.cpp

clean:
		rm -rf *o bar0191

run: bar0191
	./bar0191

all: bar0191

bar0191: main.o Graph.o
		g++ main.o Graph.o -o bar0191

main.o: main.cpp
		g++ -c main.cpp

Graph.o: Graph.cpp
		g++ -c Graph.cpp

clean:
		rm -rf *o bar0191

run: bar0191
	./bar0191

/*
 ============================================================================
 Name        : Graph.cpp
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : Graph class functions
 Notes       : this is a STL implementation to construct an undirected graph
 into adjacecy list and matrix, this is a very creative way to use STL.
 Esentially a MAP is like a hash table, taking only unique keys, which a
 vertex is.. so with each key(vertex), will be a SET of neighbors, and since
 neighbors can not repeat, its appropriate to use a SET.
 
 The matrix is created with bool[][] values either true or false, and I
 ended up accidentally using floyds algorithm to implement the matrix using
 three nested for loops then checking each vertex to see if it visits another
 then mark it as visited and set bool value to true.
 
 map<vertex, <set<vertex> > undirected graph
 
 Traversal for this graph require nested for loops of two or three
 sudo code to understand:
 
 for map loop through each vertex
    *inside here traverses through map of vertices*
        for set loop through each neighbor of vertex
            *inside here traverses through set of neighbors*
 
 map: is similar to hashtable, takes in only unique key values (vertex)
 set: is similar to list, but doesn't take duplicates (neighbors)
 
 each key(vertex) in the map has its own set of neighbors
 
 CITES:
 http://cs.dvc.edu/HowTo_Cparse.html
 http://stackoverflow.com/a/14133220
 ============================================================================
 */

//includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <map>

// libraries
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::map;
using std::set;

// delimeter for file parser
const char* const DELIMITER = ",";
const int MAX_BUF_LENGTH = 1024;
const int MAX_TOKENS = 20;

// graph class
class Graph
{
public:
    map<char, set<char> > adjList;      // adjacency list
    int graphSize;                      // graph size
    int index;                          // index for loops
    int row, col;                       // row and col index for loops
    
    // prototypes
    Graph();
    void addNode(char newNode);
    void addEdge(char u, char v);
    void removeNode(char node);
    void removeEdge(char u, char v);
    void print();
};

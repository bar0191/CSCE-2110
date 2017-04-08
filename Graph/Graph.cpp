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

#include "Graph.h"

/*
 ============================================================================
 Function    : Graph()
 Parameters  : N/A
 Return      : N/A
 Description : Constructor
 Citation    : N/A
 ============================================================================
 */

Graph::Graph()
{
    graphSize = adjList.size();
}

/*
 ============================================================================
 Function    : addNode()
 Parameters  : char newNode
 Return      : nothing
 Description : addNode to stl map (adjacency list), it will not add dups
 Citation    : http://www.cplusplus.com/reference/map/map/insert/
 ============================================================================
 */

void Graph::addNode(char newNode)
{
    adjList[newNode]; // add to stl map
}

/*
 ============================================================================
 Function    : addEdge()
 Parameters  : char u, char v
 Return      : nothing
 Description : add edge to vertex's set
 Citation    : http://www.cplusplus.com/reference/map/map/insert/
http://www.cplusplus.com/reference/set/set/insert/
 ============================================================================
 */

void Graph::addEdge(char u, char v)
{
    //adjList[map].insert(to set)
    
    adjList[u].insert(v);
    adjList[v].insert(u);
}

/*
 ============================================================================
 Function    : removeNode()
 Parameters  : char node
 Return      : nothing
 Description : remove node from map, traverse through each vertex to remove
 node from each vertex's set
 Citation    : http://www.cplusplus.com/reference/map/map/erase/
 ============================================================================
 */

void Graph::removeNode(char node)
{
    adjList.erase(node); // this erases node from map
    // still need to remove from all sets
    
    // traverse through map, and traverse through each set of neighbors in each vertex
    for (map<char, set<char> >::iterator it = adjList.begin(); it != adjList.end(); ++it)
        for (set<char>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter)
            if (node == *iter)
                adjList[it->first].erase(node);
}

/*
 ============================================================================
 Function    : removeEdge()
 Parameters  : char u, char v
 Return      : nothing
 Description : remove edge from vertexs set of neighbors
 Citation    : http://www.cplusplus.com/reference/map/map/erase/
 http://www.cplusplus.com/reference/set/set/erase/
 ============================================================================
 */

void Graph::removeEdge(char u, char v)
{
    // adjList[map].erase(from set)
    
    adjList[u].erase(v);
    adjList[v].erase(u);
}

/*
 ============================================================================
 Function    : print()
 Parameters  : nothing
 Return      : nothing
 Description : prints adjacency list and constructs adjacency matrix
 Citation    : N/A
 ============================================================================
 */

void Graph::print()
{
    int size = adjList.size();  //size of map
    char vertices[size];        // list of vertices
    bool matrix[size][size];    // adjacency matrix bool[][]
    index = 0;                  // index value for vertices
    row = 0;                    // loop value for matrix
    
    // initialize adjacency matrix to false(0)
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = false;
    
    // initialize vertices to size of map
    for (int i = 0; i < size; i++)
        vertices[i] = '\0';
    
    // print adjacency list & size
    cout << "Printing Adjacency List: " << endl;
    cout << "Undirected graph contains " << adjList.size() << " Nodes total" << endl;
    // loop through each vertex in the map
    for (map<char, set<char> >::iterator it = adjList.begin(); it != adjList.end(); ++it)
    {
        vertices[index] = it->first; // each value in map is a vertex, store it
        cout << it->first << " : \t"; // vertex
        // loop through each set of neighbors for each vertex
        for (set<char>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter)
            cout << *iter << " "; // neighbor
        cout << endl;
        index++; // increment index
    }
    cout << endl;
    
    // set up matrix
    // floyds implementations - three nested for loops
    // loop through map of vertices, then loop through each vertices set of neighbors
    for (map<char, set<char> >::iterator it = adjList.begin(); it != adjList.end(); ++it)
    {
        for (set<char>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter)
            for (int i = 0; i < adjList.size(); i++)
                if (vertices[i] == *iter) // if its an edge mark it as true
                    matrix[row][i] = true;
        row++;
    }
    
    // print the adjacency matrix
    cout << "Printing Adjacency Matrix: " << endl;
    cout << "  ";
    for (map<char, set<char> >::iterator it = adjList.begin(); it != adjList.end(); ++it)
        cout << it->first << " ";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << vertices[i] << " ";
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << " " << endl;
    }
}

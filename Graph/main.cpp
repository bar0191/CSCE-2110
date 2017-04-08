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

int main(void)
{
    // class object
    Graph graph;
    
    // file stream variables
    ifstream fin;
    ofstream fout;
    
    // hard coded file names
    string graphFile = "graph.txt";
    string cmdFile = "commands.txt";

    // open file
    cout << endl << "Opening file: " << graphFile << endl << endl;
    fin.open(graphFile.c_str());
    if (!fin.good())
    {
        // if error opening file
        cout << "ERROR: unable to open file..." << endl;
        return 1;
    }
    
    // until end of file
    while (!fin.eof())
    {
        // getline will put line into buffer
        char buffer[MAX_BUF_LENGTH];
        fin.getline(buffer, MAX_BUF_LENGTH);
        
        
        int i = 0; // for loop value
        char* token[MAX_TOKENS] = {}; // initialize tokens
        char temp; // temp value for node
        
        // parse the line
        token[0] = strtok(buffer, DELIMITER); // first token
        if (token[0])
        {
            for (i = 1; i < MAX_TOKENS; i++)
            {
                // take in each token
                token[i] = strtok(0, DELIMITER);
                if (!token[i]) break; // no more tokens
            }
        }
        
        // loop through parsed tokens
        for (int n = 0; n < i; n++)
        {
            // token[0] is vertex
            if (n == 0)
            {
                // add new vertex(node) to map
                temp = token[n][0];
                graph.addNode(temp);
            }
            else
            {
                // add new edge to vertex's set
                graph.addEdge(temp, token[n][0]);
            }
        }
    }
    
    // close file after eof
    fin.close();
    
    // print adjacency list/matrix
    graph.print();
    
    // open next file
    cout << endl << "Opening file: " << cmdFile << endl << endl;
    fin.open(cmdFile.c_str());
    if (!fin.good()) // if error opening
    {
        cout << "ERROR: Unable to open file... " << endl;
        return 1;
    }
    
    // will output commands to screen while we parse (saves run time)
    cout << "Ran the following commands: " << endl;
    while (!fin.eof())
    {
        // buffer for each line, getline
        char buf[MAX_BUF_LENGTH];
        fin.getline(buf, MAX_BUF_LENGTH);
        
        int i = 0; // for loop value
        char* token[MAX_TOKENS] = {}; // init tokens
        
        // parse line into tokens
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0])
        {
            for (i = 1; i < MAX_TOKENS; i++)
            {
                // each token
                token[i] = strtok(0, DELIMITER);
                if (!token[i]) break; // no more tokens
            }
        }
        
        char temp[i]; // array of temp values
        
        // loop through each token
        for (int n = 0; n < i; n++)
        {
            // token[0] will be command
            if (n == 0)
            {
                cout << "\t" << token[n] << " ";
                
                // if command is remove node
                if (strstr(token[n], "removenode") != NULL)
                {
                    char node = token[n+1][0];
                    
                    graph.removeNode(node);
                }
                // if command is remove edge
                else if (strstr(token[n], "removeedge") != NULL)
                {
                    char node1 = token[n+1][0];
                    char node2 = token[n+2][0];
                    
                    graph.removeEdge(node1, node2);
                }
                // if command is add node
                else if (strstr(token[n], "addnode") != NULL)
                {
                    char node = token[n+1][0];
                    
                    graph.addNode(node);
                }
                // if command is add edge
                else if (strstr(token[n], "addedge") != NULL)
                {
                    char node1 = token[n+1][0];
                    char node2 = token[n+2][0];
                    
                    graph.addEdge(node1, node2);
                }
                // otherwise unknown command
                else
                {
                    cout << "unknown command" << endl;
                }
            }
            // print nodes associated with command
            else
            {
                temp[n] = token[n][0];
                cout << temp[n] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    graph.print(); // print adjacency list/matrix
    fin.close();
    return 0;
}


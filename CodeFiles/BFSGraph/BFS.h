#ifndef BFS_H
#define BFS_H

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;   
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w); 

    // function to get No. of vertices
    int getV();
 
    // prints BFS traversal from a given source s
    vector<int> BFS(int s);  
};
 




#endif

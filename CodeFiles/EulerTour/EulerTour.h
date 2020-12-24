
#ifndef EulerTour_H
#define EulerTour_H

#include<bits/stdc++.h>
using namespace std;

class Tree
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    vector<int> *adj;   
    int *vis;
    int *Euler;
public:
    Tree(int V);  // Constructor
 
    // function to add an edge to Tree
    bool addEdge(int v, int w); 

    // function to get No. of vertices
    int getV();
 
    
    vector<int> getEulerTour(int root) ;
   
    void eulerTree(int u, int &indx) ;
};
 




#endif




  

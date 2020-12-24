#include "EulerTour.h"


/**
 * @brief Construct a new  Tree object
 * 
 * @param V 
 */

Tree::Tree(int V){
    this->V = V;
    adj = new vector<int>[V];
    vis = new int[V];
    Euler = new int[2*V];

}
/**
 * @brief Function to add edges to tree.
 * 
 * @param u 
 * @param v 
 */
bool Tree::addEdge(int u, int v) 
{ 
    if(v<this->V && v>=0 && u < this->V && u>=0){
         adj[u].push_back(v); 
         adj[v].push_back(u); 
         return true;
    }
    return false;
   
} 
/**
 * @brief Get Number of vertices in the graph
 * 
 * @return int 
 */
int Tree::getV()
{
    return this->V;
}

/**
 * @brief Function to store Euler Tour of tree.
 * 
 * @param u 
 * @param indx 
 */
void Tree::eulerTree(int u, int &indx) 
{ 
    vis[u] = 1; 
    Euler[indx++] = u; 
    for (auto it : adj[u]) { 
        if (!vis[it]) { 
            eulerTree(it, indx); 
            Euler[indx++] = u; 
        } 
    } 
} 


/**
 * @brief Function to Get Euler Tour of tree.
 * 
 * @param root 
 * @param N 
 */
vector<int> Tree::getEulerTour(int root) 
{ 
    
    
    vector<int> output;
    if(root<0 || root>=this->V){
        return output;
    }
    for(int i =0;i<this->V;i++){
        vis[i] =0;

    }
    for(int i =0;i<2*this->V;i++){
        Euler[i] =-1;

    }
    
    
    int index = 0;   
    eulerTree(root, index); 
    for (int i = 0; i < (2*this->V-1); i++) {
        if(Euler[i]==-1){
            break;
        }
        output.push_back(Euler[i]);
    }
         


    return output;

} 
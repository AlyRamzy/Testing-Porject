
#include "BFS.h"

/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param V 
 */
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

/**
 * @brief Add edge in the graph
 * 
 * @param v 
 * @param w 
 */
bool Graph::addEdge(int v, int w)
{
    if(v<this->V && v>=0 && w < this->V && w>=0){
        adj[v].push_back(w); // Add w to v’s list.
        return true;

    }
    return false;
    
}

/**
 * @brief Get Number of vertices in the graph
 * 
 * @return int 
 */
int Graph::getV()
{
    return this->V;
}

/**
 * @brief return vector of nodes value of the bfs
 * 
 * 
 * @param int s
 * @return  vector<int> Array of nodes value
 */

  
vector<int> Graph::BFS(int s)
{
    vector<int> out;
    if(s>=this->V || s<0){
        return out;
    }
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        out.push_back(s);
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return out;
}

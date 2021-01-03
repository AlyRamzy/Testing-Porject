#include "Kruskal.h"

/**
 * @brief Constructor to the class
 * 
 * @param n Number of nodes in the graph
 * @param edges Discription of the graph
 * @return 
 */
Kruskal :: Kruskal(int n, vector<edge> edges)
{   
    Nodes = n;
    this->edges = edges;

    DSUParent.resize(n+1);
    CompSize.resize(n+1,1);

    for(int i = 1; i <= n; i++)
        DSUParent[i] = i;
}

/**
 * @brief Find the parent of the Disjoint set
 * 
 * @param node Node to search for
 * @return int Parent Node
 */
int Kruskal :: FindSet(int node) 
{
	if(DSUParent[node] == node)
		return node;

	return DSUParent[node] = FindSet(DSUParent[node]);
}

/**
 * @brief Join two disjoint sets given a node from each set
 * 
 * @param x 
 * @param y 
 */
void Kruskal :: Union(int x,int y)
{
	x = FindSet(x);
	y = FindSet(y);

	if(x==y)
		return;

	DSUParent[x]=y;
	CompSize[y] += CompSize[x]; 
}

/**
 * @brief Find the weight of the Minimum Spanning tree
 * 
 * @return long long
 */
long long Kruskal :: FindMSTValue()
{
    sort(edges.begin(), edges.end());

    long long MST = 0;
    int TotalSize = 0;
    for(auto e : edges)
    {
        int u = FindSet(e.from);
        int v = FindSet(e.to);

        if(u != v)
        {
            Union(u,v);
            TotalSize = max({TotalSize, CompSize[DSUParent[u]], CompSize[DSUParent[v]]});
            MST += e.weight;
        }
    }

    return TotalSize == Nodes ? MST : LONG_LONG_MIN;
}
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <bits/stdc++.h>
using namespace std;

class edge {

    public:
    
	int from, to, weight;

	edge() {}
	edge(int f, int t, int w) : from(f), to(t), weight(w) {}

	bool operator<(const edge& rhs) const {
		return (weight < rhs.weight);
	}
};

class Kruskal
{
    int Nodes;
    vector<edge> edges;
    vector<int>DSUParent, CompSize;
    int FindSet(int node);
    void Union(int x, int y);

    public:
    Kruskal(int Nodes_num,vector<edge>edges);
    int FindMSTValue();
};

#endif
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include<bits/stdc++.h>
using namespace std;

class MinSegTree
{
    int ArraySize, Default;
    vector<int>seg;
    void build(const vector<int> & arr, int id, int left, int right);
    void Update(int index, int value, int id, int left, int right);
    int Query(int l, int r, int id, int left, int right);

    public:
    MinSegTree(vector<int>arr);
    void Update(int index, int value);
    int GetMin(int left,int right);
};

#endif
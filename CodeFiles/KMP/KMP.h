#ifndef KMP_H
#define KMP_H

#include<bits/stdc++.h>
using namespace std;

class KMP
{
    vector<int> PrefixFunction(string str);
    public:
    vector<int> ApplyKMP(string str, string pat);
};

#endif
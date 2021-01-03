#ifndef __MINMAX
#define __MINMAX
// A simple C++ program to find 
// maximum score that 
// maximizing player can get. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns the optimal value a maximizer can obtain. 
// depth is current depth in game tree. 
// nodeIndex is index of current node in scores[]. 
// isMax is true if current move is 
// of maximizer, else false 
// scores[] stores leaves of Game tree. 
// h is maximum height of Game tree 

/**
 * @brief Returns the optimal value a maximizer can obtain.
 * 
 * @param depth 
 * @param nodeIndex 
 * @param isMax 
 * @param scores 
 * @param h 
 * @return int 
 */
int minimax(int depth, int nodeIndex, bool isMax, 
            vector<int> scores, int h) 
{ 
    // Terminating condition. i.e 
    // leaf node is reached 
    if (depth == h) 
        return scores[nodeIndex]; 
  
    //  If current move is maximizer, 
    // find the maximum attainable 
    // value 
    if (isMax) 
       return max(minimax(depth+1, nodeIndex*2, false, scores, h), 
            minimax(depth+1, nodeIndex*2 + 1, false, scores, h)); 
  
    // Else (If current move is Minimizer), find the minimum 
    // attainable value 
    else
        return min(minimax(depth+1, nodeIndex*2, true, scores, h), 
            minimax(depth+1, nodeIndex*2 + 1, true, scores, h)); 
} 
  
/**
 * @brief Returns the optimal value a maximizer can obtain.
 * 
 * @param values 
 * @return int 
 */

int minimax_interface(vector<int> values) {
    
    int n = values.size();
    if(n ==0 || n%2 !=0){
        return -1;
    }
    int h = log2(n);

    return minimax(0,0,true,values,h);


}

#endif
#ifndef __LCA
#define __LCA
// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>
 
using namespace std;
 

/**
 * @brief A Binary Tree node
 * 
 */
struct Node
{
    int key;
    struct Node *left, *right;
};
 

/**
 * @brief  Utility function creates a new binary tree node with given key
 * 
 * @param key 
 * @return Node* 
 */
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
 

/**
 * @brief Finds the path from root node to given root of the tree, Stores the path in a vector path[], returns true if path exists otherwise false
 * 
 * @param root 
 * @param path 
 * @param key
 * @return true 
 * @return false 
 */
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL) return false;
 
    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root->key);
 
    // See if the k is same as root's key
    if (root->key == k)
        return true;
 
    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;
 
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}
 

/**
 * @brief Returns LCA if node n1, n2 are present in the given binary tree,otherwise return -1
 * 
 * @param root 
 * @param n1 
 * @param n2 
 * @return int 
 */
int findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;
 
    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}
#endif
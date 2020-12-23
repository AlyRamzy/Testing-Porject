#include "SegTree.h"

/**
 * @brief Class Constructor, given the initial array build the initial segment tree
 * 
 * @return  
 */
MinSegTree :: MinSegTree(vector<int>arr)
{
    Default = INT_MAX;
    ArraySize = arr.size();
    seg.resize(4 * ArraySize);

    build(arr, 1, 0, ArraySize-1);
}

/**
 * @brief Build the initial segment tree in O(n)
 * 
 * @param arr Initial array
 * @param id Current segment id
 * @param left Left boundary of current segment
 * @param right Right boundary of current segment
 */
void MinSegTree :: build(const vector<int> & arr, int id, int left, int right)
{
    if(left == right)
    {
        seg[id] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(arr, 2 * id, left, mid);
    build(arr, 2 * id + 1, mid + 1, right);

    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

/**
 * @brief Updates the value in index with value, and update the segment tree
 * 
 * @param index Index to be updated
 * @param value Value to be updated
 * @param id Current segment id
 * @param left Left boundary of current segment
 * @param right Right boundary of current segment
 */
void MinSegTree :: Update(int index, int value, int id, int left, int right)
{
    if(left == right)
    {
        seg[id] = value;
        return;
    }
    int mid = (left + right) / 2;
    
    if(index <= mid)
        Update(index, value, 2 * id, left, mid);
    else 
        Update(index, value, 2 * id + 1, mid + 1, right);
    
    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

/**
 * @brief Public method to interface with the user
 * 
 * @param index 
 * @param value 
 */
void MinSegTree :: Update(int index, int value)
{
    Update(index, value, 1, 0, ArraySize-1);
}

/**
 * @brief Returns the minimum in segment bounded by [l, r]
 * 
 * @param l Left boundary of the required segment
 * @param r Right boundary of the required segment
 * @param id Current segment id
 * @param left Left boundary of current segment
 * @param right Right boundary of current segment
 * @return int Minimum value
 */
int MinSegTree :: Query(int l, int r, int id, int left, int right)
{
    if(left > r || right < l)   //fully outside
        return Default;
    if(left >= l && right <= r) //fully inside
        return seg[id];
    
    int mid = (left + right) / 2;

    return min(Query(l, r, 2 * id, left, mid), Query(l, r, 2 * id + 1, mid + 1, right));
}

/**
 * @brief Get the Min value
 * 
 * @param left 
 * @param right 
 * @return int 
 */
int MinSegTree :: GetMin(int left, int right)
{
    return Query(left, right, 1, 0, ArraySize-1);
}
#ifndef __STACK
#define __STACK
// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *NewNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *stackNode = NewNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
    {

        return INT_MIN;
    }
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode *root)
{
    if (isEmpty(root))
    {

        return INT_MIN;
    }
    return root->data;
}
#endif
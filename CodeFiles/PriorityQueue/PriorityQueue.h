#ifndef __PRIORITY_QUEUE
#define __PRIORITY_QUEUE
#include <cstdio>

#include <cstring>

#include <cstdlib>
#include<iostream>

#define MAX_SIZE 100000
using namespace std;


struct node

{

    int priority;

    int info;

    struct node* link;

};

/*

 * Class Priority Queue

 */

class Priority_Queue

{

private:

    node* front;

public:

    Priority_Queue()

    {

        front = NULL;

    }

    /*

     * Insert into Priority Queue

     */

    void insert(int item, int priority)

    {

        node* tmp, * q;

        tmp = new node;

        tmp->info = item;

        tmp->priority = priority;

        if (front == NULL || priority >= front->priority)

        {

            tmp->link = front;

            front = tmp;

        }

        else

        {

            q = front;

            while (q->link != NULL && q->link->priority > priority)

                q = q->link;

            tmp->link = q->link;

            q->link = tmp;

        }

    }

    /*

     * Delete from Priority Queue

     */
    int isEmpty()
    {
        return !front;
    }

    int peekRearInfo()
    {
        if (isEmpty())
        {

            return -1;
        }
        node* q = front;
        while (q->link != NULL)

            q = q->link;
        return q->info;

    }
    int peekRearPriority()
    {
        if (isEmpty())
        {

            return -1;
        }
        node* q = front;
        while (q->link != NULL)

            q = q->link;
        return q->priority;

    }
    int peekFrontInfo()
    {
        if (isEmpty())
        {

            return -1;
        }
        node* q = front;

        return q->info;

    }
    int peekFrontPriority()
    {
        if (isEmpty())
        {

            return -1;
        }
        node* q = front;

        return q->priority;

    }

    void del()

    {

        node* tmp;

        if (front != NULL){
            tmp = front;

            front = front->link;

            free(tmp);
        }

    }

    /*

     * Print Priority Queue

     */

    void display()

    {

        node* ptr;

        ptr = front;

        if (front != NULL)
        {
            while (ptr != NULL)
            {
                ptr = ptr->link;
            }
        }
    }
};

#endif

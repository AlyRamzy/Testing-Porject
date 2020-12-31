#pragma once
#define MAX_SIZE 100000
using namespace std;
class Queue {
private:
    int myqueue[MAX_SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == MAX_SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) return true;
        else return false;
    }

    void enQueue(int value) {
        if (isFull()) {

        }
        else {
            if (front == -1) front = 0;
            rear++;
            myqueue[rear] = value;
        }
    }
    int deQueue() {
        int value;
        if (isEmpty()) {
            return(-1);
        }
        else {
            value = myqueue[front]; if (front >= rear) {      //only one element in queue
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }

            return(value);
        }
    }
    int getRear() { return rear; }
    int getFront() { return front; }
    int getFirst() { return myqueue[front]; }
    int getLast() {
        return myqueue[rear];
    }

};
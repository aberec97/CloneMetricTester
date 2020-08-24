#pragma once

#include <stack>

using namespace std;

class QueueWithTwoStacks {

private:
    stack<int>* stack1;
    stack<int>* stack2;
    int count = 0;
    bool isEmpty();
public:
    QueueWithTwoStacks();
    ~QueueWithTwoStacks();
    void enqueue(int item);
    int dequeue();
    int peek();
    int size();
    stack<int>* copyStack(stack<int>* original);
    void print();
};
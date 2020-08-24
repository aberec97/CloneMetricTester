#include <stack>
#include <iostream>
#include "QueueWithTwoStacks.h"

using namespace std;

QueueWithTwoStacks::QueueWithTwoStacks() {
    stack1 = new stack<int>;
    stack2 = new stack<int>;
}

QueueWithTwoStacks::~QueueWithTwoStacks() {
    delete stack1;
    delete stack2;
}

bool QueueWithTwoStacks::isEmpty() {
    return count == 0;
}

void QueueWithTwoStacks::enqueue(int item) {
    stack1->push(item);
    count++;
}

int QueueWithTwoStacks::dequeue() {
    if (isEmpty()) {
        return NULL;
    }

    if (stack2->empty()) {
        if (stack1->empty()) {
            return NULL;
        }
        while (!stack1->empty()) {
            stack2->push(stack1->top());
            stack1->pop();
        }
    }

    int result = stack2->top();
    count--;
    stack2->pop();
    return result;
}

int QueueWithTwoStacks::peek() {
    if (isEmpty()) {
        return NULL;
    }

    if (stack2->empty()) {
        if (stack1->empty()) {
            return NULL;
        }
        while (!stack1->empty()) {
            stack2->push(stack1->top());
            stack1->pop();
        }
    }

    int result = stack2->top();
    return result;
}

int QueueWithTwoStacks::size() {
    return count;
}

stack<int>* QueueWithTwoStacks::copyStack(stack<int>* original) {
    stack<int>* result = new stack<int>;
    stack<int>* temporary = new stack<int>;

    while (!original->empty()) {
        temporary->push(original->top());
        original->pop();
    }
    while (!temporary->empty()) {
        original->push(temporary->top());
        result->push(temporary->top());
        temporary->pop();
    }

    delete temporary;

    return result;
}

void QueueWithTwoStacks::print() {
    if (isEmpty()) {
        cout << "This queue is empty!\n";
        return;
    }

    int* content = new int[count];
    int index = 0;

    stack<int>* tmpStack1 = copyStack(stack1);
    stack<int>* tmpStack2 = copyStack(stack2);

    while (!tmpStack2->empty()) {
        content[index] = tmpStack2->top();
        tmpStack2->pop();
        index++;
    }
    while (!tmpStack1->empty()) {
        tmpStack2->push(tmpStack1->top());
        tmpStack1->pop();
    }
    while (!tmpStack2->empty()) {
        content[index] = tmpStack2->top();
        tmpStack2->pop();
        index++;
    }

    cout << "[ ";
    for (int i = 0; i < count; i++) {
        cout << content[i] << " ";
    }
    cout << "]\n";

    delete tmpStack1;
    delete tmpStack2;
    delete[] content;
}
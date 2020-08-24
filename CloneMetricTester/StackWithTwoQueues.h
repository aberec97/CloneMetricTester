#pragma once

#include <queue>

using namespace std;

class StackWithTwoQueues {

private:
	queue<int> *q1;
	queue<int> *q2;
	int count = 0;
	bool isEmpty();
public:
	StackWithTwoQueues();
	~StackWithTwoQueues();
	void push(int value);
	int pop();
	int peek();
	int size();
	queue<int>* copyQueue(queue<int>* original);
	void print();
};
#include <iostream>
#include <queue>
#include "StackWithTwoQueues.h"

using namespace std;

StackWithTwoQueues::StackWithTwoQueues() {
	q1 = new queue<int>;
	q2 = new queue<int>;
}

StackWithTwoQueues::~StackWithTwoQueues() {
	delete q1;
	delete q2;
}

bool StackWithTwoQueues::isEmpty() {
	return count == 0;
}

void StackWithTwoQueues::push(int value) {
	if (q1->empty() || q2->empty()) {
		q1->push(value);
	}
	else {
		q2->push(value);
	}

	count++;
}

int StackWithTwoQueues::pop() {
	if (isEmpty()) {
		return NULL;
	}

	int result;

	if (q1->empty()) {
		while (q2->size() != 1) {
			q1->push(q2->front());
			q2->pop();
		}
		result = q2->front();
		q2->pop();
	}
	else {
		while (q1->size() != 1) {
			q2->push(q1->front());
			q1->pop();
		}
		result = q1->front();
		q1->pop();
	}

	count--;
	return result;
}

int StackWithTwoQueues::peek() {
	if (isEmpty()) {
		return NULL;
	}

	int result;

	if (q1->empty()) {
		while (q2->size() != 1) {
			q1->push(q2->front());
			q2->pop();
		}
		result = q2->front();
	}
	else {
		while (q1->size() != 1) {
			q2->push(q1->front());
			q1->pop();
		}
		result = q1->front();
	}

	count--;
	return result;
}

int StackWithTwoQueues::size() {
	return count;
}

queue<int>* StackWithTwoQueues::copyQueue(queue<int> *original) {
	queue<int> *result = new queue<int>;
	queue<int> *temporary = new queue<int>;

	while (!original->empty()) {
		temporary->push(original->front());
		original->pop();
	}
	while (!temporary->empty()) {
		original->push(temporary->front());
		result->push(temporary->front());
		temporary->pop();
	}

	delete temporary;

	return result;
}

void StackWithTwoQueues::print() {
	if (isEmpty()) {
		cout << "This stack is empty!";
		return;
	}

	queue<int>* tmpQ1 = copyQueue(q1);
	queue<int>* tmpQ2 = copyQueue(q2);

	cout << "[ ";

	if (!tmpQ1->empty()) {
		while (!tmpQ1->empty()) {
			cout << tmpQ1->front() << " ";
			tmpQ1->pop();
		}
	}
	else {
		while (!tmpQ2->empty()) {
			cout << tmpQ2->front() << " ";
			tmpQ2->pop();
		}
	}

	cout << "]\n";

	delete tmpQ1;
	delete tmpQ2;
}
#include <iostream>
#include <stack>
#include "QueueWithTwoStacks.h"
#include "StackWithTwoQueues.h"

using namespace std;

int main()
{
    QueueWithTwoStacks *qwts = new QueueWithTwoStacks();
    qwts->enqueue(5);
    qwts->enqueue(6);
    qwts->enqueue(7);
    qwts->enqueue(8);
    qwts->enqueue(9);

    cout << "Queue with two stacks: \n";

    qwts->print();

    cout << qwts->dequeue() << endl;

    qwts->print();

    cout << qwts->peek() << endl;

    qwts->print();

    StackWithTwoQueues* swtq = new StackWithTwoQueues();
    swtq->push(1);
    swtq->push(2);
    swtq->push(3);
    swtq->push(4);
    swtq->push(5);

    cout << "\nStack with two queues: \n";

    swtq->print();

    cout << swtq->pop() << endl;

    swtq->print();

    cout << swtq->peek() << endl;

    swtq->print();
}
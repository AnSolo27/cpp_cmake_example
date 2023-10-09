#include <iostream>

#include "linked_list.h"
#include "linked_list.cpp"

#include "stack.h"
#include "stack.cpp"

#include "queue.h"
#include "queue.cpp"

using namespace std;

int main(void) {
    Queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }
    q.print();

    for (int i = 0; i < 5; i++) {
        cout << q.dequeue() << endl;
    }
    q.print();

    return 0;
}
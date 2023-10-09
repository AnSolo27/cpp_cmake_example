#include <iostream>

#include <queue.h>

using namespace std;

//Insert
template <typename T> void Queue<T>::enqueue(T val) {
    qNode<T> *node = this->to_write;

    node->val = val;
    items++;
    node->next = new qNode<T>(0);
    
    this->to_write = node->next;
    this->to_write->next = nullptr;
}

template <typename T> void Queue<T>::print() {
    qNode<T> *node = this->to_read;
    for (auto i = 0U; i < items; i++) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

//Pull
template <typename T> T Queue<T>::dequeue() {
    T result = 0;
    if (items > 0) {
        qNode<T> *node = this->to_read;

        result = node->val;
        items--;
        this->to_read = node->next;
        delete(node);
    }
    return result;
}

template <typename T> Queue<T>::~Queue() {
    qNode<T> *node;
    T res = 0;
    for (auto i = 0U; i < items + 1; i++) {
        res = dequeue();
    }

    if (to_write == to_read) {
        delete(to_write);
    }
    else {
        delete(to_write);
        delete(to_read);
    }
}

template <typename T> Queue<T>::Queue() {
    to_write = new qNode<T>(0);
    to_write->next = nullptr;
    to_read = to_write;
    items = 0;
}


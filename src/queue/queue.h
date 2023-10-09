#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

template <typename T> class qNode {
    public:
        qNode(T value) {
            val = value;
        }
        T val;
        qNode<T> *next;
    private:

};

template <typename T> class Queue {
    public:
        Queue();
        ~Queue();
        uint32_t size() {
            return items;
        }
        void enqueue(T val);
        T dequeue();
        void print();

    private:
        uint32_t items;
        qNode<T> *to_read;
        qNode<T> *to_write;
};

#endif /* QUEUE_H */
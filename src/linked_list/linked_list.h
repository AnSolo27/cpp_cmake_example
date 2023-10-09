#ifndef LL_H
#define LL_H

#include <stdint.h>

template <typename T> class Node {
    public:
        Node(T value) {
            val = value;
        }

        //TODO clear mem in destruct
        T val;
        Node<T> *next;
    private:

};

template <typename T> class LL {
    public:
        LL() {
            head = nullptr;
            tail = nullptr;
        }
        uint32_t size();
        void add(T val);
        void prepend(T val);
        void* last();
        void print();
        void del(uint32_t num);
        T get(uint32_t num);

    private:
        Node<T> *head;
        Node<T> *tail;
};



#endif /* LL_H */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

template <typename T> class Node {
    public:
        Node(T value) {
            val = value;
        }
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

    private:
        Node<T> *head;
        Node<T> *tail;
};

template <typename T> uint32_t LL<T>::size(void) {
    uint32_t size = 0;

    Node<T> *node = this->head;
    // find last node
    while (node != nullptr)
    {
        size++;
        if (node->next != nullptr) {
            node = node->next;
        }
        else {
            node = nullptr;
        }
    }
    return size;
}

template <typename T> void LL<T>::add(T value) {
    // find last node
    Node<T> *node = this->tail;
    if (this->tail == nullptr || this->head == nullptr) {
        node = new Node<T>(value);
        this->tail = node;
        this->head = node;
        node->next = nullptr;
    }
    else {
        node->next = new Node<T>(value);
        if (node->next != nullptr) {
            node = node->next;
            node->next = nullptr;
            this->tail = node;
        }
    }
    
}

template <typename T> void LL<T>::print(void) {
    Node<T> *node = this->head;
    // find last node
    for (uint32_t i = 0; i < this->size(); i++)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

template <typename T> void LL<T>::prepend(T value) {
    if (this->head == nullptr || this->tail == nullptr) {
        this->add(value);
    }
    else {
        Node<T> *node = new Node<T>(value);
        node->next = this->head;
        this->head = node;
    }
}

template <typename T> void LL<T>::del(uint32_t num) {
    Node<T> *node = this->head;
    Node<T> *prv_node = this->head;
    if (num > this->size() || this->head == nullptr) {
        return;
    }
    for (uint32_t i = 0; i < num; i++) {
        if (node != nullptr && node->next != nullptr) {
            prv_node = node;
            node = node->next;
        }
    }
    if (node == this->head) {
        //del head
        this->head = node->next;
        delete(node);
    }
    else if (node == this->tail) {
        this->tail = prv_node;
        delete(node);
    }
    else {
        prv_node->next = node->next;
        delete(node);
    }
}

//TODO insert

int main(void) {

    LL<int> list;
    list.add(34);
    list.add(36);
    list.prepend(4);
    list.prepend(1);

    list.print();
    list.del(0);
    list.del(0);
    list.del(0);
    list.del(0);
    list.del(0);
    list.del(0);
    list.prepend(1);
    cout << "Size = " << list.size() << endl;
    list.print();
    /*
    list.add(5);
    cout << "Size = " << list.size() << endl;
    list.add(1);
    list.add(2);
    list.add(3);

    list.add_at_start(55);
    list.add_at_start(66);
    list.print();
    list.del(44);
    list.print();
    */
    return 0;
}
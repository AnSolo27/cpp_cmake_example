#include <iostream>

#include <linked_list.h>

using namespace std;

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


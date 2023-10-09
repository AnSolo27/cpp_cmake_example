#include <iostream>
#include "stack.h"

using namespace std;

template <typename T> T Stack<T>::pop(void) {
    T res = 0;
    if (c_size > 0) {
        res = data[c_size - 1];
        c_size--;
    }
    return res;
}

template <typename T> void Stack<T>::push(T val) {
    if (c_size < max_size) {
        data[c_size] = val;
        c_size++;
    }
}

template <typename T> void Stack<T>::print() {
    for (uint32_t i = c_size; i > 0; i--) {
        cout << data[i - 1] << " ";
    }
    cout << endl;
}

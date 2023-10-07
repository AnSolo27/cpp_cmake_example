#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

template <typename T> class Stack {
    public:
        Stack(uint32_t stack_size) {
            max_size = stack_size;
            c_size = 0;
            data = new T[max_size];
        }
        ~Stack() {
            delete(data);
        }
        uint32_t size() {
            return c_size;
        }
        bool empty() {
            bool result = false;
            if (c_size == 0) {
                result == true;
            }
            return result;
        }
        T pop();
        void push(T val);
        void print();

    private:
        uint32_t max_size;
        uint32_t c_size;
        T *data;
};


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



//TODO insert

int main(void) {
    Stack<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    cout << stack.pop() << endl;
    stack.print();
    return 0;
}
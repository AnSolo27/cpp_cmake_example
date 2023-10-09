#ifndef STACK_H
#define STACK_H

#include <stdint.h>

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

#endif /* STACK_H */
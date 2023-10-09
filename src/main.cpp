#include <iostream>

#include "linked_list.h"
#include "linked_list.cpp"

#include "stack.h"
#include "stack.cpp"

using namespace std;

int main(void) {
    LL<int> list;
    list.add(3);
    
    list.add(34);
    list.add(36);
    list.prepend(4);
    list.prepend(1);

    list.print();
    list.del(0);
    list.prepend(1);
    cout << "Size = " << list.size() << endl;
    list.print();

    Stack<char> st(10);
    st.push(3);
    st.push(5);
    st.print();
    

    return 0;
}
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    MyArray myarray(4);
    MyStack mystack(myarray);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    cout << "Stack elements:" << endl;
    myarray.output();
    cout << mystack.pop() << endl;
    cout << mystack.peek() << endl;
    cout << mystack.isEmpty() << endl;

    return 0;
}

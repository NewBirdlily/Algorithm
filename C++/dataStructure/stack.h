#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "array.h"
using namespace std;

class MyStack {
public:
    // 构造函数
    MyStack(MyArray& myarray) : myarray(myarray) {}

    // 判断堆栈是否为空
    bool isEmpty() const {
        return myarray.getSize() == 0;
    }

    // 入栈
    void push(int item) {
        myarray.insert(myarray.getSize(), item);
    }

    // 出栈
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        return myarray.remove(myarray.getSize() - 1);
    }

    // 获取栈顶元素
    int peek() const {
        if (isEmpty()) {
            return -1;
        }
        return myarray[myarray.getSize() - 1];
    }

private:
    MyArray& myarray;
};
#endif
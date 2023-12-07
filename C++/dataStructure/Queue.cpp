#include<iostream>
#include"Queue.h"
using namespace std;

int main(){
    MyQueue myQueue(6);
    myQueue.enQueue(3);
    myQueue.enQueue(5);
    myQueue.enQueue(6);
    myQueue.enQueue(8);
    myQueue.enQueue(1);
    myQueue.deQueue();
    myQueue.deQueue();
    myQueue.deQueue();
    myQueue.enQueue(2);
    myQueue.enQueue(4);
    myQueue.enQueue(9);
    myQueue.output();
    return 0;
}
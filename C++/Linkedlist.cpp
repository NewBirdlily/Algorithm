#include<iostream>
#include"Linkedlist.h"
using namespace std;

int main() {
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->insert(3, 0);
    myLinkedList->insert(7, 1);
    myLinkedList->insert(9, 2);
    myLinkedList->insert(5, 3);
    myLinkedList->insert(6, 1);
    myLinkedList->output();
    myLinkedList->remove(2);
    myLinkedList->output();
    return 0;
}

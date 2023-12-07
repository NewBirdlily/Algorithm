#include<iostream>
using namespace std;

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node<T>(T val) : data(val), next(nullptr) {}
    template<typename U>friend class MyLinkedList;
};

template<typename T>
class MyLinkedList {
private:
    Node<T>* head;
    Node<T>* last;
    int size;
public:
    MyLinkedList() : head(nullptr), last(nullptr), size(0) {}

    bool isEmpty() const {
        return (size == 0);
    }

    void insert(T data, int index) {
        if (index < 0 || index > size) {
            cout << "超出链表节点范围！" << endl;
            return;
        }

        Node<T>* insertedNode = new Node<T>(data);

        if (size == 0) {
            //空链表
            head = insertedNode;
            last = insertedNode;
        }
        else if (index == 0) {
            //插入头部
            insertedNode->next = head;
            head = insertedNode;
        }
        else if (size == index) {
            //插入尾部
            last->next = insertedNode;
            last = insertedNode;
        }
        else {
            //插入中间
            Node<T>* prevNode = get(index - 1);
            insertedNode->next = prevNode->next;
            prevNode->next = insertedNode;
        }
        size++;
    }

    Node<T>* remove(int index) {
        if (index < 0 || index >= size) {
            cout << "超出链表节点范围！" << endl;
            return nullptr;
        }

        Node<T>* removedNode = nullptr;
        if (index == 0) {
            //删除头节点
            removedNode = head;
            head = head->next;
        }
        else if (index == size - 1) {
            //删除尾节点
            Node<T>* prevNode = get(index - 1);
            removedNode = prevNode->next;
            prevNode->next = nullptr;
            last = prevNode;
        }
        else {
            //删除中间的节点
            Node<T>* prevNode = get(index - 1);
            Node<T>* nextNode = prevNode->next->next;
            removedNode = prevNode->next;
            prevNode->next = nextNode;
        }
        size--;
        return removedNode;
    }

    T  removeFirst() {
        if (head == nullptr) {
            cout << "链表为空！" << endl;
            return T();
        }    
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr) {
            last = nullptr;
        }

        return data;
    }

    Node<T>* get(int index) {
        if (index < 0 || index >= size) {
            cout << "超出链表节点范围！" << endl;
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void output() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};
#endif

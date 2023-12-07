#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include"array.h"
using namespace std;

class MyQueue{
    private:
        int *array;
        int front;
        int rear;
        int capacity;

    public:
        MyQueue(int capacity){
            this->capacity=capacity;
            array =new int [capacity];
            front=0;
            rear=0;
        }
        
        
        //入队
        void enQueue(int element){
            if((rear+1) % capacity == front) {
                cout<<"队列已满！"<<endl;
            } 
            else {
                array[rear]=element;
                rear=(rear+1)%capacity;
            }
        }   

        //出队
        int deQueue(){
            if(rear == front) {
                cout<<"队列已空!"<<endl;
                return -1;
            } 
            else {
                int deQueueElement = array[front];
                front = (front+1) % capacity;
                return deQueueElement;
            }
        }

        //输出队列
        void output(){
            for(int i=front;i!=rear;i=(i+1)%capacity){
                cout<<array[i]<<' ';
            }
            cout<<endl;
        }
    
};
#endif
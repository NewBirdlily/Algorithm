#include<iostream>
using namespace std;

#ifndef _ARRAY_H
#define _ARRAY_H

class MyArray{
public:
    MyArray(int capacity){
        array = new int[capacity];
        size = 0;
        this->capacity=capacity;
    }
    //数组插入元素
    void insert(int index,int element) {
        //判断访问下标是否超出范围
        if(index<0||index>size)
            cout<<"超出数组实际元素范围！"<<endl;
        //如果实际元素达到数组容量上限，则对数组进行扩容
        if(size>=capacity)
        resize();
        //从右向左循环，将元素逐个向右挪一位
        for(int i=size-1;i>=index;i--)
            array[i+1]=array[i];
        //腾出的位置放入新元素
        array[index]=element;
        size++;
    }
    //数组元素的删除
    int remove(int index){
        if(index<0||index>=size)
        cout<<"超出数组实际元素范围"<<endl;
        int removedElement=array[index];
        //从左向右循环，将元素逐个向左挪1位
        for(int i=index;i<size-1;i++)
        array[i]=array[i+1];
        size--;
        return removedElement;
    }
    //数组扩容
    void resize(){
        int *arrayNew =new int[capacity * 2];
        //从旧数组复制到新数组
        for(int i=0;i<size;++i){
            arrayNew[i]=array[i];
        }
        delete[] array;
        array = arrayNew;
        capacity *=2;
        cout<<capacity<<endl;
    }
    //输出数组
    void output(){
        for(int i=0;i<size;i++)
            cout<<array[i]<<' ';
        cout<<endl;
    }
private:
    int* array;
    int size;
    int capacity;
};
#endif

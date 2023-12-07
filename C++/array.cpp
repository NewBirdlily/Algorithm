#include<iostream>
#include"array.h"
using namespace std;

int main(){
    //MyArray myArray(10);
    MyArray myArray(4);
    myArray.insert(0,3);
    myArray.insert(1,7);
    myArray.insert(2,9);
    myArray.insert(3,5);
    myArray.insert(1,6);
    myArray.output();
    myArray.remove(2);
    myArray.output();
    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

class StackQueue{
    private:
        stack<int> stackA;
        stack<int> stackB;
        void transfer(){
            while(!stackA.empty()){
                int result1 =stackA.top();
                stackA.pop();
                stackB.push(result1);
            }
        }
    public:
        void enQueue(int element){
            stackA.push(element);
        }
        int deQueue(){
            if(stackB.empty()){
                if(stackA.empty()){
                    return -1;
                }
                transfer();
            }
            int result2 =stackB.top();
            stackB.pop();
            return result2;
        }
};

int main(){
    StackQueue stackqueue;
    stackqueue.enQueue(1);
    stackqueue.enQueue(2);
    stackqueue.enQueue(3);
    cout<<stackqueue.deQueue()<<endl;
    cout<<stackqueue.deQueue()<<endl;
    stackqueue.enQueue(4);
    cout<<stackqueue.deQueue()<<endl;
    cout<<stackqueue.deQueue()<<endl;
}
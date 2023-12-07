#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    private:
        stack<int> mainStack;
        stack<int> minStack;
    
    public:
        void push(int element){
            mainStack.push(element);
            //如果辅助栈为空，或者新元素小于或等于辅助栈栈顶，则将新元素压入辅助栈
            if(minStack.empty() ||element <=minStack.top()){
                minStack.push(element);
            }
        }
        int pop(){
            //如果出栈元素和辅助栈栈顶元素值相等，辅助栈出栈
            if(mainStack.top() == minStack.top()){
                minStack.pop();
            }
            int result =mainStack.top();
            mainStack.pop();
            return result;
        }

        int getMin(){
            if(mainStack.empty()){
                cout<<"stack is empty!"<<endl;
                return -1;
            }
            return minStack.top();
        }

};

int main(){
    MinStack stack;
    stack.push(4);
    stack.push(9);
    stack.push(7);
    stack.push(3);
    stack.push(8);
    stack.push(5);
    cout<<stack.getMin()<<endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<stack.getMin()<<endl;
    return 0;
}
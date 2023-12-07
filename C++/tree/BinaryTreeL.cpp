#include<iostream>
#include"BinaryTree.h"
using namespace std;

template<typename T>
class Queue{
    private:
        int front;
        int rear;
        int capacity;
        T* arr; // 需要一个数组来存储队列元素
    public:
        Queue(int capacity){
            this->capacity = capacity;
            front = 0;
            rear = 0;
            arr = new T[capacity]; // 动态分配数组空间
        }
        void enQueue(T val){
            arr[rear] = val;
            rear = (rear + 1) % capacity; // 使用取模运算实现循环队列
        }
        T deQueue(){
            T val = arr[front];
            front = (front + 1) % capacity;
            return val;
        }
        bool isEmpty(){
            return front == rear;
        }
};

// 二叉树层序非递归遍历
class BinaryTreeL{
    public:
        static void levelOrderTraversal(TreeNode* root){ // 参数应该为指针类型
            if(root == nullptr){
                return;
            }
            Queue<TreeNode*> queue(20); // 假设队列容量为20
            queue.enQueue(root);
            while(!queue.isEmpty()){
                TreeNode* node = queue.deQueue();
                cout << node->data << endl;
                if(node->leftChild != nullptr){
                    queue.enQueue(node->leftChild);
                }
                if(node->rightChild != nullptr){
                    queue.enQueue(node->rightChild);
                }
            }
        }
};

int main(){
    // 创建一个包含多节点的二叉树
    TreeNode* root = new TreeNode(1);
    root->leftChild = new TreeNode(2);
    root->rightChild = new TreeNode(3);
    root->leftChild->leftChild = new TreeNode(4);
    root->leftChild->rightChild = new TreeNode(5);
    root->rightChild->rightChild = new TreeNode(6);

    cout << "层序非递归遍历：" << endl;
    BinaryTreeL::levelOrderTraversal(root); 

    // 释放内存空间
    delete root->leftChild->leftChild;
    delete root->leftChild->rightChild;
    delete root->rightChild->rightChild;
    delete root->leftChild;
    delete root->rightChild;
    delete root;

    return 0;
}

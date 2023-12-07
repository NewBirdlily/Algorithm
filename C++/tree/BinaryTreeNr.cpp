#include<iostream>
#include"BinaryTree.h"
using namespace std;

template<typename T>
class MyStack{
    private: 
        T*arr;
        int capacity;
        int topIndex;
    public:
        MyStack(int cap) : capacity(cap),topIndex(-1){
            arr =new T[capacity];
        }

        void push(T val){
            arr[++topIndex] = val;
        }
        
        T pop(){
            return arr[topIndex--];
        }
        bool isEmpty(){
            return topIndex ==-1;
        }
        T peek() {
            return arr[topIndex];
        }
};

// 二叉树非递归遍历
class BinaryTreeNr{
    public:
        // 前序遍历（根-左-右）
        static void preOrderTraveralWithStack(TreeNode* root){
            MyStack<TreeNode*> stack(6);
            TreeNode* treenode = root;
            while(treenode != nullptr || !stack.isEmpty()){
                // 迭代访问节点的左孩子，并入栈
                while(treenode != nullptr){
                    cout << treenode->data << endl;
                    stack.push(treenode);
                    treenode = treenode->leftChild;
                }
                // 如果节点没有左孩子，则弹出栈顶节点，访问节点右孩子
                if(!stack.isEmpty()){
                    treenode = stack.pop();
                    treenode = treenode->rightChild;
                }
            }
        }

        // 中序遍历（左-根-右）
        static void inOrderTraveralWithStack(TreeNode* root){
            MyStack<TreeNode*> stack(6);
            TreeNode* treenode = root;
            while(treenode != nullptr || !stack.isEmpty()){
                // 迭代访问节点的左孩子并入栈
                while(treenode != nullptr){
                    stack.push(treenode);
                    treenode = treenode->leftChild;
                }
                // 如果节点没有左孩子，则弹出栈顶节点，访问节点值，并转向右孩子
                if(!stack.isEmpty()){
                    treenode = stack.pop();
                    cout << treenode->data << endl;
                    treenode = treenode->rightChild;
                }
            }
        }

        // 后序遍历（左-右-根）
        static void postOrderTraveralWithStack(TreeNode* root){
            MyStack<TreeNode*> stack(6);
            TreeNode* treenode = root;
            TreeNode* lastVisitNode = nullptr; // 记录上次访问的节点
            while(treenode != nullptr || !stack.isEmpty()){
                // 迭代访问节点的左孩子并入栈
                while(treenode != nullptr){
                    stack.push(treenode);
                    treenode = treenode->leftChild;
                }
                // 获取当前栈顶节点，但不弹出
                TreeNode* topNode = stack.peek();
                // 如果当前节点没有右孩子或者右孩子已经访问过，则访问当前节点
                if(topNode->rightChild == nullptr || topNode->rightChild == lastVisitNode){
                    cout << topNode->data << endl;
                    stack.pop();
                    lastVisitNode = topNode;
                } else { // 否则访问右孩子节点
                    treenode = topNode->rightChild;
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

    // 前序遍历
    cout << "前序非递归遍历：" << endl;
    BinaryTreeNr::preOrderTraveralWithStack(root);

    // 中序遍历
    cout << "中序非递归遍历：" << endl;
    BinaryTreeNr::inOrderTraveralWithStack(root);

    // 后序遍历
    cout << "后序非递归遍历：" << endl;
    BinaryTreeNr::postOrderTraveralWithStack(root);

    // 释放内存空间
    delete root->leftChild->leftChild;
    delete root->leftChild->rightChild;
    delete root->rightChild->rightChild;
    delete root->leftChild;
    delete root->rightChild;
    delete root;

    return 0;
}

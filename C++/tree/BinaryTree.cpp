#include<iostream>
#include"BinaryTree.h"
using namespace std;

 int main(){
    MyLinkedList<int> inputList;
    inputList.insert(3, 0);
    inputList.insert(2, 1);
    inputList.insert(9, 2);
    inputList.insert(INT_MAX, 3);
    inputList.insert(INT_MAX, 4);
    inputList.insert(10, 5);
    inputList.insert(INT_MAX, 6);
    inputList.insert(INT_MAX, 7);
    inputList.insert(8, 8);
    inputList.insert(INT_MAX, 9);
    inputList.insert(4, 10);
    TreeNode* treeNode = TreeNode::createBinaryTree(inputList);
    cout<<"前序遍历："<<endl;
    TreeNode::preOrderTraveral(treeNode);
    cout<<"中序遍历："<<endl;
    TreeNode::inOrderTraveral(treeNode);
    cout<<"后序遍历："<<endl;
    TreeNode::postOrderTraveral(treeNode);
    return 0;
 }
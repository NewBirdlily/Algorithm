#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include<iostream>
#include<climits>
#include"Linkedlist.h"
using namespace std;

class TreeNode{
    public:
    TreeNode(int val):data(val),leftChild(nullptr),rightChild(nullptr){}
    //构建二叉树
    //输入序列
    static TreeNode* createBinaryTree(MyLinkedList<int>& inputList){
        if(inputList.isEmpty()){
            return nullptr;
        }
        int data = inputList.removeFirst();
        if(data ==INT_MAX){
            return nullptr;
        }
            TreeNode* node = new TreeNode(data);
            node->leftChild = createBinaryTree(inputList);
            node->rightChild = createBinaryTree(inputList);
            return node;
    }

    //二叉树前序遍历
    static void preOrderTraveral(TreeNode* node){
        if(node ==nullptr)
            return ;
        cout<<node->data << endl;
        preOrderTraveral(node->leftChild);
        preOrderTraveral(node->rightChild);
    }

    // 二叉树中序遍历
    static void inOrderTraveral(TreeNode* node){
        if(node == nullptr)
            return ;
        inOrderTraveral(node->leftChild);
        cout<<node->data<<endl;
        inOrderTraveral(node->rightChild);
    }

    //二叉树后序遍历
    static void postOrderTraveral(TreeNode* node){
        if(node ==nullptr){
            return ;
        }
        postOrderTraveral(node->leftChild);
        postOrderTraveral(node->rightChild);
        cout<<node->data<<endl;
    }
    //private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    
    friend class BinaryTreeNr;
};
#endif
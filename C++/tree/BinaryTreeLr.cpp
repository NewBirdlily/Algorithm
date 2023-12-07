#include<iostream>
#include"BinaryTree.h"
using namespace std;

class BinaryTreeLr{
    public:
    int height(TreeNode* root){
        if(root ==nullptr){
            return 0;
        }else{
            int left_height = height(root->leftChild);
            int right_height =height(root->rightChild);
            return max(left_height,right_height) +1;
        }
    }
    void printLevelOrder(TreeNode* root,int level){
        if(root == nullptr){
            return ;
        }
        if(level ==1){
            cout <<root->data<<" ";
        }else if(level >1){
            printLevelOrder(root->leftChild,level -1);
            printLevelOrder(root->rightChild,level -1);
        }
    }
    void levelOrderRecursive(TreeNode* root){
        int h =height(root);
        for(int i = 1;i<=h;i++){
            printLevelOrder(root,i);
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

    BinaryTreeLr binaryTreeLr; // 实例化 BinaryTreeLr 类
    cout << "层序递归遍历：" << endl;
    binaryTreeLr.levelOrderRecursive(root); 

    // 释放内存空间
    delete root->leftChild->leftChild;
    delete root->leftChild->rightChild;
    delete root->rightChild->rightChild;
    delete root->leftChild;
    delete root->rightChild;
    delete root;

    return 0;
}

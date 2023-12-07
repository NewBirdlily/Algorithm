from BinaryTree import TreeNode
from stack import MyStack

class BinaryTree:
    def __init__(self, root):
        self.root = root
    
    @staticmethod
    # 二叉树非递归前序遍历
    def preOrderTraveralWithStack(root):
        stack = MyStack(6)
        treenode = root
        while treenode is not None or not stack.is_empty():
            # 迭代访问节点的左孩子，并入栈
            while treenode is not None:
                print(treenode.data)
                stack.push(treenode)
                treenode = treenode.leftChild
            # 如果没有左孩子，则弹出栈顶节点，访问节点右孩子
            if not stack.is_empty():
                treenode = stack.pop()
                treenode = treenode.rightChild 

    @staticmethod
    # 二叉树非递归中序遍历
    def inOrderTraveralWithStack(root):
       stack = MyStack(7)
       treenode = root
       while treenode is not None or not stack.is_empty():
        # 迭代访问节点的左孩子，并入栈
        while treenode is not None:
            stack.push(treenode)
            treenode = treenode.leftChild
        # 如果没有左孩子，则弹出栈顶节点并访问。然后转向右子树
        if not stack.is_empty():
            treenode = stack.pop()
            print(treenode.data)
            treenode = treenode.rightChild

    @staticmethod
    # 二叉树非递归后序遍历
    def postOrderTraveralWithStack(root):
        stack1= MyStack(6)
        stack2= MyStack(6)
        stack1.push(root)
        while not stack1.is_empty():
            treenode = stack1.pop()
            stack2.push(treenode)
            if treenode.leftChild is not None:
                stack1.push(treenode.leftChild)
            if treenode.rightChild is not None:
                stack1.push(treenode.rightChild)
        while not stack2.is_empty():
            print(stack2.pop().data)


if __name__ == "__main__":
    # 创建一个包含多个节点的二叉树
    root = TreeNode(1) 
    root.leftChild = TreeNode(2)
    root.rightChild = TreeNode(3)
    root.leftChild.leftChild = TreeNode(4)
    root.leftChild.rightChild = TreeNode(5)
    root.rightChild.rightChild = TreeNode(6)
    #创建二叉树对象 
    tree = BinaryTree(root)

    print("前序非递归遍历：")
    BinaryTree.preOrderTraveralWithStack(tree.root)

    print("中序非递归遍历：")
    BinaryTree.inOrderTraveralWithStack(tree.root)

    print("后序非递归遍历：")
    BinaryTree.postOrderTraveralWithStack(tree.root)

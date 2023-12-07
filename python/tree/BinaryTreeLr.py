from Queue import MyQueue
from BinaryTree import TreeNode

class BinaryTree:
    def __init__(self, root):
        self.root = root

    @staticmethod
    def levelOrderTraversal(root):
        queue = MyQueue(8)
        queue.enQueue(root)
        while queue.front != queue.rear:
            node = queue.deQueue()
            print(node.data)
            if node.leftChild is not None:
                queue.enQueue(node.leftChild)
            if node.rightChild is not None:  
                queue.enQueue(node.rightChild)


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

    print("二叉树层序遍历：")
    BinaryTree.levelOrderTraversal(tree.root)
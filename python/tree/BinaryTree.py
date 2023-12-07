from Linkedlist import MyLinkedList

class TreeNode:
    def __init__(self, val):
        self.data = val
        self.leftChild = None
        self.rightChild = None

    # 构建二叉树
    @staticmethod
    def createBinaryTree(inputList):
        node = None
        if inputList.is_empty():
            return None
        data = inputList.pop(0)
        if data is not None:
            node = TreeNode(data)
            node.leftChild = TreeNode.createBinaryTree(inputList)
            node.rightChild = TreeNode.createBinaryTree(inputList)
        return node

    # 二叉树前序遍历(根-左-右)
    @staticmethod
    def preOrderTraveral(node):
        if node is None:
            return 
        print(node.data)
        TreeNode.preOrderTraveral(node.leftChild)
        TreeNode.preOrderTraveral(node.rightChild)
        
    # 二叉树中序遍历(左-根-右)
    @staticmethod
    def inOrderTraveral(node):
        if node is None:
            return 
        TreeNode.inOrderTraveral(node.leftChild)
        print(node.data)
        TreeNode.inOrderTraveral(node.rightChild)

    # 二叉树后序遍历(左-右-根)
    @staticmethod
    def postOrderTraveral(node):
        if node is None:
            return 
        TreeNode.postOrderTraveral(node.leftChild)
        TreeNode.postOrderTraveral(node.rightChild)
        print(node.data)

if __name__ == "__main__":
    inputList = MyLinkedList()
    inputList.insert(3, 0)
    inputList.insert(2, 1)
    inputList.insert(9, 2)
    inputList.insert(None, 3)
    inputList.insert(None, 4)
    inputList.insert(10, 5)
    inputList.insert(None, 6)
    inputList.insert(None, 7)
    inputList.insert(8, 8)
    inputList.insert(None, 9)
    inputList.insert(4, 10)
    treeNode = TreeNode.createBinaryTree(inputList)

    print("前序遍历：")
    TreeNode.preOrderTraveral(treeNode)

    print("中序遍历：")
    TreeNode.inOrderTraveral(treeNode)

    print("后序遍历：")
    TreeNode.postOrderTraveral(treeNode)
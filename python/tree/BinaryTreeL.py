from BinaryTree import TreeNode

class BinaryTree:
    def __init__(self, root):
        self.root = root

def levelOrderTraversal(root,level):
    if root is None:
        return
    if level ==1:
        print(root.data)
    elif level >1:
        levelOrderTraversal(root.leftChild,level-1)
        levelOrderTraversal(root.rightChild,level-1)

def height(node):
    if node is None:
        return 0
    else:
        leftChild_height = height(node.leftChild)
        rightChild_height = height(node.rightChild)

        return max(leftChild_height,rightChild_height) + 1

def printLevelOrder(root):
    h = height(root)
    for i in range(1,h+1):
        levelOrderTraversal(root,i)


if __name__ == "__main__":
    # 创建一个包含多个节点的二叉树
    root = TreeNode(1) 
    root.leftChild = TreeNode(2)
    root.rightChild = TreeNode(3)
    root.leftChild.leftChild = TreeNode(4)
    root.leftChild.rightChild = TreeNode(5)
    root.rightChild.rightChild = TreeNode(6)

    print("二叉树层序递归遍历：")
    printLevelOrder(root)

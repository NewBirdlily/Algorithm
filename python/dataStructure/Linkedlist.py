class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = None
        self.last = None
        self.size = 0
    
    def is_empty(self):
        return self.size == 0
    
    def pop(self, index):
        if index <0 or index >=self.size:
            raise IndexError("Index out of range")

        if index ==0:
            data =self.head.data
            self.head = self.head.next
        else:
            prev_node = self.__get_node(index -1)
            curr_node = prev_node.next
            data = curr_node.data
            prev_node.next =curr_node.next

        self.size -=1
        return data
    
    def insert(self, data, index):
        if index < 0 or index > self.size:
            print("超出链表节点范围！")
            return

        insertedNode = Node(data)

        if self.size == 0:
            # 空链表
            self.head = insertedNode
            self.last = insertedNode
        elif index == 0:
            # 插入头部
            insertedNode.next = self.head
            self.head = insertedNode
        elif self.size == index:
            # 插入尾部
            self.last.next = insertedNode
            self.last = insertedNode
        else:
            # 插入中间
            prevNode = self._get(index - 1)
            insertedNode.next = prevNode.next
            prevNode.next = insertedNode
        self.size += 1

    def remove(self, index):
        if index < 0 or index >= self.size:
            print("超出链表节点范围！")
            return None

        removedNode = None
        if index == 0:
            # 删除头节点
            removedNode = self.head
            self.head = self.head.next
        elif index == self.size - 1:
            # 删除尾节点
            prevNode = self._get(index - 1)
            removedNode = prevNode.next
            prevNode.next = None
            self.last = prevNode
        else:
            # 删除中间的节点
            prevNode = self._get(index - 1)
            nextNode = prevNode.next.next
            removedNode = prevNode.next
            prevNode.next = nextNode
        self.size -= 1
        return removedNode

    def _get(self, index):
        if index < 0 or index >= self.size:
            print("超出链表节点范围！")
            return None
        temp = self.head
        for i in range(index):
            temp = temp.next
        return temp

    def output(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=' ')
            temp = temp.next
        print()

if __name__ == "__main__":
    myLinkedList = MyLinkedList()
    myLinkedList.insert(3, 0)
    myLinkedList.insert(7, 1)
    myLinkedList.insert(9, 2)
    myLinkedList.insert(5, 3)
    myLinkedList.insert(6, 1)
    myLinkedList.output()
    myLinkedList.remove(2)
    myLinkedList.output()

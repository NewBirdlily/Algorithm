# class Node:
#     def __init__(self,data):
#         self.data = data
#         self.next = None

# class IsCycle:
#     @staticmethod
#     def isCycle(head):
#         p1 = head
#         p2 = head
#         while p2 is not None and p2.next is not None:
#             p1 = p1.next
#             p2 = p2.next.next
#             if p1 == p2:
#                 return True
#         return False
    
# if __name__ =="__main__":
#     node1 = Node(5)
#     node2 = Node(3)
#     node3 = Node(7)
#     node4 = Node(2)
#     node5 = Node(6)
#     node6 = Node(8)
#     node7 = Node(1)
#     node1.next = node2
#     node2.next = node3
#     node3.next = node4
#     node4.next = node5
#     node5.next = node6
#     node6.next = node7
#     node7.next = node4
#     print(IsCycle.isCycle(node1))
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
    
    def append_node(self,node):
        if self.head is None:
            self.head = node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = node

            #将末尾节点的next指针指向头节点，形成环
            node.next = self.head

    def is_cycle(self):
        p1 = self.head
        p2 = self.head
        cycle_found =False

        while p2 and p2.next:
            p1 = p1.next
            p2 = p2.next.next

            if p1 == p2:
                cycle_found =True
                break
        
        if not cycle_found:
            return False

        #计算环的长度
        length = 1
        p1 = p1.next
        while p1 != p2:
            p1 = p1.next
            length +=1
        
        # 找到入环点
        p1 = self.head
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next

        return length, p1.data


if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.append(5)
    linked_list.append(3)
    linked_list.append(7)
    linked_list.append(2)
    linked_list.append(6)
    linked_list.append(8)
    linked_list.append(1)

    #创建环
    node4 = linked_list.head.next.next.next
    linked_list.append_node(node4)

    cycle_length,entry_point = linked_list.is_cycle()
    print("Cycle Length:",cycle_length)
    print("Entry Point:",entry_point)
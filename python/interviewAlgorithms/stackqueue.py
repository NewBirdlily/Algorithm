class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0


class StackQueue:
    def __init__(self):
        self.stackA = Stack()
        self.stackB = Stack()

    #入队操作
    def enQueue(self, element):
        self.stackA.push(element)

    #出队操作
    def deQueue(self):
        if not self.stackB.is_empty():
            return self.stackB.pop()

        if self.stackA.is_empty():
            return -1
        
        self.transfer()
        return self.stackB.pop()

    #栈A元素转移到栈B
    def transfer(self):
        while not self.stackA.is_empty():
            self.stackB.push(self.stackA.pop())


if __name__ == "__main__":
    stackqueue = StackQueue()
    stackqueue.enQueue(1)
    stackqueue.enQueue(2)
    stackqueue.enQueue(3)
    print(stackqueue.deQueue())
    print(stackqueue.deQueue())
    stackqueue.enQueue(4)
    print(stackqueue.deQueue())
    print(stackqueue.deQueue())

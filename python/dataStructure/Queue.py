class MyQueue:
    def __init__(self, capacity):
        self.array = [0] * capacity
        self.capacity = capacity
        self.front = 0
        self.rear = 0

    # 入队
    def enQueue(self, element):
        if (self.rear + 1) % self.capacity == self.front:
            print("队列已满！")
        else:
            self.array[self.rear] = element
            self.rear = (self.rear + 1) % self.capacity

    # 出队
    def deQueue(self):
        if self.rear == self.front:
            print("队列已空！")
            return None
        else:
            deQueueElement = self.array[self.front]
            self.front = (self.front + 1) % self.capacity
            return deQueueElement

    # 输出队列
    def output(self):
        if self.front == self.rear:
            print("队列已空！")
        else:
            i = self.front
            while i != self.rear:
                print(self.array[i], end=' ')
                i = (i + 1) % self.capacity
            print()

if __name__ == "__main__":
    myQueue = MyQueue(6)
    myQueue.enQueue(3)
    myQueue.enQueue(5)
    myQueue.enQueue(6)
    myQueue.enQueue(8)
    myQueue.enQueue(1)
    myQueue.deQueue()
    myQueue.deQueue()
    myQueue.deQueue()
    myQueue.enQueue(2)
    myQueue.enQueue(4)
    myQueue.enQueue(9)
    myQueue.output()

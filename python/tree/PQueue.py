# 最大优先队列
class PriorityQueue_max:
    def __init__(self):
        self.array = [0] * 32
        self.size = 0

    # 入队
    def enQueue(self, key):
        if self.size >= len(self.array):
            self.resize()
        self.array[self.size] = key
        self.size += 1
        self.upAdjust_max()

    # 出队
    def deQueue(self):
        if self.size <= 0:
            print("the queue is empty!")
            return None
        # 获取堆顶元素
        head = self.array[0]
        # 将最后一个元素移动到堆顶
        self.array[0] = self.array[self.size - 1]
        self.size -= 1
        self.downAdjust_max()
        return head

    def resize(self):
        # 队列容量翻倍
        new_array = [0] * (len(self.array) * 2)
        for i in range(self.size):
            new_array[i] = self.array[i]
        self.array = new_array
    
    def upAdjust_max(self):
        childIndex = self.size - 1
        parentIndex = (childIndex - 1) //2
        #temp保存插入的叶子节点值，用于最后赋值
        temp = self.array[childIndex] 
        while childIndex > 0 and temp > self.array[parentIndex]:
            #无须真正交换，单向赋值即可
            self.array[childIndex] = self.array[parentIndex]
            childIndex = parentIndex
            parentIndex = (parentIndex - 1) //2
        self.array[childIndex] = temp
    
    def downAdjust_max(self):
        parentIndex = 0
        #temp保存父节点的值，用于最后赋值
        temp = self.array[parentIndex]
        childIndex = 1
        while childIndex < self.size:
            # 如果有右孩子，且右孩子的值大于左孩子的值，则定位到右孩子
            if childIndex + 1 < self.size and self.array[childIndex + 1] > self.array[childIndex]:
                childIndex += 1
            # 如果父节点大于任何一个孩子节点，则直接跳出
            if temp >= self.array[childIndex]:
                break
            # 无须真正交换，单向赋值即可
            self.array[parentIndex] = self.array[childIndex]
            parentIndex = childIndex
            childIndex = 2 * childIndex + 1
        self.array[parentIndex] = temp



# 最小优先队列
class PriorityQueue_min:
    def __init__(self):
        self.array= [0] *32
        self.size = 0

    # 入队
    def enQueue(self, key):
        if self.size >= len(self.array):
            self.resize()
        self.array[self.size] = key
        self.size += 1
        self.upAdjust_min()

    # 出队
    def deQueue(self):
        if self.size <= 0:
            print("the queue is empty!")
            return None
        # 获取堆顶元素
        head = self.array[0]
        # 将最后一个元素移动到堆顶
        self.array[0] = self.array[self.size-1]
        self.size -= 1
        #self.array.pop()
        self.downAdjust_min()
        return head

    def resize(self):
        # 队列容量翻倍
        new_array = [0] * (len(self.array) * 2)
        for i in range(self.size):
            new_array[i] = self.array[i]
        self.array = new_array
    
    def upAdjust_min(self):
        childIndex = self.size -1
        parentIndex = (childIndex -1) //2
        #temp保存插入的叶子节点值，用于最后赋值
        temp = self.array[childIndex] 
        while childIndex >0 and temp < self.array[parentIndex]:
            self.array[childIndex] = self.array[parentIndex]
            childIndex = parentIndex
            parentIndex = (parentIndex -1) //2
        self.array[childIndex] =temp
    
    def downAdjust_min(self):
        parentIndex = 0
        childIndex =1
        #temp保存父节点的值，用于最后赋值
        temp = self.array[parentIndex]
        while childIndex <self.size:
            #如果有右孩子，且右孩子的值小于左孩子，则定位到右孩子
            if childIndex +1< self.size and self.array[childIndex+1]<self.array[childIndex]:
                childIndex +=1
            #如果父节点小于所有孩子节点，直接跳出
            if temp <self.array[childIndex]:
                break
            #无须真正交换，单向赋值即可
            self.array[parentIndex] = self.array[childIndex]
            parentIndex = childIndex
            childIndex = 2 * childIndex +1
        self.array[parentIndex] =temp

if __name__ == "__main__":
    priorityQueue1 = PriorityQueue_max()
    priorityQueue1.enQueue(3)
    priorityQueue1.enQueue(5)
    priorityQueue1.enQueue(10)
    priorityQueue1.enQueue(2)
    priorityQueue1.enQueue(7)
    print("出队元素1：")
    print(priorityQueue1.deQueue())
    print("出队元素2：")
    print(priorityQueue1.deQueue())

    priorityQueue2 = PriorityQueue_min()
    priorityQueue2.enQueue(3)
    priorityQueue2.enQueue(5)
    priorityQueue2.enQueue(10)
    priorityQueue2.enQueue(2)
    priorityQueue2.enQueue(7)
    print("出队元素3：")
    print(priorityQueue2.deQueue())
    print("出队元素4：")
    print(priorityQueue2.deQueue())

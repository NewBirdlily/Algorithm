from array import MyArray

class MyStack:
    def __init__(self, capacity):
        self.myarray = MyArray(capacity)
        self.capacity = capacity
        self.size = 0
    
    # 判断堆栈是否为空
    def is_empty(self):
        return self.myarray.size == 0
    
    # 入栈
    def push(self, item):
        if self.myarray.size == self.capacity:
            return "Stack is full"
        else:
            self.myarray.insert(self.myarray.size, item)
    
    # 出栈
    def pop(self):
        if self.is_empty():
            return "Stack is empty"
        else:
            return self.myarray.remove(self.myarray.size - 1)
    
    # 获取栈顶元素
    def peek(self):
        if self.is_empty():
            return "Stack is empty"
        return self.myarray.arr[self.myarray.size - 1]
    
    # 输出堆栈中的元素
    def output(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            for i in range(self.myarray.size):
                print(self.myarray.arr[i], end=' ')

                
if __name__ == "__main__":
    mystack = MyStack(4)
    mystack.push(1)
    mystack.push(2)
    mystack.push(3)
    print("Stack elements:")
    mystack.output()
    print("Array length:", mystack.myarray.size)
    print("Array content:", mystack.myarray.arr)
    print(mystack.pop())
    print(mystack.peek())
    print(mystack.is_empty())

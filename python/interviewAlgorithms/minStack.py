class MinStack:
    def __init__(self):
        self.mainstack = []
        self.minstack = []

    # 入栈
    def push(self, element):
        self.mainstack.append(element)
        # 如果辅助栈为空，或者新元素小于或等于辅助栈栈顶，则将新元素压入辅助栈
        if not self.minstack or element <= self.minstack[-1]:
            self.minstack.append(element)

    # 出栈
    def pop(self):
        if not self.mainstack:
            print("stack is empty")
            return None
        # 如果出栈元素和辅助栈栈顶元素值相等，辅助栈出栈
        if self.mainstack[-1] == self.minstack[-1]:
            self.minstack.pop()
        return self.mainstack.pop()

    # 获取栈的最小元素
    def getMin(self):
        if not self.mainstack:
            print("stack is empty")
            return None
        return self.minstack[-1]


if __name__ == "__main__":
    stack1 = MinStack()
    stack1.push(4)
    stack1.push(9)
    stack1.push(7)
    stack1.push(3)
    stack1.push(8)
    stack1.push(5)
    print(stack1.getMin())
    stack1.pop()
    stack1.pop()
    stack1.pop()
    print(stack1.getMin())

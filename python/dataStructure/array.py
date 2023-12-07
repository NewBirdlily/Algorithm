class MyArray:
    def __init__(self, capacity):
        self.arr = [0] * capacity
        self.size = 0
        self.capacity = capacity
    
    def __getitem__(self,index):
        return self.arr[index]
    
    def __setitem__(self,index,value):
        self.arr[index] = value

    # 数组插入元素
    def insert(self, index, element):
        # 判断访问下标是否超出范围
        if index < 0 or index > self.size:
            print("超出数组实际元素范围！")
            return
        # 如果实际元素达到数组容量上限，则对数组进行扩容
        if self.size >= self.capacity:
            self.resize()
        # 从右往左循环，将元素逐个向右挪一位
        for i in range(self.size - 1, index - 1, -1):
            self.arr[i + 1] = self.arr[i]
        # 腾出的位置放入新元素
        self.arr[index] = element
        self.size += 1

    # 数组删除元素
    def remove(self, index):
        # 判断访问下标是否超出范围
        if index < 0 or index >= self.size:
            print("超出数组实际元素范围！")
            return None
        removed_element = self.arr[index]
        # 从左向右循环，将元素逐个向左挪1位
        for i in range(index, self.size - 1):
            self.arr[i] = self.arr[i + 1]
        self.size -= 1
        return removed_element

    # 数组扩容
    def resize(self):
        arr_new = [0] * (self.capacity * 2)
        # 从旧数组复制到新数组
        for i in range(self.size):
            arr_new[i] = self.arr[i]
        self.arr = arr_new
        self.capacity *= 2
        print(self.capacity)

    # 输出数组
    def output(self):
            for i in range(self.size):
                print(self.arr[i], end=' ')
            print()

if __name__ == "__main__":
    #myArray = MyArray(10)
    myArray = MyArray(4)
    myArray.insert(0, 3)
    myArray.insert(1, 7)
    myArray.insert(2, 9)
    myArray.insert(3, 5)
    myArray.insert(1, 6)
    myArray.output()
    myArray.remove(2)
    myArray.output()

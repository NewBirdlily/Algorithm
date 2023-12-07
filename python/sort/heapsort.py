class MyHeapSort:
    @staticmethod
    def downAdjust(array, parentIndex, length):
        # temp 保存父节点值，用于最后的赋值
        temp = array[parentIndex]
        childIndex = 2 * parentIndex + 1
        while childIndex < length:
            # 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子
            if childIndex + 1 < length and array[childIndex] < array[childIndex + 1]:
                childIndex += 1
            # 如果父节点大于任何一个孩子节点，则直接跳出
            if temp >= array[childIndex]:
                break
            # 无须真正交换，单向赋值即可
            array[parentIndex] = array[childIndex]
            parentIndex = childIndex
            childIndex = 2 * childIndex + 1
        array[parentIndex] = temp

    @staticmethod
    def heapsort(array):
        # 1.把无序数组构建成最大堆
        for i in range((len(array) - 2) // 2, -1, -1):
            MyHeapSort.downAdjust(array, i, len(array))
            print(array)
        # 2.循环删除栈顶元素，移到集合尾部,调整对产生新的堆顶
        for i in range(len(array) - 1, 0, -1):
            # 最后一个元素和第一个元素进行交换
            temp = array[i]
            array[i] = array[0]
            array[0] = temp
            # 下沉调整最大堆
            MyHeapSort.downAdjust(array, 0, i)

if __name__ == "__main__":
    array = [1, 3, 2, 6, 5, 7, 8, 9, 10, 0]
    MyHeapSort.heapsort(array)
    print(array)

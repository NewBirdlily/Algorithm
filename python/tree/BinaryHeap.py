class MyBinaryHeap:
    def __init__(self, array):
        self.array = array

    # 最小堆
    # 插入操作——上浮调整
    def upAdjust_min(self, array):
        childIndex = len(array) - 1
        parentIndex = (childIndex - 1) // 2
        # temp保存插入的叶子节点值，用于最后的赋值
        temp = array[childIndex]
        while childIndex > 0 and temp < array[parentIndex]:
            # 无需真正交换，单向赋值即可
            array[childIndex] = array[parentIndex]
            childIndex = parentIndex
            parentIndex = (parentIndex - 1) // 2

        array[childIndex] = temp

    # 删除操作——下沉调整
    def downAdjust_min(self, array, parentIndex, length):
        # temp保存父节点值，用于最后的赋值
        temp = array[parentIndex]
        childIndex = 2 * parentIndex + 1
        while childIndex < length:
            # 如果有右孩子，且右孩子小于左孩子的值，则定位到右孩子
            if childIndex + 1 < length and array[childIndex + 1] < array[childIndex]:
                childIndex += 1
            # 如果父节点小于任何一个孩子的值，则直接跳出
            if temp <= array[childIndex]:
                break
            # 无须真正交换，单向赋值即可
            array[parentIndex] = array[childIndex]
            parentIndex = childIndex
            childIndex = 2 * childIndex + 1
        array[parentIndex] = temp

    # 构建最小堆
    def buildHeap_min(self, array):
        # 从最后一个非叶子节点开始，依次做下沉调整
        for i in range((len(array) - 2) // 2, -1, -1):
            self.downAdjust_min(array, i, len(array))

    # 最大堆
    # 插入操作——上浮调整
    def upAdjust_max(self, array):
        childIndex = len(array) - 1
        parentIndex = (childIndex - 1) // 2
        temp = array[childIndex]
        while childIndex > 0 and temp > array[parentIndex]:
            array[childIndex] = array[parentIndex]
            childIndex = parentIndex
            parentIndex = (parentIndex - 1) // 2

        array[childIndex] = temp

    # 删除操作——下沉调整
    def downAdjust_max(self, array, parentIndex, length):
        temp = array[parentIndex]
        childIndex = 2 * parentIndex + 1
        while childIndex < length:
            if childIndex + 1 < length and array[childIndex + 1] > array[childIndex]:
                childIndex += 1
            if temp >= array[childIndex]:
                break
            array[parentIndex] = array[childIndex]
            parentIndex = childIndex
            childIndex = 2 * childIndex + 1

        array[parentIndex] = temp

    # 构建最大堆
    def buildHeap_max(self, array):
        # 从第一个非叶子节点开始，依次做下沉调整
        for i in range(len(array) // 2 - 1, -1, -1):
            self.downAdjust_max(array, i, len(array))

if __name__ == "__main__":
    mybinaryheap = MyBinaryHeap([])
    array = [1, 3, 2, 6, 5, 7, 8, 9, 10, 0]
    mybinaryheap.upAdjust_min(array)
    print("最小堆上浮调整：")
    print(array)

    array = [10, 8, 9, 6, 7, 4, 5, 2, 3, 11]
    mybinaryheap.upAdjust_max(array)
    print("最大堆上浮调整：")
    print(array)

    array = [7, 1, 3, 10, 5, 2, 8, 9, 6]
    mybinaryheap.buildHeap_min(array)
    print("构建最小堆：")
    print(array)

    array = [7, 1, 3, 10, 5, 2, 8, 9, 6]
    mybinaryheap.buildHeap_max(array)
    print("构建最大堆：")
    print(array)


from stack import MyStack
from HashTable import MyHashTable

class QuickSortStack:
    def __init__(self):
        self.Map = MyHashTable(8)
        rootParam =MyHashTable(2)
        rootParam.put("startIndex",0)
        rootParam.put("endIndex",0)
        self.Map.put(0,rootParam)

    def quicksort(self, array, startIndex, endIndex):
        #用一个集合栈来代替递归的函数栈
        quickSortStack = MyStack(self.Map.capacity)
        #整个数列的起止下标，以哈希的形式入栈
        rootParam = self.Map.get(0)
        rootParam.put("startIndex", int(startIndex))
        rootParam.put("endIndex", int(endIndex))
        quickSortStack.push(rootParam)
        #循环结束条件：栈为空时
        while not quickSortStack.is_empty():
            #栈顶元素出栈，得到起止下标
            param = quickSortStack.pop()
            #得到基准元素位置
            pivotIndex = self.partition(array, param.get("startIndex"), param.get("endIndex"))
            #根据基准元素分成两部分，把每一部分的起止下标入栈
            if param.get("startIndex") < pivotIndex - 1:
                leftParam = self.Map.get(0)
                leftParam.put("startIndex", int(param.get("startIndex")))
                leftParam.put("endIndex", int(pivotIndex - 1))
                quickSortStack.push(leftParam)
            
            if pivotIndex + 1 < param.get("endIndex"):
                rightParam = self.Map.get(0)
                rightParam.put("startIndex", int(pivotIndex + 1))
                rightParam.put("endIndex", int(param.get("endIndex")))
                quickSortStack.push(rightParam)
        
    #分治：单边循环法
    def partition(self, array, startIndex, endIndex):
        #取第一个位置（也可以选择随机位置）的元素作为基准元素
        pivot = array[startIndex]
        mark = startIndex

        for i in range(startIndex+1, endIndex+1):
            if array[i] < pivot:
                mark += 1
                tmp = array[mark]
                array[mark] = array[i]
                array[i] = tmp

        #将基准元素归位
        array[startIndex] = array[mark]
        array[mark] = pivot

        return mark

if __name__ == "__main__":
    quicksort = QuickSortStack()
    array = [4, 7, 6, 5, 3, 2, 8, 1]
    quicksort.quicksort(array, 0, len(array)-1)
    print(array)

class QuickSort:
    def quicksort(self,array,startIndex,endIndex):
        #递归结束条件：StartIndex大于或等于endIndex时
        if startIndex >endIndex:
            return array
        #得到基准元素位置
        pivotIndex = self.partition1(array,startIndex,endIndex)
        pivotIndex = self.partition2(array,startIndex,endIndex)
        #根据基准元素，分成两部分进行递归排序
        self.quicksort1(array,startIndex,pivotIndex-1)
        self.quicksort1(array,pivotIndex +1,endIndex)
        return array
        self.quicksort2(array,startIndex,pivotIndex-1)
        self.quicksort2(array,pivotIndex +1,endIndex)
        return array
        
    #分治（双边循环法）
    def partition2(self,array,startIndex,endIndex):
        pivot = array[startIndex]
        left = startIndex
        right = endIndex
        while left < right:
            #控制right指针比较并左移
            while left<right and array[right] >pivot:
                right -=1
            #控制left指针比较并右移
            while left<right and array[left]<pivot:
                left +=1
            #交换left和right指针所指向的元素
            if left <right:
                tmp = array[left]
                array[left] =array[right]
                array[right] = tmp
        #pivot和指针重合点交换
        array[startIndex] = array[left]
        array[left] = pivot
        return left
    
    #分治(单边循环法)
    def partition1(self,array,startIndex,endIndex):
        #取第一个位置（也可以选择随机位置）的元素作为基准元素
        pivot = array[startIndex]
        mark = startIndex
        for i in range(startIndex+1,endIndex+1)
        if array[i]<pivot:
            mark  +=1
            tmp = array[mark]
            array[mark] = array[i]
            array[i] = tmp

        array[startIndex] = array[mark]
        array[mark] = pivot
        return mark


if __name__ == "__main__":
    qsort =QuickSort()
    array = [4, 4, 6, 5, 3, 2, 8, 1]
    qsort.quicksort(array, 0, len(array) - 1)
    print(array)

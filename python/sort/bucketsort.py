class BucketSort:
    @staticmethod
    def bucketsort(array):
        #1.得到数列的最大值和最小值，并算出差值d
        max = array[0]
        min = array[0]
        for i in range(1,len(array)):
            if array[i] >max:
                max = array[i]
            if array[i] <min:
                min = array[i]
        d = max - min

        #2.初始化桶
        bucketNum = len(array)
        bucketList = [list() for _ in range(bucketNum)]
        for i in range(bucketNum):
            bucketList.append(list())
        
        #3.遍历原始数组，将每一个元素放入桶中
        for i in range(len(array)):
            num = int((array[i]-min) *(bucketNum-1) /d)
            bucketList[num].append(array[i])

        #4.对每个桶内部进行排序
        for i in range(bucketNum):
            bucketList[i] = sorted(bucketList[i])
        
        #5.输出全部元素
        sorted_array = [0] * len(array)
        index = 0 
        for lst in bucketList:
            for element in lst:
                sorted_array[index] = element
                index +=1
        return sorted_array

if __name__ =="__main__":
    array = [4.12,6.421,0.0023,3.0,2.123,8.122,4.12,10.09]
    sorted_array = BucketSort.bucketsort(array)
    print(sorted_array)

        
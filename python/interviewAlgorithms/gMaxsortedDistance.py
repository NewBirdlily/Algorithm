class Bucket:
    def __init__(self):
        self.min = None
        self.max = None

class GMaxSortedDistance:
    @staticmethod
    def getMaxSortedDistance(array):
        #1.得到数列的最大值和最小值
        max = array[0]
        min = array[0]
        for i in range(1,len(array)):
            if array[i]>max:
                max = array[i]
            if array[i]<min:
                min = array[i]
        d = max - min
        #如果max和min相等，说明数组所有元素都相等，返回0
        if d==0:
            return 0
        
        #2.初始化桶
        bucketNum = len(array)
        buckets = [Bucket() for _ in range(bucketNum)]
        
        #3.遍历原始数组，确定每个桶的最大最小值
        for i in range(len(array)):
            #确定数组元素所归属的桶下标
            index = int((array[i]-min)*(bucketNum-1) // d)
            if buckets[index].min is None or buckets[index].min > array[i]:
                buckets[index].min = array[i]
            if buckets[index].max is None or buckets[index].max < array[i]:
                buckets[index].max = array[i]

        #4.遍历桶，找到最大差值
        leftMax = buckets[0].max
        maxDistance = 0
        for i in range(1, len(buckets)):
            if buckets[i].min is None:
                continue
            if buckets[i].min - leftMax > maxDistance:
                maxDistance = buckets[i].min - leftMax
            leftMax = buckets[i].max

        return maxDistance

if __name__ == "__main__":
    array = [2, 6, 3, 4, 5, 10, 9]
    print(GMaxSortedDistance.getMaxSortedDistance(array))

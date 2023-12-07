class Sort:
    def bublesort(self, array):
        #记录最后一次交换的位置
        last_exchange_Index = 0
        #无序数列的边界，每次比较只需要比到这里为止
        sort_border = len(array) - 1
        for i in range(len(array) - 1):
            # 有序标记，每一轮的初始值都是 True
            is_sorted = True
            for j in range(sort_border):
                tmp = 0 
                if array[j] > array[j + 1]:
                    tmp = array[j]
                    array[j] = array[j + 1]
                    array[j + 1] = tmp
                    # 因为有元素进行交换，所以不是有序的，标记变为 False
                    is_sorted = False
                    #更新为最后一次交换元素的位置
                    last_exchange_Index = j
            sort_border = last_exchange_Index
            if is_sorted:
                break

    def cocktailsort(self,array):
        # tmp = 0
        # for i in range(len(array)//2):
        #     #有序标记，每一轮的初始值为True
        #     is_sorted = True
        #     #奇数轮，从左到右比较和交换
        #     for j in range(len(array) -i -1):
        #         if array[j] >array[j+1]:
        #             tmp = array[j]
        #             array[j]=array[j+1]
        #             array[j+1] =tmp
        #             #有元素交换，所以不是有序的，标记变为false
        #             is_sorted = False
        #     if is_sorted:
        #         break

        # #在偶数轮之前，将is_sorted重新标记为True
        #     is_sorted =True
        #     #偶数轮，从右往左比较和交换
        #     for j in range(len(array) -i -1,0,-1):
        #         if array[j]<array[j-1]:
        #             tmp = array[j]
        #             array[j] = array[j-1]
        #             array[j-1] = tmp
        #             #因为有元素交换，所以不是有序的，标记变为false
        #             is_sorted = False
        #     if is_sorted:
        #         break
        n = len(array)
        left = 0
        right = n - 1
        while left < right:
            # 前半轮，将最大元素放到后面
            is_sorted = True
            for i in range(left, right):
                if array[i] > array[i + 1]:
                    tmp = array[i]
                    array[i]=array[i+1]
                    array[i+1]=tmp
                    is_sorted = False
            right -= 1
            if is_sorted:
                break

            # 后半轮，将最小元素放到前面
            is_sorted = True
            for i in range(right, left, -1):
                if array[i - 1] > array[i]:
                    tmp = array[i]
                    array[i] = array[i-1]
                    array[i-1]=tmp
                    is_sorted = False
            left += 1
            if is_sorted:
                break

        return array

if __name__ == "__main__":
    bsort = Sort()
    csort = Sort()

    array = [5, 8, 6, 3, 9, 2, 1, 7]
    bsort.bublesort(array)
    print(array)

    array = [2, 3, 4, 5, 6, 7, 1,8]
    csort.cocktailsort(array)
    print(array)
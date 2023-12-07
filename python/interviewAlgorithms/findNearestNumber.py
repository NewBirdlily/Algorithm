class FindNearestNumber:
    @staticmethod
    def findNearestNumber(numbers):
        # 1. 从后向前查看逆序区域，找到逆序区域的前一位，也就是数字置换的边界
        index = FindNearestNumber.findTransferPoint(numbers)
        # 如果数字置换边界是0，说明整个数组已经逆序，无法得到更大的相同数字组成的整数，返回None
        if index == 0:
            return None
        
        # 2. 如果把逆序区域的前一位和逆序区域中刚刚大于它的数字交换位置，复制并入参，避免直接修改入参
        numbers_copy = numbers.copy()
        numbers_copy = FindNearestNumber.exchangeHead(numbers_copy, index)
        # 3. 将逆序区域翻转，使其变为顺序
        numbers_copy = FindNearestNumber.reverse(numbers_copy, index)
        return numbers_copy

    @staticmethod
    def findTransferPoint(numbers):
        for i in range(len(numbers)-1, 0, -1):
            if numbers[i] > numbers[i-1]:
                return i
        
        return 0 
    
    @staticmethod
    def exchangeHead(numbers, index):
        head = numbers[index-1]
        for i in range(len(numbers)-1, 0, -1):
            if head < numbers[i]:
                numbers[index-1], numbers[i] = numbers[i], head
                break
        return numbers
    
    @staticmethod
    def reverse(numbers, index):
        i, j = index, len(numbers)-1
        while i < j:
            temp = numbers[i]
            numbers[i] = numbers[j]
            numbers[j] = temp
            i += 1
            j -= 1
        return numbers

    @staticmethod
    def outputNumbers(numbers):
        for i in numbers:
            print(i)

if __name__ == "__main__":
    numbers = [1,2,3,4,5]
    # 打印12345之后的10个全排列整数
    for i in range(10):
        numbers = FindNearestNumber.findNearestNumber(numbers)
        if numbers is None:
            break
        FindNearestNumber.outputNumbers(numbers)
        print()  

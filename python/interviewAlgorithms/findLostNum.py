class FindLostNum:
    @staticmethod
    def findLostNum(array):
        # 用于存储两个出现奇数次的整数
        result = [0, 0]
        # 第1次进行异或运算
        xorResult = 0
        for i in range(len(array)):
            xorResult ^= array[i]
        # 如果进行异或运算的结果为0，则说明输入的数组不符合题目要求（两个奇数相同）
        if xorResult == 0:
            return None
        # 确定两个整数的不同位，以此来做分组
        separator = 1
        while 0 == xorResult & separator:
            separator = separator << 1
        # 第2次分组进行异或运算
        for i in range(len(array)):
            if 0 == (array[i] & separator):
                result[0] ^= array[i]
            else:
                result[1] ^= array[i]
        return result

if __name__ == "__main__":
    array = [4, 1, 2, 2, 5, 1, 4, 3]
    result = FindLostNum.findLostNum(array)
    print(str(result[0]) + "," + str(result[1]))

class BigNumberSum:
    @staticmethod
    def bigNumberSum(bigNumberA, bigNumberB):
        # 1. 把两个大整数用数组逆序存储，数组长度等于较大整数位数+1
        maxLength = max(len(bigNumberA), len(bigNumberB))
        
        arrayA = [0] * (maxLength + 1)
        for i in range(len(bigNumberA)):
            arrayA[i] = int(bigNumberA[len(bigNumberA) - i - 1])
        
        arrayB = [0] * (maxLength + 1)
        for i in range(len(bigNumberB)):
            arrayB[i] = int(bigNumberB[len(bigNumberB) - 1 - i])
        
        # 2. 构建result数组，数组长度等于较大整数位数+1
        result = [0] * (maxLength + 1)

        # 3. 遍历数组，按位相加
        for i in range(len(result)):
            temp = result[i]
            temp += arrayA[i]
            temp += arrayB[i]
            # 判断是否进位
            if temp >= 10:
                temp -= 10
                result[i + 1] = 1
            result[i] = temp

        # 4. 把result数组再次逆序并转成string
        sb = ""
        # 是否找到大整数的最高有效位
        findFirst = False
        for i in range(len(result) - 1, -1, -1):
            if not findFirst:
                if result[i] == 0:
                    continue
                findFirst = True
            sb += str(result[i])

        return sb


if __name__ == "__main__":
    print(BigNumberSum.bigNumberSum("426709752318", "95481253129"))

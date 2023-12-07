# class RemoveKDigits:
#     @staticmethod
#     def removeKDigits(num,k):
#         for i in range(k):
#             hasCut =False
#             #从左向右遍历，找到比自己右侧数字大的数字并删除
#             for j in range(len(num)-1):
#                 if num[j]>num[j+1]:
#                     num = num[0:j]+num[j+1:len(num)]
#                     hasCut = True
#                     break
#             #如果没有找到要删除的数字，则删除最后一个数字
#             if not hasCut:
#                 num = num[0:len(num)-1]
#         #清除整数左侧的数字0
#         start = 0
#         for j in range(len(num)-1):
#             if num[j] != '0':
#                 break
#             start +=1
        
#         num = num[start:len(num)]
#         #如果整数的所有数字都被删除了，直接返回0
#         if len(num) ==0:
#             return '0'
#         return num

#优化版
class RemoveKDigits:
    @staticmethod
    def removeKDigits(num, k):
        # 新整数的最终长度 = 原整数的长度 - k
        new_length = len(num) - k
        # 创建一个栈，用于接收所有数字
        stack = ['0'] * len(num)
        top = 0
        for i in range(len(num)):
            # 遍历当前数字
            c = num[i]
            # 当栈顶数字大于遍历到的当前数字时，栈顶数字出栈（相当于删除数字）
            while top > 0 and stack[top-1] > c and k > 0:
                top -= 1
                k -= 1
            # 遍历到的当前数字入栈
            stack[top] = c
            top += 1
        # 找到栈中第一个非零的位置，以此构成新的整数字符串
        offset = 0
        while offset < new_length and stack[offset] == '0':
            offset += 1
        return '0' if offset == new_length else ''.join(stack[offset:new_length])


if __name__ == "__main__":
    print(RemoveKDigits.removeKDigits("1593212",3))
    print(RemoveKDigits.removeKDigits("30200",1))
    print(RemoveKDigits.removeKDigits("10",2))
    print(RemoveKDigits.removeKDigits("541270936",3))
    print(RemoveKDigits.removeKDigits("100",1))
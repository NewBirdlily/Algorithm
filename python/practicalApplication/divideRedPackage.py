import random
from decimal import Decimal

class DivideRedPackage:
    @staticmethod
    def divideRedPackage1(totalAmount, totalPeopleNum):
        amount_List = []
        restAmount = totalAmount
        restPeopleNum = totalPeopleNum
        random_num = random.Random()
        
        for i in range(totalPeopleNum-1):
            # 随机范围：[1, 剩余人均金额的2倍-1]分
            amount = random_num.randint(1, restAmount // restPeopleNum * 2 - 1)
            restAmount -= amount
            restPeopleNum -= 1
            amount_List.append(amount)
        
        amount_List.append(restAmount)
        return amount_List
    
    @staticmethod
    def divideRedPackage2(n, m):
        cuts = set()
        while len(cuts) < n-1:
            cut = random.randint(1, m-1)
            cuts.add(cut)
        cuts = sorted(list(cuts))  # 对切割点进行排序

        amounts = [0] * n
        prev_cut = 0
        for i in range(n-1):
            cut = cuts[i]
            amounts[i] = cut - prev_cut
            prev_cut = cut
        amounts[n-1] = m - prev_cut

        return amounts


if __name__ == "__main__":
    amount_List = DivideRedPackage.divideRedPackage1(1000, 10)
    for amount in amount_List:
        print("抢到金额：" + str(Decimal(amount) / Decimal(100)))
    print()

    n = 10  # 红包个数
    m = 1000  # 总金额
    amounts = DivideRedPackage.divideRedPackage2(n, m)
    
    for amount in amounts:
        print("抢到金额：", amount/100)
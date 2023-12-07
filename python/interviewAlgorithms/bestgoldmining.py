import numpy as np
class BestGoldMining:
    #递归方式
    @staticmethod
    def getBestGoldMining(w,n,p,g):
        if w==0 or n==0:
            return 0
        if w<p[n-1]:
            return BestGoldMining.getBestGoldMining(w,n-1,p,g)
        
        return max(BestGoldMining.getBestGoldMining(w,n-1,p,g),BestGoldMining.getBestGoldMining(w-p[n-1],n-1,p,g)+g[n-1])


    #二维数组方式
    @staticmethod
    def getBestGoldMiningV2(w, p, g):
        #创建表格
        resultTable = np.zeros((len(g) + 1, w + 1), dtype=int)
        #填充表格
        for i in range(1, len(g) + 1):
            for j in range(w + 1):
                if j < p[i - 1]:
                    resultTable[i][j] = resultTable[i - 1][j]
                else:
                    resultTable[i][j] = max(resultTable[i - 1][j], resultTable[i - 1][j - p[i - 1]] + g[i - 1])
        #返回最后一个格子的值
        return resultTable[len(g)][w]


if __name__ == "__main__":
    w=10
    p=[5, 5, 3, 4,3]
    g=[400,500,200,300,350]
    print("最优收益：" +str(BestGoldMining.getBestGoldMining(w,len(g),p,g)))
    print("最优收益：" +str(BestGoldMining.getBestGoldMiningV2(w,p,g)))
    
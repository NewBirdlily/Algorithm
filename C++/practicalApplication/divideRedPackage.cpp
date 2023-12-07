#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <random>
#include <cmath>
using namespace std;

class DivideRP {
    public:
    // 二倍均值法
        static list<int> divideRP1(int totalAmount, int totalPeopleNum) {
        list<int> amountList;
        int restAmount = totalAmount;
        int restPeopleNum = totalPeopleNum;
        random_device random;
        mt19937 rng(random());

            for (int i = 0; i < totalPeopleNum - 1; i++) {
                // 随机范围：[1, 剩余人均金额的2倍-1]分
                int amout = getRandomNum(1, restAmount / restPeopleNum * 2 - 1, rng);
                restAmount -= amout;
                restPeopleNum--;
                amountList.push_back(amout);
            }
            
            amountList.push_back(restAmount);
            return amountList;
        }

        // 线段切割法
        static vector<int> divideRP2(int n, int m) {
            set<int> cuts;
            random_device random;
            mt19937 rng(random());

            while (cuts.size() < n - 1) {
                int cut = getRandomNum(1, m - 1, rng);
                cuts.insert(cut);
            }

            vector<int> sortedCuts(cuts.begin(), cuts.end());
            vector<int> amounts(n, 0);
            int prevCut = 0;

            for (int i = 0; i < n - 1; i++) {
                int cut = sortedCuts[i];
                amounts[i] = cut - prevCut;
                prevCut = cut;
            }

            amounts[n - 1] = m - prevCut;

            return amounts;
    }
    private:
        static int getRandomNum(int low, int high, mt19937& rng) {
        uniform_int_distribution<int> dist(low, high);
        return dist(rng);
    }
};

int main() {
    list<int> amountList = DivideRP::divideRP1(1000, 10);
    for (int amount : amountList) {
        cout << "抢到的金额：" << static_cast<double>(amount) / 100 << endl;
    }
    cout<<endl;
    
    vector<int> amounts = DivideRP::divideRP2(10, 1000);
    for (int amount : amounts) {
        cout << "抢到的金额：" << static_cast<double>(amount) / 100 << endl;
    }
    return 0;
}
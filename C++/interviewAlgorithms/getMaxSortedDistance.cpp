#include <iostream>
#include <vector>
#include<climits>
using namespace std;

class Bucket {
public:
    int min = INT_MAX;
    int max = INT_MIN;
};

class GetMaxSortedDistance {
public:
    static int getMaxSortedDistance(int *array, int length) {
        // 得到数列的最大值和最小值
        int max = array[0];
        int min = array[0];
        for (int i = 1; i < length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
            if (array[i] < min) {
                min = array[i];
            }
        }
        int d = max - min;
        // 如果max 和min相等，说明数组所以元素相等，返回0
        if (d == 0) {
            return 0;
        }

        int bucketNum = length;
        vector<Bucket> buckets(bucketNum);

        for (int i = 0; i < length; i++) {
            // 确定数组元素所归属的桶下标
            int index = ((array[i] - min) * (bucketNum - 1) / d);
            if (buckets[index].min > array[i]) {
                buckets[index].min = array[i];
            }
            if (buckets[index].max < array[i]) {
                buckets[index].max = array[i];
            }
        }

        int leftMax = buckets[0].max;
        int maxDistance = 0;
        for (int i = 1; i < buckets.size(); i++) {
            if (buckets[i].min == INT_MAX) {
                continue;
            }
            if (buckets[i].min - leftMax > maxDistance) {
                maxDistance = buckets[i].min - leftMax;
            }
            leftMax = buckets[i].max;
        }
        return maxDistance;
    }
};

int main() {
    int array[] = {2, 6, 3, 4, 5, 10, 9};
    cout << GetMaxSortedDistance::getMaxSortedDistance(array, sizeof(array) / sizeof(int)) << endl;
    return 0;
}

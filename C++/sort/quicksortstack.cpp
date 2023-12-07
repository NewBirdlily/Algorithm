#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class QuickSortStack {
public:
    static void quicksortstack(int *array, int startIndex, int endIndex) {
        // 用一个集合栈来代替递归的函数栈
        stack<unordered_map<string, int>> quicksortstack;
        // 整个数列的起止下标，以哈希的形式入栈
        unordered_map<string, int> rootParam;
        rootParam["startIndex"] = startIndex;
        rootParam["endIndex"] = endIndex;
        quicksortstack.push(rootParam);
        // 循环结束：栈为空时
        while (!quicksortstack.empty()) {
            // 栈顶元素出栈，得到起止下标
            unordered_map<string, int> param = quicksortstack.top();
            quicksortstack.pop();
            // 得到基准元素位置
            int pivotIndex = partition(array, param["startIndex"], param["endIndex"]);
            // 根据基准元素分成两部分，把每一部分的起止下标入栈
            if (param["startIndex"] < pivotIndex - 1) {
                unordered_map<string, int> leftParam;
                leftParam["startIndex"] = param["startIndex"];
                leftParam["endIndex"] = pivotIndex - 1;
                quicksortstack.push(leftParam);
            }
            if (pivotIndex + 1 < param["endIndex"]) {
                unordered_map<string, int> rightParam;
                rightParam["startIndex"] = pivotIndex + 1;
                rightParam["endIndex"] = param["endIndex"];
                quicksortstack.push(rightParam);
            }
        }
    }

private:
    static int partition(int *array, int startIndex, int endIndex) {
        // 取第一个位置的元素作为基准元素
        int pivot = array[startIndex];
        int mark = startIndex;

        for (int i = startIndex + 1; i <= endIndex; i++) {
            if (array[i] < pivot) {
                mark++;
                int p = array[mark];
                array[mark] = array[i];
                array[i] = p;
            }
        }
        array[startIndex] = array[mark];
        array[mark] = pivot;
        return mark;
    }
};

int main() {
    int array[] = { 4, 7, 6, 5, 3, 2, 8, 1 };
    int length = sizeof(array) / sizeof(array[0]);
    QuickSortStack::quicksortstack(array, 0, length - 1);
    cout << "快速非递归排序：" << endl;
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

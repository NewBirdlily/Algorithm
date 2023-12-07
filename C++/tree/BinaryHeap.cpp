#include<iostream>
using namespace std;

//最小二叉堆自我调整
class BinaryHeap_min {
public:
    //上浮操作
    static void upAdjust(int *array, int childIndex) {
        int parentIndex = (childIndex - 1) / 2;
        //temp保存插入叶子节点值，用于最后的赋值
        int temp = array[childIndex];
        while (childIndex > 0 && temp < array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    //下沉操作
    static void downAdjust(int *array, int parentIndex, int length) {
        //temp保存父节点值，用于最后的赋值
        int temp = array[parentIndex];
        int childIndex = 2 * parentIndex + 1;
        while (childIndex < length) {
            //如果有右孩子，且右孩子的值小于左孩子的值，则定位到右孩子
            if (childIndex + 1 < length && array[childIndex + 1] < array[childIndex]) {
                childIndex++;
            }
            //如果父节点小于任何一个孩子节点的值，则直接跳出
            if (temp < array[childIndex])
                break;
            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }

    //构建二叉堆
    static void buildHeap(int *array, int length) {
        //从最后一个非叶子节点开始，依次作下沉调整
        for (int i = (length - 2) / 2; i >= 0; i--) {
            downAdjust(array, i, length);
        }
    }
};

//最大二叉堆自我调整
class BinaryHeap_max {
public:
    static void upAdjust(int *array, int childIndex) {
        int parentIndex = (childIndex - 1) / 2;
        int temp = array[childIndex];
        while (childIndex > 0 && temp > array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    static void downAdjust(int *array, int parentIndex, int length) {
        int temp = array[parentIndex];
        int childIndex = 2 * parentIndex + 1;
        while (childIndex < length) {
            if (childIndex + 1 < length && array[childIndex + 1] > array[childIndex]) {
                childIndex++;
            }
            if (temp > array[childIndex])
                break;
            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }

    static void buildHeap(int *array, int length) {
        for (int i = (length - 2) / 2; i >= 0; i--) {
            downAdjust(array, i, length);
        }
    }
};

int main() {
    int array1[] = {1, 3, 2, 6, 7, 8, 9, 10, 0};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    BinaryHeap_min::upAdjust(array1, length1 - 1);
    cout << "最小堆上浮调整: "<<endl;
    for (int i = 0; i < length1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    int array2[] = {7, 1, 3, 10, 5, 2, 8, 9, 6};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    BinaryHeap_min::buildHeap(array2, length2);
    cout << "最小二叉堆的构建: "<<endl;
    for (int i = 0; i < length2; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;

    int array3[] = {10, 8, 9, 6, 7, 4, 5, 2, 3, 11};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    BinaryHeap_max::upAdjust(array3, length3 - 1);
    cout << "最大堆上浮调整: "<<endl;
    for (int i = 0; i < length3; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

    int array4[] = {7, 1, 3, 10, 5, 2, 8, 9, 6};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    BinaryHeap_max::buildHeap(array4, length4);
    cout << "最大二叉堆的构建: "<<endl;
    for (int i = 0; i < length4; i++) {
        cout << array4[i] << " ";
    }
    cout << endl;

    return 0;
}

#include<iostream>
using namespace std;

class BubbleSort {
public:
    static void sort1(int *array, int length) {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }

    static void sort2(int *array, int length) {
        for (int i = 0; i < length - 1; i++) {
            bool isSorted = true;
            for (int j = 0; j < length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                    isSorted = false;
                }
            }
            if (isSorted) {
                break;
            }
        }
    }

    static void sort3(int *array, int length) {
        int lastExchangeIndex = 0;
        int sortBorder = length - 1;
        for (int i = 0; i < length - 1; i++) {
            bool isSorted = true;
            for (int j = 0; j < sortBorder; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                    isSorted = false;
                    lastExchangeIndex = j;
                }
            }
            sortBorder = lastExchangeIndex;
            if (isSorted) {
                break;
            }
        }
    }
};

class CocktailSort {
public:
    static void sort1(int *array, int length) {
        for (int i = 0; i < length / 2; i++) {
            bool isSorted = true;
            for (int j = i; j < length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                    isSorted = false;
                }
            }
            if (isSorted) {
                break;
            }
            isSorted = true;
            for (int j = length - i - 1; j > i; j--) {
                if (array[j] < array[j - 1]) {
                    swap(array[j], array[j - 1]);
                    isSorted = false;
                }
            }
            if (isSorted) {
                break;
            }
        }
    }
    
    static void sort2(int *array, int length) {
        int left = 0;
        int right = length - 1;
        while (left < right) {
            // 前半轮，将最大元素放到后面
            bool is_sorted = true;
            for (int i = left; i < right; i++) {
                if (array[i] > array[i + 1]) {
                    swap(array[i], array[i + 1]);
                    is_sorted = false;
                }
            }
            right--;
            if (is_sorted) {
                break;
            }

            // 后半轮，将最小元素放到前面
            is_sorted = true;
            for (int i = right; i > left; i--) {
                if (array[i - 1] > array[i]) {
                    swap(array[i - 1], array[i]);
                    is_sorted = false;
                }
            }
            left++;
            if (is_sorted) {
                break;
            }
        }
    }
};

int main() {
    int array1[] = { 5, 8, 6, 3, 9, 2, 1, 7 };
    int length1 = sizeof(array1) / sizeof(array1[0]);
    BubbleSort::sort1(array1, length1);
    cout << "Sorted array1: ";
    for (int i = 0; i < length1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    int array2[] = { 6, 4, 8, 2, 1, 3, 7, 5 };
    int length2 = sizeof(array2) / sizeof(array2[0]);
    BubbleSort::sort2(array2, length2);
    cout << "Sorted array2: ";
    for (int i = 0; i < length2; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;

    int array3[] = { 3, 4, 2, 1, 5, 6, 7, 8 };
    int length3 = sizeof(array3) / sizeof(array3[0]);
    BubbleSort::sort3(array3, length3);
    cout << "Sorted array3: ";
    for (int i = 0; i < length3; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

    int array4[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    CocktailSort::sort1(array4, length4);
    cout << "Sorted array4: ";
    for (int i = 0; i < length4; i++) {
        cout << array4[i] << " ";
    }
    cout << endl;

    int array5[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int length5 = sizeof(array5) / sizeof(array5[0]);
    CocktailSort::sort2(array5, length5);
    cout << "Sorted array5: ";
    for (int i = 0; i < length5; i++) {
        cout << array5[i] << " ";
    }
    cout << endl;

    return 0;
}

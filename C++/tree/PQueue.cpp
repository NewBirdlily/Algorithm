#include<iostream>
using namespace std;

class PriorityQueue_max {
public:
    PriorityQueue_max() {
        array = new int[5];
        size = 0;
        length = 5;
    }

    ~PriorityQueue_max() {
        delete[] array;
    }

    void enQueue(int key) {
        if (size >= length) {
            resize();
        }
        array[size++] = key;
        upAdjust();
    }

    int deQueue() {
        if (size <= 0) {
            cout << "The queue is empty!" << endl;
            return -1;
        }
        int head = array[0];
        array[0] = array[--size];
        downAdjust();
        return head;
    }

private:
    int *array;
    int size;
    int length;

    void upAdjust() {
        int childIndex = size - 1;
        int parentIndex = (childIndex - 1) / 2;
        int temp = array[childIndex];
        while (childIndex > 0 && temp > array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    void downAdjust() {
        int parentIndex = 0;
        int childIndex = 1;
        int temp = array[parentIndex];
        while (childIndex < size) {
            if (childIndex + 1 < size && array[childIndex + 1] > array[childIndex]) {
                childIndex++;
            }
            if (temp > array[childIndex]) {
                break;
            }
            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }

    void resize() {
        int newSize = length * 2;
        int *newArray = new int[newSize];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        length = newSize;
    }
};

class PriorityQueue_min {
public:
    PriorityQueue_min() {
        array = new int[5];
        size = 0;
        length = 5;
    }

    ~PriorityQueue_min() {
        delete[] array;
    }

    void enQueue(int key) {
        if (size >= length) {
            resize();
        }
        array[size++] = key;
        upAdjust();
    }

    int deQueue() {
        if (size <= 0) {
            cout << "The queue is empty!" << endl;
            return -1;
        }
        int head = array[0];
        array[0] = array[--size];
        downAdjust();
        return head;
    }

private:
    int *array;
    int size;
    int length;

    void upAdjust() {
        int childIndex = size - 1;
        int parentIndex = (childIndex - 1) / 2;
        int temp = array[childIndex];
        while (childIndex > 0 && temp < array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    void downAdjust() {
        int parentIndex = 0;
        int childIndex = 1;
        int temp = array[parentIndex];
        while (childIndex < size) {
            if (childIndex + 1 < size && array[childIndex + 1] < array[childIndex]) {
                childIndex++;
            }
            if (temp < array[childIndex]) {
                break;
            }
            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }

    void resize() {
        int newSize = length * 2;
        int *newArray = new int[newSize];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        length = newSize;
    }
};

int main() {
    PriorityQueue_max pqueue_max;
    pqueue_max.enQueue(3);
    pqueue_max.enQueue(5);
    pqueue_max.enQueue(10);
    pqueue_max.enQueue(2);
    pqueue_max.enQueue(7);
    cout << "最大优先队列的出队元素：" << pqueue_max.deQueue() << endl;
    cout << "最大优先队列的出队元素：" << pqueue_max.deQueue() << endl;

    PriorityQueue_min pqueue_min;
    pqueue_min.enQueue(3);
    pqueue_min.enQueue(5);
    pqueue_min.enQueue(10);
    pqueue_min.enQueue(2);
    pqueue_min.enQueue(7);
    cout << "最小优先队列的出队元素：" << pqueue_min.deQueue() << endl;
    cout << "最小优先队列的出队元素：" << pqueue_min.deQueue() << endl;

    return 0;
}

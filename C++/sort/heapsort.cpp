#include<iostream>
using namespace std;

class HeapSort{
    public:
        static void downAdjust(int *array,int parentIndex,int length){
            //temp保存父节点值，用于最后的赋值
            int temp =array[parentIndex];
            int childIndex = 2 *parentIndex +1;
            while(childIndex<length){
                if(childIndex +1<length && array[childIndex]<array[childIndex +1]){
                    childIndex++;
                }
                if(temp>array[childIndex])
                    break;
                array[parentIndex] =array[childIndex];
                parentIndex = childIndex;
                childIndex = 2*childIndex +1;
            }
            array[parentIndex] =temp;
        }

        static void heapSort(int *array, int length){
            //1.把无序数组构建成最大堆
            for(int i =(length-2)/2;i>=0;i--){
                downAdjust(array,i,length);
            }
            cout<<"最大堆："<<endl;
            for(int i=0;i<length;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
            //2.循环删除栈顶元素，移到集合尾部，调整对产生新的堆顶
            for(int i =length-1;i>0;i--){
                //最后一个元素和第一个元素进行交换
                int temp = array[i];
                array[i]=array[0];
                array[0]=temp;
                //下沉调整最大堆
                downAdjust(array,0,i);
            }
        }
};

int main(){
    int array[]={1,3,2,6,5,7,8,9,10,0};
    int length = sizeof(array)/sizeof(array[0]);
    HeapSort::heapSort(array, length);
    cout<<"堆排序输出最小堆 ："<<endl;
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

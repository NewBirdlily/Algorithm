#include<iostream>
using namespace std;

class QuickSort1{
    public:
        static void quickSort(int *array,int startIndex,int endIndex){
            //递归结束条件：startIndex大于或等于endIndex
            if(startIndex >= endIndex){
                return;
            }
            //得到基准元素位置
            int pivotIndex = partition(array,startIndex,endIndex);
            //根据基准元素，分成两部分进行递归排序
            quickSort(array,startIndex,pivotIndex -1);
            quickSort(array,pivotIndex+1,endIndex);
        }
    private:
        static int partition(int *array,int startIndex,int endIndex){
            //取第一个位置（也可以选择随机位置）的元素作为基准元素
            int pivot = array[startIndex];
            int left = startIndex;
            int right = endIndex;
            while(left !=right){
                //控制right指针比较并左移
                while(left <right && array[right] >=pivot){
                    right--;
                }
                //控制left指针比较并右移
                while(left<right && array[left] <=pivot){
                    left++;
                }
                //交换left 和right指针所指向的元素
                if(left <right){
                    int p = array[left];
                    array[left] =array[right];
                    array[right] = p;
                }
            }
            //pivot和指针重合点交换
            array[startIndex] =array[left];
            array[left] = pivot;

            return left;
        }
};
class QuickSort2{
    public:
        static void quickSort(int *array,int startIndex,int endIndex){
            //递归结束条件：：startIndex大于或等于endIndex时
            if(startIndex >= endIndex){
                return;
            }
            //得到基准元素位置
            int pivotIndex = partition(array,startIndex,endIndex);
            //根据基准元素，分成两部分进行递归排序
            quickSort(array,startIndex,pivotIndex-1);
            quickSort(array,pivotIndex+1,endIndex);
        }

    private:
        static int partition(int *array,int startIndex,int endIndex){
            //取第一个位置（也可以选择随机位置）的元素作为基准元素
            int pivot = array[startIndex];
            int mark =startIndex;

            for(int i = startIndex +1;i<=endIndex;i++){
                if(array[i]<pivot){
                    mark++;
                    int p =array[mark];
                    array[mark] = array[i];
                    array[i]=p;
                }
            }
            array[startIndex] = array[mark];
            array[mark]= pivot;
            return mark;
        }
};   
int main(){
    //int array1[] = {4,7,6,5,3,2,8,1};
    int array1[] = {5,6,8,7};
    int length1 =sizeof(array1)/sizeof(array1[0]);
    QuickSort1::quickSort(array1,0,length1-1);
    cout<<"Sorted array1 :"<<endl;
    for(int i =0;i<length1;i++){
        cout<<array1[i]<<" "<<endl;
    }

    int array2[] = {4,7,6,5,3,2,8,1};
    int length2 =sizeof(array2)/sizeof(array2[0]);
    QuickSort1::quickSort(array2,0,length2-1);
    cout<<"Sorted array2 :"<<endl;
    for(int i =0;i<length2;i++){
        cout<<array2[i]<<" "<<endl;
    }

    return 0;

}

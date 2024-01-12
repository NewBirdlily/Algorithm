#include<iostream>
#include<vector>
using namespace std;

class SelectionSort{
public:
    static void selectionSort(int *array,int length){
        for(int i =0;i<length -1;i++){
            int minIndex =i;
            for(int j =i+1; j<length;j++){
                if(array[j] <array[minIndex]){
                    minIndex = j;
                }
            }
            if(i !=minIndex){
                swap(array[i],array[minIndex]);
            }
        }
    }
};

int main(){
    int array[] = {3,4,2,1,5,6,7,8,30,50,1,33,24,5,-4,7,0};
    int length = sizeof(array)/sizeof(array[0]);
    SelectionSort::selectionSort(array,length);
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
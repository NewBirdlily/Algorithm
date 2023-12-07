#include<iostream>
#include<vector>
using namespace std;

class CountSort{
    public:
        static vector<int> countSort1(int *array, int length){
            int max = array[0];
            for(int i = 1; i<length;i++){
                if(array[i]>max){
                    max = array[i];
                }
            }
            vector<int> countArray(max+1, 0);
            for(int i = 0;i <length;i++){
                countArray[array[i]]++;
            }
            int index =0;
            vector<int> sortedArray(length);
            for(int i =0;i<countArray.size();i++){
                for(int j =0;j<countArray[i];j++){
                    sortedArray[index++] = i;
                }
            }
            return sortedArray;
        }

        static vector<int> countSort2(int *array,int length){
            int max = array[0];
            int min = array[0];
            for(int i =0; i <length;i++){
                if(array[i]>max){
                    max =array[i];
                }
                if(array[i]<min){
                    min = array[i];
                }
            }
            int d =max -min;
            vector<int> countArray(d+1,0);
            for(int i = 0;i<length;i++){
                countArray[array[i]-min]++;
            }

            for(int i = 1;i<countArray.size();i++){
                countArray[i] +=countArray[i-1];
            }
            vector<int> sortedArray(length);
            for(int i = length-1;i>=0;i--){
                sortedArray[countArray[array[i]-min]-1] = array[i];
                countArray[array[i]-min]--;
            }
            return sortedArray;
        }
};

int main(){
    int array1[] = {4,4,6,5,3,2,8,1,7,5,6,0,10};
    int length1 = sizeof(array1)/sizeof(array1[0]);
    vector<int> sortedArray1 = CountSort::countSort1(array1, length1);
    for(int i=0;i<sortedArray1.size();i++){
        cout<<sortedArray1[i]<<" ";
    }
    cout<<endl;

    int array2[] = {95,94,91,98,99,90,99,93,91,92};
    int length2 = sizeof(array2)/sizeof(array2[0]);
    vector<int>sortedArray2 = CountSort::countSort2(array2,length2);
    for(int i = 0;i<sortedArray2.size();i++){
        cout<<sortedArray2[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

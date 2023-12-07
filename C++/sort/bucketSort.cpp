#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class BucketSort{
    public:
        static vector<double> bucketSort(double *array,int length){
            double max = array[0];
            double min = array[0];
            for(int i =0 ; i< length ;i++){
                if(array[i] > max){
                    max = array[i];
                }
                if(array[i]<min){
                    min = array[i];
                }
            }
            double d = max -min;
            int bucketNum = length;
            vector<list<double>> bucketList(bucketNum,list<double>());
            for(int i =0;i<bucketNum;i++){
                bucketList.push_back(list<double>());
            }

            for(int i =0;i<length;i++){
                int num =(int)((array[i]-min) * (bucketNum-1) /d);
                bucketList[num].push_back(array[i]);
            }

            for(int i =0;i<bucketList.size();i++){
                bucketList[i].sort();
            }
            vector<double>sortedArray(length,0);
            int index =0;
            for(const auto& list : bucketList) {
                for(const auto& element : list) {
                    sortedArray[index] =element;
                    index++;
                    cout<<element<<" ";
                }
            }
            cout<<endl;
            return sortedArray;
        }
};

int main(){
    double array[] ={4.12,6.421,0.0023,3.0,2.123,8.122,4.12,10.09};
    int length = sizeof(array)/sizeof(array[0]);
    vector<double>sortedArray = BucketSort::bucketSort(array,length);
    return 0;
}
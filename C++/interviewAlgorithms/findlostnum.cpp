//如果要找一串连续数字中，缺失的某个数字，可以直接算这些数的和然后相减，差值就是缺失的那个数
#include<iostream>
#include<vector>
using namespace std;

class FindLostNum{
    public:
        static vector<int> findLostNum(int *array,int length){
            //用于存储2个出现奇数次的整数
            vector<int>result(2);
            //第一次进行整体异或运算
            int xorResult =0;
            for(int i=0;i<length;i++){
                xorResult ^=array[i];
            }
            //如果进行异或运算的结果为0，则说明输入的数组不符合题目要求
            if(xorResult ==0){
                cout<<"输入的数组不符合要求"<<endl;
                return {};
            }
            //确定2个整数的不同位，一次来做分组
            int separator =1;
            while(0 ==(xorResult&separator)){
                separator<<=1;//向左移位，意味着变成原来的2倍（001->010)
            }
            //第二次分组进行异或运算
            for(int i=0;i<length;i++){
                if(0==(array[i]&separator)){
                    result[0] ^=array[i];
                }
                else{
                    result[1] ^=array[i];
                }
            }
            return result;
        }
};

int main(){
    int array[]={4,1,2,2,5,1,4,3};
    //int array[] ={4,4,2,2,6,6,8,8};
    int length =sizeof(array)/sizeof(array[0]);
    vector<int> result=FindLostNum::findLostNum(array,length);
    cout<<result[0]<<","<<result[1]<<endl;
    return 0;
}

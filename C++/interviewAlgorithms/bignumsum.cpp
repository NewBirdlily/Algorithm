#include<iostream>
#include<vector>
using namespace std;

class BigNumberSum{
    public:
        static string bigNumberSum(string bigNumberA,string bigNumberB){
            //把两个大整数用数组逆序存储，数组长度等于较大整数位数+1（高位进位预留）
            int maxLength = max(bigNumberA.length(),bigNumberB.length());
            vector<int> arrayA(maxLength +1);
            for(int i =0;i<bigNumberA.length();i++){
                arrayA[i]=bigNumberA[bigNumberA.length()-1-i]-'0';//将大整数逆序存储进数组
            }
            vector<int> arrayB(maxLength+1);
            for(int i=0;i<bigNumberB.length();i++){
                arrayB[i] = bigNumberB[bigNumberB.length()-i-1]-'0';
            }
            //构建result数组，数组长度等于较大整数位数+1
            vector<int> result(maxLength+1);
            //遍历数组，按位相加
            for(int i =0;i<result.size();i++){
                int temp = result[i];
                temp +=arrayA[i];
                temp +=arrayB[i];
                //判断是否进位
                if(temp>=10){
                    temp -=10;
                    result[i+1]=1;
                }
                result[i]=temp;
            }
            //把result数组再次逆序并转成string
            string sb;
            //是否找到大整数的最高有效位
            bool findFirst =false;
            for(int i = result.size() -1;i>=0;i--){
                if(!findFirst){
                    if(result[i] == 0){
                        continue;
                    }
                    findFirst =true;
                }
                sb +=to_string(result[i]);
            }
            return sb;
        }
};

int main(){
    cout<<BigNumberSum::bigNumberSum("426709752318","95481253129")<<endl;
    return 0;
}
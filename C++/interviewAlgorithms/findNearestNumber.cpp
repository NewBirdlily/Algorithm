#include<iostream>
#include<vector>
using namespace std;

class FindNearestNumber{
    public:
        static vector<int> findNearestNumber(vector<int>& numbers){
            //1.从后向前查看逆序区域，找到逆序区域的前一位，也就是数字置换的边界
            int index = findTransferPoint(numbers);
            //如果数字置换边界是0，说明整个数组已经逆序，无法得到更大的相同数字组成的整数，返回空向量
            if(index == 0){
                return {};
            }
            //2.把逆序区域前一位和逆序区域中刚刚大于它的数字交换位置
            //复制并入参，避免直接修改入参
            vector<int> numbersCopy = numbers;
            exchangeHead(numbersCopy,index);
            //3.把原来的逆序区域转为顺序
            reverse(numbersCopy,index);
            return numbersCopy;
        }
        static void outputNumbers(vector<int>& numbers){
            for(int i: numbers){
                cout<<i<<"";
            }
            cout<<endl;
        }

    private:
        static int findTransferPoint(vector<int>& numbers){
            int length = numbers.size();
            for(int i =length-1;i>0;i--){
                if(numbers[i] > numbers[i-1]){
                    return i;
                }
            }
            return 0;
        }
        static void exchangeHead(vector<int>& numbers,int index){
            int head = numbers[index-1];
            for(int i =numbers.size()-1;i>0;i--){
                if(head<numbers[i]){
                    numbers[index-1] = numbers[i];
                    numbers[i] = head;
                    break;
                }
            }
        }
        static void reverse(vector<int>& numbers,int index){
            int i =index,j=numbers.size()-1;
            while(i<j){
                swap(numbers[i], numbers[j]);
                i++;
                j--;
            }
        }
};

int main(){
    vector<int> numbers = {1,2,3,4,5};
    int length = numbers.size();
    for(int i =0; i<10;i++){
        numbers = FindNearestNumber::findNearestNumber(numbers);
        FindNearestNumber::outputNumbers(numbers);
    }
    return 0;
}

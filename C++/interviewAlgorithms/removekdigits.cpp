#include<iostream>
#include<string>
#include<stack>
using namespace std;

class RemoveKDigits{
    public:
        static string removeKDigits1(string num,int k){
            string numNew =num;
            for(int i =0;i<k;i++){
                bool hascut =false;
                //从左往右遍历，找到比自己右侧数字大的数字并删除
                for(int j=0;j<numNew.size()-1;j++){
                    if (numNew[j]> numNew[j+1]) {
                        numNew = numNew.substr(0,j)+numNew.substr(j+1,numNew.size());
                        hascut = true;
                        break;
                    }
                }
                //如果没有找到要删除的数字，则删除最后一个数字
                if(!hascut){
                    numNew = numNew.substr(0,numNew.size()-1);
                }
                //清除整数右侧的数字0
                numNew = removeZero(numNew);
            }
            //如果整数的所有数字都被删除了，直接返回0
            if(numNew.size() ==0){
                return "0";
            }
            return numNew;
        }

    static string removeKDigits2(string num, int k) {
    // 新整数的最终长度 = 原整数长度 - k
    int newLength = num.size() - k;
    // 创建一个栈，用于接收所有的数字
    stack<char> st;
    for (int i = 0; i < num.size(); ++i) {
        // 遍历当前数字
        char c = num[i];
        // 当栈顶数字大于遍历到的当前数字时，栈顶数字出栈（相当于删除数字）
        while (!st.empty() && st.top() > c && k > 0) {
            st.pop();
            k -= 1;
        }
        // 遍历到的当前数字入栈
        st.push(c);
    }
    // 找到栈中第1个非0数字的位置，一次构建新的整数字符串
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    // 去除前导零
    int offset = 0;
    while (offset < result.length() && result[offset] == '0') {
        offset++;
    }
    result = result.substr(offset);

    return result.empty() ? "0" : result.substr(0, newLength);
}

    private:
        static string removeZero(string num){
            for(int i =0;i<num.size()-1;i++){
                if(num[0] !='0'){
                    break;
                }
                num = num.substr(1,num.size());
            }
            return num;
        }
};

int main(){
    cout<<RemoveKDigits::removeKDigits1("1593212",3)<<endl;
    cout<<RemoveKDigits::removeKDigits1("30200",1)<<endl;
    cout<<RemoveKDigits::removeKDigits1("10",2)<<endl;
    cout<<RemoveKDigits::removeKDigits1("541270936",3)<<endl;
    cout<<endl;

    cout<<RemoveKDigits::removeKDigits2("1593212",3)<<endl;
    cout<<RemoveKDigits::removeKDigits2("30200",1)<<endl;
    cout<<RemoveKDigits::removeKDigits2("10",2)<<endl;
    cout<<RemoveKDigits::removeKDigits2("541270936",3)<<endl;
    return 0;
}
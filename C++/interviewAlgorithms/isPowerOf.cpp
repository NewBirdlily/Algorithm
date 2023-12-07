#include<iostream>
using namespace std;

class IsPowerOf2{
    public:
        static bool isPowerOf2(int num){
            if((num&(num-1))==0){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    cout<<IsPowerOf2::isPowerOf2(32)<<endl;
    cout<<IsPowerOf2::isPowerOf2(19)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

class GCD{
    public:
        static int gcd(int a,int b){
            if(a==b){
                return a;
            }
            if((a&1) ==0 && (b&1)==0){
                return gcd(a>>1,b>>1)<<1;
            }
            else if((a&1)!=0 &&(b&1)==0){
                return gcd(a,b>>1);
            }
            else if((a&1)==0 &&(b&1)!=0){
                return gcd(a>>1,b);
            }
            else{
                int big =a>b ? a:b;
                int small = a<b ? a:b;
                return gcd(big-small,small);//更相减损书
            }
        }
};

int main(){
    cout<<GCD::gcd(25,5)<<endl;
    cout<<GCD::gcd(100,80)<<endl;
    cout<<GCD::gcd(27,14)<<endl;
}
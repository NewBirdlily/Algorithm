#include<iostream>
#include<vector>
using namespace std;

class Bitmap{
    private:
        vector<long> words;
        int size;
        int getWordIndex(int bitIndex){
            //右移6位，相当于除以64
            return bitIndex >>6;
        }
    public:
        Bitmap(int size){
            this->size=size;
            this->words =vector<long>(getWordIndex(size-1) +1);
        }

        bool getBit(int bitIndex){
            if(bitIndex <0||bitIndex>size-1){
                cout<<"超过Bitmap有效范围！"<<endl;
                return false;
            }
            int wordIndex =getWordIndex(bitIndex);
            return (words[wordIndex] & (1L<<bitIndex)) !=0;
        }
        void setBit(int bitIndex){
            if(bitIndex <0 ||bitIndex>size-1){
                cout<<"超过Bitmap有效范围！"<<endl;
            return;
            }
            int wordIndex = getWordIndex(bitIndex);
            words[wordIndex] |=(1L <<bitIndex);
        }
};

int main(){
    Bitmap bitmap(128);
    bitmap.setBit(126);
    bitmap.setBit(75);
    //bitmap.setBit(-1);
    cout<<bitmap.getBit(126)<<endl;
    cout<<bitmap.getBit(78)<<endl;
    //cout<<bitmap.getBit(129)<<endl;
    return 0;
}
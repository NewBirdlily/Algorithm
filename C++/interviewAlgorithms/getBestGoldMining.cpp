#include<iostream>
#include<vector>
using namespace std;

class GetBestGoldMining{
    public:
        static int getBestGoldMining1(int w,int n,int *p,int *g){
            if(w==0||n==0){
                return 0;
            }
            if(w<p[n-1]){
                return getBestGoldMining1(w,n-1,p,g);
            }
            return max(getBestGoldMining1(w,n-1,p,g),getBestGoldMining1(w-p[n-1],n-1,p,g)+g[n-1]);
        }

        static int getBestGoldMining2(int w,int n,int *p,int *g){
            //创建表格
            vector<vector<int>> resultTable(n+1,vector<int>(w+1,0));
            //填充表格
            for(int i =1;i<=n;i++){
                for(int j=1;j<=w;j++){
                    if(j<p[i-1]){
                        resultTable[i][j]=resultTable[i-1][j];
                    }
                    else{
                        resultTable[i][j]=max(resultTable[i-1][j],resultTable[i-1][j-p[i-1]]+g[i-1]);
                    }
                }
            }
            //返回最后1个格子的值
            return resultTable[n][w];
        }
};
int main(){
    int w=10;
    int p[]={5,5,3,4,3};
    int g[]={400,500,200,300,350};
    int n = sizeof(g)/sizeof(g[0]);
    cout<<"最优收益 ：\n"<<GetBestGoldMining::getBestGoldMining1(w,n,p,g)<<endl;
    cout<<"最优收益 ：\n"<<GetBestGoldMining::getBestGoldMining2(w,n,p,g)<<endl;
    return 0;
}
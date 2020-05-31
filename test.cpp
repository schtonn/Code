#include "bits/stdc++.h"
#include "iostream"
using namespace std;
const int N=1<<10;
int n,m,e[25][25];
bool dp[N][25];//dp[i][j]表示状态为i，最后到达j点有没有路径
int g[N][25];
int fact(int n) 
{ if(n<2)                       //将 2 换成其它数如 8 就可输出 8 进制的结果
 return n; 
 else
  { return fact(n/2)*10+n%2;                     //将二进制结果整个输出 
  } 
} 

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u][v]=true;
    }
    dp[1][1]=true;
    for(int s=1;s<(1<<n);++s){
        for(int p=1;p<=n;++p){
            if(s&(1<<(p-1))==0)continue;//判断p是否为S中元素
            for(int q=1;q<=n;++q){
                if(s&(1<<(q-1))==0)continue;//判断q是否为S中元素
                if(!e[q][p])continue;//判断有没有q到p的边
                if(dp[s^(1<<(p-1))][q]){//判断dp[{s}-p][q]是否为真
                    dp[s][p]=true;
                    g[s][p]=q;
                    cout<<s<<"->"<<fact(s)<<' '<<q<<"->"<<p<<endl;
                }
            }
        }
    }
    cout<<endl;
    int s=(1<<n)-1;
    bool flag;
    stack<int>output;
    for(int i=1;i<=n;i++){
        cout<<dp[s][i]<<' ';
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(dp[s][i]&&e[i][1]){
            int p=i;
            output.push(p);
            do{
                output.push(g[s][p]);
                int t=p;
                p=g[s][p];
                s-=(1<<(t-1));
            }while(s!=1);
            break;
        }
    }
    while(!output.empty()){
        cout<<output.top()<<' ';
        output.pop();
    }
    return 0;
}
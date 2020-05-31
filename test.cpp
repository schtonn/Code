#include "bits/stdc++.h"
using namespace std;
const int N=1<<10;
int n,m,g[N][25];
int e[25][25];
int dp[N][25];//dp[i][j]表示状态为i，最后到达j点有没有路径
int len[N][25];
int special[N][3];
int fact(int n) {
    if(n<2)return n;
    else{
        return fact(n/2)*10+n%2;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int c;
            cin>>c;
            e[i][j]=c;
        }
    }
    for(int i=1;i<=n;i++){
        dp[1<<(i-1)][i]=1;
        special[1<<(i-1)][1]=-1;
        special[1<<(i-1)][2]=i;
    }
    for(int s=1;s<(1<<n);++s){
        for(int p=1;p<=n;++p){
            if(s&(1<<(p-1))==0)continue;//判断p是否为S中元素
            for(int q=1;q<=n;++q){
                if(s&(1<<(q-1))==0)continue;//判断q是否为S中元素
                if(e[q][p]==-1)continue;//判断有没有q到p的边
                if(dp[s^(1<<(p-1))][q]){//判断dp[{s}-p][q]是否为真
                    if(len[s][p]==0)len[s][p]=len[s^(1<<(p-1))][q]+e[q][p];
                    else len[s][p]=min(len[s][p],len[s^(1<<(p-1))][q]+e[q][p]);
                    dp[s][p]=true;
                    g[s][p]=q;
                    cout<<s<<"->"<<fact(s)<<' '<<q<<"->"<<p<<' '<<len[s][p]<<endl;
                }
            }
        }
    }
    cout<<endl;
    int s=(1<<n)-1;
    stack<int>output;
    for(int i=1;i<=n;i++){
        cout<<len[s][i]<<' ';
    }
    cout<<endl;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(dp[s][i]){
            ans=min(ans,len[s][i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
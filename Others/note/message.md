问题描述
　　有 n 个同学(编号为 1 到 n)正在玩一个信息传递的游戏。在游戏里每人都有一个固定的信息传递对象,其中,编号为 i 的同学的信息传递对象是编号为T i 的同学。
　　游戏开始时,每人都只知道自己的生日。之后每一轮中,所有人会同时将自己当前所知的生日信息告诉各自的信息传递对象(注意:可能有人可以从若干人那里获取信息,但是每人只会把信息告诉一个人,即自己的信息传递对象)。当有人从别人口中得知自己的生日时,游戏结束。请问该游戏一共可以进行几轮?
输入格式
　　输入文件名为 message.in 。
　　输入共 2 行。
　　第 1 行包含 1 个正整数 n,表示 n 个人。
　　第 2 行包含 n 个用空格隔开的正整数 T 1 , T 2 , ... ... , T n ,其中第i 个整数T i 表示编号为 i的同学的信息传递对象是编号为 T i 的同学, T i ≤ n 且 T i ≠ i。
　　数据保证游戏一定会结束。
输出格式
　　输出文件名为 message.out 。
　　输出共 1 行,包含 1 个整数,表示游戏一共可以进行多少轮。



#include "bits/stdc++.h"
using namespace std;
int n,f[200001]={0},a[200001],cnt=0,ans=1e9,aa=0;
int find(int x){
    if(x==f[x])return x;
    else return f[x]=find(f[x]);
}
int round(int x){
    cnt++;
    if((x==aa&&cnt!=1)||(x==aa&&a[x]==x)){
        return cnt;
    }
    else round(a[x]);
}
int main(){
		freopen("message.in","r",stdin);
	  freopen("message.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        cnt=0,aa=0;
        cin>>a[i];
        if(find(i)!=find(a[i]))f[i]=find(a[i]);
        if(f[i]==i&&find(i)==i)aa=i,round(i),ans=min(ans,cnt);
    }
    cout<<ans-1;
    return 0;
}
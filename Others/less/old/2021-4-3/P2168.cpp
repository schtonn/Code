#include "bits/stdc++.h"
using namespace std;
const long long N=1000010;
long long n,k,ans,md,a[N];
long long tot,h[N];
struct node{
    long long v,nxt;
}e[N<<1];
void adde(long long u,long long v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}

long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct wd{
    long long id,w,dep;
    bool operator>(const wd&u)const{
        return u.w==w?u.dep<dep:u.w<w;
    }
};
wd add(long long a,long long b,long long c){
    return wd{a,b,c};
}
priority_queue<wd,vector<wd>,greater<wd>>q;

void dfs(long long u,long long d){
    if(u<=n){
        ans+=a[u]*d;
        md=max(md,d);
    }
    for(long long i=h[u];i;i=e[i].nxt){
        dfs(e[i].v,d+1);
    }
}

int main(){
    n=read();k=read();
    for(long long i=1;i<=n;i++){
        q.push(add(i,a[i]=read(),0));
    }
    while((n-1)%(k-1)!=0){
        q.push(add(++n,0,0));
    }
    long long id=n,n1=n;
    while(n1-=k-1,n1>=1){
        long long p=0,mx=0;
        ++id;
        for(long long i=1;i<=k;i++){
            wd cur=q.top();
            q.pop();
            p+=cur.w;
            mx=max(mx,cur.dep);
            adde(id,cur.id);
        }
        q.push(add(id,p,mx+1));
    }
    dfs(id,0);
    cout<<ans<<endl<<md<<endl;
    return 0;
}
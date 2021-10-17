//https://www.luogu.com.cn/record/45693575
#include "bits/stdc++.h"
using namespace std;
const long long N=500010;
struct node{
    long long v,nxt;
}e[N<<1];
long long n,tot,f[N],h[N],fa[N],ans[N];
string s;
void adde(long long u,long long v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
stack<long long>st;
void dfs(long long u){
    long long last=0;
    if(s[u]==')'&&(!st.empty())){
        last=st.top();
        f[u]=f[fa[last]]+1;
        st.pop();
    }else if(s[u]=='(')st.push(u);
    ans[u]=ans[fa[u]]+f[u];
    for(long long i=h[u];i;i=e[i].nxt){
        dfs(e[i].v);
    }
    if(last)st.push(last);
    else if(!st.empty())st.pop();
}
int main(){
    cin>>n>>s;
    s=' '+s;
    for(long long i=2;i<=n;i++){
        cin>>fa[i];
        adde(fa[i],i);
    }
    dfs(1);
    long long ret=0;
    for(long long i=1;i<=n;i++){
        ret^=ans[i]*i;
    }
    cout<<ret<<endl;
    return 0;
}
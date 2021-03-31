#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;
int tot;
int pr[MAXN];
bool vis[MAXN];
void calc(int n){
    for(int i=2;i<=n;++i){
        if(!vis[i])pr[++tot]=i;
        for(int j=1;j<=tot&&(int)i*pr[j]<=n;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0)break;
        }
    }
}
ll up[MAXN],idx[MAXN];
int n,m,k,p;
int main(){
    cin>>n>>m>>k>>p;
    for(int i=1;i<=m;++i)up[i]=m+k-i;
    calc(m);
    for(int i=1;i<=tot&&pr[i]<=m;++i){
        for(int j=pr[i];j<=m;j*=pr[i]){
            idx[i]+=m/j;
        }
    }
    for(int i=1;i<=tot;++i){
        int s=m+k-1-(m+k-1)%pr[i];
        for(int j=m+k-s;j<=m;j+=pr[i]){
            while(idx[i]&&up[j]%pr[i]==0){
                idx[i]--;
                up[j]/=pr[i];
            }
            if(!idx[i])break;
        }
    }
    int s=1,sum=1;
    for(int i=1;i<=m;++i)s=(ll)s*up[i]%p;
    for(int i=1;i<=n;++i)sum=(ll)sum*(s-i+1)%p;
    cout<<sum<<endl;
    return 0;
}
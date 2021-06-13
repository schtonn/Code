#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
string l,r;
int a[1010];
ll dp[1010][20][20];
ll dfs(int pos,int p1,int p2,bool lim,bool lead){
    if(!pos)return 1;
    if(dp[pos][p1][p2]!=-1&&!lim&&!lead&&p1!=-1&&p2!=-1)return dp[pos][p1][p2];
    int up=lim?a[pos]:9;
    ll ret=0;
    for(ll i=0;i<=up;i++){
        if(i!=p1&&i!=p2&&!lead){
            ret=(ret+dfs(pos-1,i,p1,lim&&i==a[pos],0))%mod;
        }else if(lead){
            ret=(ret+dfs(pos-1,(i==0&&lead)?-1:i,-1,lim&&i==a[pos],i==0&&lead))%mod;
        }
    }
    if(!lim&&!lead&&p1!=-1&&p2!=-1)return dp[pos][p1][p2]=ret;
    return ret;
}
ll solve(){
    int s=l.length();
    for(int i=0;i<s;i++){
        a[s-i]=l[i]-'0';
    }
    ll ansl=dfs(s,-1,-1,1,1);
    s=r.length();
    for(int i=0;i<s;i++){
        a[s-i]=r[i]-'0';
    }
    ll ansr=dfs(s,-1,-1,1,1);
    ansl--;
    s=l.length();
    for(int i=2;i<=s;i++){
        if(l[i]==l[i-1]||(l[i]==l[i-2]&&(i-2>=1))){
            ansl++;
            break;
        }
    }
    return (ansr-ansl)%mod;
}
int main(){
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    ll numl=0,numr=0;
    int s1=l.length(),s2=r.length();
    for(int i=0;i<s1;i++){
        numl=(numl*10%mod+(l[i]^48))%mod;
    }
    for(int i=0;i<s2;i++){
        numr=(numr*10%mod+(r[i]^48))%mod;
    }
    printf("%lld",((numr-numl-solve()+1)%mod+mod)%mod);
    return 0;
} 
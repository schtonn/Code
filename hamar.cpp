#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=1000010;
ll m,n,k,p;
struct matrix{
    ll v[5][5];
    ll x,y;
}f,A,B,I,ans;
ll e[N],g[N],inv[N],vis[N];
void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b){
        d=a;
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,d,y,x);
    y-=x*(a/b);
}
ll getinv(ll a){
    ll d,x,y;
    exgcd(a,k,d,x,y);
    return d==1?(x+k)%k:-1;
}
ostream&operator<<(ostream&ous,matrix a){
    for(ll i=0;i<a.x;i++){
        for(ll j=0;j<a.y;j++){
            ous<<a.v[i][j]<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    ll x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%p;
        }
    }
    return c;
}
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    ll x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=0;
            for(ll k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%p;
            }
        }
    }
    return c;
}
matrix operator^(matrix a,ll b){
    matrix c=I;
    while(b){
        if(b&1)c=c*a;
        a=a*a;
        b>>=1;
    }
    return c;
}
void init(){
    A.x=A.y=B.x=B.y=3;
    I.x=I.y=3;
    f.x=3;f.y=1;
    f.v[1][0]=f.v[2][0]=1;
    A.v[0][0]=A.v[0][1]=A.v[1][0]=A.v[2][2]=1;
    B.v[0][0]=B.v[0][1]=B.v[1][0]=B.v[2][2]=1;
    B.v[0][2]=-1;
    I.v[0][0]=I.v[1][1]=I.v[2][2]=1;
}
int main(){
    // freopen("rabbit.in","r",stdin);
    // freopen("rabbit.out","w",stdout);
    init();
    cin>>n>>k>>p;
    int a=1,b=2;
    memset(e,-1,sizeof(e));
    for(int i=1;i<=k*k;i++){
        if(a==1&&b==1)break;
        if(!inv[b])inv[b]=getinv(b);
        if(inv[b]==-1){
            swap(a,b);
            b=(a+b)%k;
            continue;
        }
        if(e[inv[b]]==-1){
            e[inv[b]]=i;
            g[inv[b]]=a*inv[b]%k;
        }
        swap(a,b);
        b=(a+b)%k;
    }
    ll flag=0;
    ll cur=1,ptr=0;
    while(true){
        if(vis[cur]){
            flag=cur;
            break;
        }
        vis[cur]=1;
        if(ptr+e[cur]+1>n||e[cur]==-1){
            f=(A^(n-ptr))*f;
            break;
        }
        f=(A^(e[cur]+1))*f;
        ptr+=e[cur]+1;
        if(ptr>=n)break;
        f=B*f;
        ptr++;
        cur=g[cur];
        if(ptr>=n)break;
    }
    matrix C;
    ll siz;
    if(flag){
        siz=e[flag]+2;
        C=B*(A^(e[flag]+1));
        for(ll i=g[flag];i!=flag;i=g[i]){
            C=B*(A^(e[i]+1))*C;
            siz+=e[i]+2;
        }
        f=(C^((n-ptr)/siz))*f;
        if((n-ptr)%siz){
            ptr=n-((n-ptr)%siz);
            while(true){
                if(ptr+e[cur]+1>n){
                    f=(A^(n-ptr))*f;
                    break;
                }
                f=(A^(e[cur]+1))*f;
                ptr+=e[cur]+1;
                if(ptr>=n)break;
                f=B*f;
                ptr++;
                cur=g[cur];
                if(ptr>=n)break;
            }
        }
    } 
    cout<<(f.v[0][0]+p)%p<<endl;
    return 0;
}
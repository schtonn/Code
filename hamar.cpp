#include "bits/stdc++.h"
using namespace std;
#define MAXN 60
typedef long long ll;
ll n,C[MAXN][MAXN],a[MAXN],found[MAXN],pos[MAXN],kk,f,kind[MAXN],fos[MAXN],frog;
void copy(){
    for(ll i=0;i<=n;i++){
        fos[i]=pos[i];
    }
}
int main(){
    freopen("Excavations2.in","r",stdin);
    freopen("Excavations2.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>kind[i];
    }
    cin>>kk>>f;
    for(ll i=0;i<f;i++){
        cin>>found[i];
    }
    for(ll i=0;i<f;i++){
        for(ll j=0;j<n;j++){
            if(found[i]==kind[j]){
                a[i]++;
            }
        }
    }
    C[0][0]=1;
    for(ll i=1;i<MAXN;i++){
        C[i][0]=C[i][i]=1;
        for(ll j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    for(ll i=0;i<=a[0];i++){
        pos[i]=C[a[0]][i];
    }
    copy();
    for(ll i=1;i<f;i++){
        memset(pos,0,sizeof(pos));
        for(ll j=1;j<MAXN;j++){
            for(ll k=1;k<MAXN;k++){
                if(j+k<=kk){
                    pos[j+k]+=fos[j]*C[a[i]][k];
                }
            }
        }
        copy();
    }
    cout<<pos[kk]<<endl;
    return 0;
}
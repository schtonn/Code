#include "bits/stdc++.h"
using namespace std;
#define DEBUG
char S0[1010], T0[1010];
char S[1010], T[1010];
int F[1010][1010], B[1010][1010];
char Q[1010],P[1010],lq=0;
int main(){
    #ifndef DEBUG
    freopen("WolfDelaymaster.in","r",stdin);
    freopen("WolfDelaymaster.out","w",stdout);
    #endif
    cin>>S0>>T0;
    int u=strlen(S0), v=strlen(T0);
    strcpy(S, "*");
    strcat(S, S0);
    strcpy(T, "*");
    strcat(T, T0);
    F[0][0]=0;
    for(int i=1;i<=u;++i)F[i][0]=0;
    for(int j=1;j<=v;++j)F[0][j]=0;
    for(int i=1;i<=u;++i){
        for(int j=1;j<=v;++j){
            F[i][j]=F[i-1][j];B[i][j]=2;
            if(S[i]==T[j] && F[i-1][j-1]+1>F[i][j]){
                F[i][j]=F[i-1][j-1]+1;B[i][j]=1;
            }
            if(F[i][j-1]>F[i][j]){
                F[i][j]=F[i][j-1];B[i][j]=3;
            }
        }
    }
    int ans=F[u][v], pS=u, pT=v;
    while(pS>0 && pT>0){
        if(B[pS][pT]==1){
            Q[++lq]=S[pS];
            --pS;--pT;
        }
        else if(B[pS][pT]==2)--pS;
        else --pT;
    }
    cout<<ans<<endl;
    for(int i=lq;i>0;--i)cout<<Q[i];
    cout<<endl;
    return 0;
}
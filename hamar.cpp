#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
int nxt[MAXN];
int la,lb,k;
char txt[MAXN],pat[MAXN];
int main(){
    cin>>pat+1;
    cin>>txt+1;
    la=strlen(txt+1);
    lb=strlen(pat+1);
    for(int i=2;i<=lb;i++){
        while(k&&pat[i]!=pat[k+1])k=nxt[k];
        if(pat[k+1]==pat[i])k++;
        nxt[i]=k;
    }
    k=0;
    for(int i=1;i<=la;i++){
        while(k>0&&pat[k+1]!=txt[i])k=nxt[k];
        if(pat[k+1]==txt[i])k++;
        if(k==lb){cout<<i-lb+1<<' ';k=nxt[k];}
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define MAXN 10010
int n,a[MAXN],b[MAXN],c[MAXN];
char frog[MAXN];
void frogger(int grof[]){//frogger that
    cin>>frog;
    n=strlen(frog);
    for(int i=0;i<n;i++)grof[n-i-1]=frog[i]-'0';
}
int main(){
    frogger(a);
    frogger(b);
    memset(c,0,sizeof(c));
    for(int i=0;i<MAXN-1;i++){
        for(int j=0;j<=i;j++){
            c[i]+=a[j]*b[i-j];
        }
        if(c[i]>=10){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    int frocnt=MAXN;
    while(!c[frocnt]&&frocnt>=0)frocnt--;
    for(int i=frocnt;i>=0;i--)cout<<c[i];
    if(frocnt==-1)cout<<0<<endl;
    return 0;
}
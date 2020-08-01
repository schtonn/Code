#include "bits/stdc++.h"
using namespace std;
#define MAXN 1010
int n,alen=MAXN-1,blen=MAXN-1,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
char frog[MAXN];
void frogger(int grof[]){//frogger that
    cin>>frog;
    n=strlen(frog);
    for(int i=0;i<n;i++)grof[n-i-1]=frog[i]-'0';
}
bool check(int step){
    if(d[step+blen])return true;
    for(int i=blen-1;i>=0;i--){
        if(d[step+i]==b[i])continue;
        return d[step+i]>b[i];
    }
    return true;
}
int main(){
    frogger(a);
    frogger(b);
    while(!a[alen])alen--;
    while(!b[blen])blen--;
    alen++;blen++;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(int i=0;i<alen;i++)d[i]=a[i];
    for(int i=alen-blen;i>=0;i--){
        while(check(i)){
            for(int j=0;j<blen;j++){
                d[i+j]-=b[j];
                if(d[i+j]<0){
                    d[i+j+1]--;
                    d[i+j]+=10;
                }
            }
            c[i]++;
        }
    }
    int frocnt=MAXN;
    while(!c[frocnt])frocnt--;
    for(int i=frocnt;i>=0;i--)cout<<c[i];
    return 0;
}
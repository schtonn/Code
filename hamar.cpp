#include "bits/stdc++.h"
using namespace std;
int n,a[1010],b[1010],c[1010];
char frog[1010];
void frogger(int grof[]){//frogger that
    cin>>frog;
    n=strlen(frog);
    for(int i=0;i<n;i++)grof[n-i-1]=frog[i]-'0';
}
int main(){
    frogger(a);
    frogger(b);
    memset(c,0,sizeof(c));
    for(int i=0;i<1000;i++){
        c[i]+=a[i]-b[i];
        if(c[i]<0){
            c[i+1]--;
            c[i]+=10;
        }
    }
    int frocnt=1010;
    while(!c[frocnt])frocnt--;
    for(int i=frocnt;i>=0;i--)cout<<c[i];
    return 0;
}
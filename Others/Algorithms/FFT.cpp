#include "bits/stdc++.h"
#define N 350000
using namespace std;
const double pi=3.141592653589793238462643383279502884197;
char a[N>>1],b[N>>1];
double ar[N],av[N],br[N],bv[N];
int i,la,lb,lans,l;
int ans[N>>1];
void dswap(double&x,double&y){double t=x;x=y;y=t;}
int rev(int x,int len){
    int ret=0;
    for(int i=1;i<=len;i++){
        ret<<=1;
        ret|=x&1;
        x>>=1;
    }
    return ret;
}
void FFT(double*ar,double*av,int n,int flag){
    int lgn=log((double)n)/log((double)2);
    for(int i=0;i<=n-1;i++){
        int j=rev(i,lgn);
        if(j>i){
            dswap(ar[i],ar[j]);
            dswap(av[i],av[j]);
        }
    }
    for(int s=1;s<=lgn;s++){
        int m=(1<<s);
        double wrP=cos(2*pi/m),wvP=sin(2*pi/m);
        if(flag)wvP=-wvP;
        for(i=0;i<n;i+=m){
            double wr=1.0,wv=0.0;
            for(int j=0;j<=m/2-1;j++){
                int p=i+j+m/2;
                double tr=wr*ar[p]-wv*av[p];
                double tv=wr*av[p]+wv*ar[p];
                double ur=ar[i+j],uv=av[i+j];
                ar[i+j]=ur+tr;
                av[i+j]=uv+tv;
                ar[p]=ur-tr;
                av[p]=uv-tv;
                double trP=wr*wrP-wv*wvP;
                double tvP=wr*wvP+wv*wrP;
                wr=trP;
                wv=tvP;
            }
        }
    }
}
void clean(){
    memset(ans,0,sizeof(ans));
    memset(ar,0,sizeof(ar));
    memset(av,0,sizeof(av));
    memset(br,0,sizeof(br));
    memset(bv,0,sizeof(bv));
}
void work(){
    la=strlen(a);
    lb=strlen(b);
    l=1;
    int lmax=max(la,lb);
    while(l<lmax)l<<=1;
    l<<=1;
    for(int i=0;i<=l-1;i++){
        if(i<la)ar[i]=(double)a[la-i-1]-'0';
        if(i<lb)br[i]=(double)b[lb-i-1]-'0';
        av[i]=bv[i]=0.0;
    }
    FFT(ar,av,l,0);
    FFT(br,bv,l,0);
    for(int i=0;i<=l-1;i++){
        double r=ar[i]*br[i]-av[i]*bv[i];
        double v=ar[i]*bv[i]+av[i]*br[i];
        ar[i]=r;av[i]=v;
    }
    FFT(ar,av,l,1);
    for(int i=0;i<=l-1;i++){ar[i]/=l;av[i]/=l;}
    for(int i=0;i<=l-1;i++)ans[i]=(int)(ar[i]+0.5);
    for(int i=0;i<=l-1;i++)ans[i+1]+=ans[i]/10,ans[i]%=10;
    lans=la+lb+2;
    while(ans[lans]==0&&lans>0)lans--;
    for(int i=lans;i>=0;i--)printf("%d",ans[i]);
    printf("\n");
}
int main(){
    while(true){
        cin>>a>>b;
        clean();
        work();
    }
    return 0;
}

#include "bits/stdc++.h"
#define N 350000
using namespace std;
const double pi=3.141592653589793238462643383279502884197;
char a[N>>1],b[N>>1];
double ar[N],ai[N],br[N],bi[N];
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
void FFT(double*ar,double*ai,int n,int flag){
    int lgn=log((double)n)/log((double)2);
    for(int i=0;i<=n-1;i++){
        int j=rev(i,lgn);
        if(j>i){
            dswap(ar[i],ar[j]);
            dswap(ai[i],ai[j]);
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
                double tr=wr*ar[p]-wv*ai[p];
                double tv=wr*ai[p]+wv*ar[p];
                double ur=ar[i+j],uv=ai[i+j];
                ar[i+j]=ur+tr;
                ai[i+j]=uv+tv;
                ar[p]=ur-tr;
                ai[p]=uv-tv;
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
    memset(ai,0,sizeof(ai));
    memset(br,0,sizeof(br));
    memset(bi,0,sizeof(bi));
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
        ai[i]=bi[i]=0.0;
    }
    FFT(ar,ai,l,0);
    FFT(br,bi,l,0);
    for(int i=0;i<=l-1;i++){
        double r=ar[i]*br[i]-ai[i]*bi[i];
        double I=ar[i]*bi[i]+ai[i]*br[i];
        ar[i]=r;ai[i]=I;
    }
    FFT(ar,ai,l,1);
    for(int i=0;i<=l-1;i++){ar[i]/=l;ai[i]/=l;}
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
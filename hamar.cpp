#include "bits/stdc++.h"
using namespace std;
#define MAXN 10010
const int mod=500;
struct num{
    int v[MAXN];
    void clear(){
        memset(this->v,0,sizeof(this->v));
    }
};
int len(num a){
    int alen=MAXN-1;
    while(!a.v[alen]&&alen>0)alen--;
    return alen+1;
}
void read(num &a){
    string g;
    cin>>g;
    int alen=g.length();
    for(int i=0;i<alen;i++)a.v[alen-i-1]=g[i]-'0';
}
void print(num a){
    int alen=len(a);
    for(int i=alen-1;i>=0;i--)cout<<a.v[i];
    cout<<endl;
}
void printt(num a){
    int alen=len(a);
    alen=mod;
    int hhhhhhhhamar=-1;
    for(int i=alen-1;i>=0;i--){
        hhhhhhhhamar++;
        if(hhhhhhhhamar==50){
            cout<<endl;
            hhhhhhhhamar=0;
        }
        cout<<a.v[i];
    }
    cout<<endl;
}
num add(num a,num b){
    int alen=len(a),blen=len(b);
    num c;
    c.clear();
    for(int i=0;i<alen+blen;i++){
        c.v[i]+=a.v[i]+b.v[i];
        if(c.v[i]>=10){
            c.v[i+1]++;
            c.v[i]-=10;
        }
    }
    return c;
}
num sub(num a,num b){
    int alen=len(a),blen=len(b);
    num c;
    c.clear();
    for(int i=0;i<alen+blen;i++){
        c.v[i]+=a.v[i]-b.v[i];
        if(c.v[i]<0){
            c.v[i+1]--;
            c.v[i]+=10;
        }
    }
    return c;
}
num mul(num a,num b){
    int alen=len(a),blen=len(b);
    num c;
    c.clear();
    for(int i=0;i<alen+blen;i++){
        for(int j=0;j<=i;j++){
            c.v[i]+=a.v[j]*b.v[i-j];
        }
        if(c.v[i]>=10){
            c.v[i+1]+=c.v[i]/10;
            c.v[i]%=10;
        }
    }
    return c;
}
bool check_div(int step,int blen,num b,num d){
    if(d.v[step+blen])return true;
    for(int i=blen-1;i>=0;i--){
        if(d.v[step+i]==b.v[i])continue;
        return d.v[step+i]>b.v[i];
    }
    return true;
}
num div(num a,num b){
    int alen=len(a),blen=len(b);
    num c,d;
    c.clear();
    d.clear();
    d=a;
    for(int i=alen-blen;i>=0;i--){
        while(check_div(i,blen,b,d)){
            for(int j=0;j<blen;j++){
                d.v[i+j]-=b.v[j];
                if(d.v[i+j]<0){
                    d.v[i+j+1]--;
                    d.v[i+j]+=10;
                }
            }
            c.v[i]++;
        }
    }
    return c;
}
num convert(int x){
    int cnt=0;
    num a;
    a.clear();
    while(x){
        a.v[cnt++]=x%10;
        x/=10;
    }
    return a;
}
num modd(num a){
    num b;
    b.clear();
    int alen=len(a);
    for(int i=0;i<mod;i++){
        b.v[i]=a.v[i];
    }
    return b;
}
bool eo(num a){
    return a.v[0]&1;
}
int main(){
    // freopen("mason.in","r",stdin);
    // freopen("mason.out","w",stdout);
    int p;
    cin>>p;
    cout<<floor(p*log10(2))+1<<endl;
    num ans=convert(1),a=convert(2),b=convert(p);
    while(len(b)!=1||b.v[0]!=0){
        if(eo(b))ans=modd(mul(ans,a));
        a=modd(mul(a,a));
        b=modd(div(b,convert(2)));
    }
    printt(sub(ans,convert(1)));
    return 0;
} 
#include "bits/stdc++.h"
using namespace std;
#define MAXN 10010
struct num{
    int v[MAXN];
    void clear(){
        memset(v,0,sizeof(v));
    }
};
int len(num a){
    int alen=MAXN-1;
    while(!a.v[alen])alen--;
    return alen+1;
}
void read(num &a){
    string g;
    g.clear();
    cin>>g;
    int alen=g.length();
    for(int i=0;i<alen;i++)a.v[alen-i-1]=g[i]-'0';
}
void print(num a){
    int alen=len(a);
    for(int i=alen-1;i>=0;i--)cout<<a.v[i];
    cout<<endl;
}
num add(num a,num b){
    int alen=len(a),blen=len(b);
    num c;
    c.clear();
    for(int i=0;i<alen+blen;i++){
        c.v[i]+=a.v[i]+b.v[i];
        if(c.v[i]>10){
            c.v[i+1]++;
            c.v[i]%=10;
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
            c.v[i]+=a.v[i]*b.v[i-j];
        }
        if(c.v[i]>10){
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
int main(){
    num a,b;
    read(a);
    read(b);
    print(add(a,b));
    print(sub(a,b));
    print(mul(a,b));
    print(div(a,b));
    return 0;
}
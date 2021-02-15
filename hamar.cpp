#include "bits/stdc++.h"
using namespace std;
int n;
__int128_t exgcd(__int128_t a,__int128_t b,__int128_t &x,__int128_t &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    __int128_t g=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
inline __int128_t read()
{
    __int128_t x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void write(__int128_t x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
bool modd(__int128_t a,__int128_t b){
    // write(a);
    // cout<<' ';
    // write(b);
    while(a>0){
        a-=b;
    }
    if(a!=0)return true;
    return false;
}
int main(){
    __int128_t a,b,c,x=0,y=0,g;
    cin>>n;
    for(int i=0;i<n;i++){
        a=read();
        b=read();
        c=read();
        g=exgcd(a,b,x,y);
        if(c%g){
            cout<<"no solution"<<endl;
            continue;
        }
        __int128_t w=c/g;
        x*=w;
        y*=w;
        a/=g;
        b/=g;
        if(x>0){
            __int128_t t=x/b;
            x-=t*b;
            y+=t*a;
        }
        if(x<0){
            __int128_t t=(-x)/b;
            x+=t*b;
            y-=t*a;
        }
        while(x<0){
            x+=b;
            y-=a;
        }
        write(x);
        cout<<' ';
        write(y);
        cout<<endl;
    }
    return 0;
}
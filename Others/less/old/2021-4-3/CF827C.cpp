#include "bits/stdc++.h"
using namespace std;
const int N=100010;
int n;
char s[N],tmp[N];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline int c2i(char c){
    switch(c){
        case 'A': return 0;
        case 'T': return 1;
        case 'G': return 2;
        case 'C': return 3;
        default: return 114514;
    }
}

int c[20][4][N];
int lowbit(int x){
    return x&(-x);
}
void change(int m,int i,int t,int v){
    int p=i/m+1,q=i%m;
    while((p-1)*m+q<=n){
        c[m][t][(p-1)*m+q]+=v;
        p+=lowbit(p);
    }
}
int query(int m,int i,int t){
    int res=0,p=i/m+1,q=i%m;
    while(p){
        res+=c[m][t][(p-1)*m+q];
        p-=lowbit(p);
    }
    return res;
}


int main(){
    scanf("%s",s+1),n=strlen(s+1);
    for(int i=1;i<=n;++i){
        s[i]=c2i(s[i]);
        for(int r=1;r<=10;++r){
            change(r,i,s[i],1);
        }
    }
    int q=read();
    while(q--){
        int opt=read();
        if(opt==1){
            int x=read();
            cin>>tmp;
            int nv=c2i(*tmp);
            for(int r=1;r<=10;++r){
                change(r,x,nv,1);
                change(r,x,s[x],-1);
            }
            s[x]=nv;
        }
        if(opt==2){
            int l=read(),r=read();
            cin>>tmp;
            int m=strlen(tmp),ans=0;
            for(int i=0;i<m;++i){
                tmp[i]=c2i(tmp[i]);
                int id=l+i-m;
                if(0<id)ans-=query(m,id,tmp[i]);
                id=r/m*m+(l+i)%m;
                if(id>r)id-=m;
                if(0<id)ans+=query(m,id,tmp[i]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
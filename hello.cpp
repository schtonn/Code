#include "bits/stdc++.h"
using namespace std;
struct node{
    int v,ran,l,r,siz,cnt;
}t[1000010];
int n,q,rt,tot,c[10];
int brand(){
    int ret=0;
    ret=(ret<<15)|(rand()&0x7fff);
    ret=(ret<<15)|(rand()&0x7fff);
    return ret;
}
stack<int>st;
int getnode(int v,int c){
    int ret;
    if(!st.empty())ret=st.top(),st.pop();
    else ret=++tot;
    t[ret].v=v;
    t[ret].ran=brand();
    t[ret].l=t[ret].r=0;
    t[ret].siz=t[ret].cnt=c;
    return ret;
}
void remove(int p){
    if(!p)return;
    st.push(p);
    if(t[p].l)remove(t[p].l);
    if(t[p].r)remove(t[p].r);
    t[p].l=t[p].r=0;
}
void update(int p){
    if(!p)return;
    t[p].siz=t[t[p].l].siz+t[t[p].r].siz+t[p].cnt;
}
int merge(int L,int R){
    if(L==0||R==0)return L+R;
    if(t[L].ran<t[R].ran){
        t[L].r=merge(t[L].r,R);
        update(L);
        return L;
    }else{
        t[R].l=merge(L,t[R].l);
        update(R);
        return R;
    }
}
void splits(int p,int s,int &L,int &R){
    if(!p){L=R=0;return;}
    if(t[t[p].l].siz+t[p].cnt<=s){
        L=p;
        splits(t[p].r,s-t[t[p].l].siz-t[p].cnt,t[p].r,R);
    }else if(t[t[p].l].siz+1<=s){
        int q=getnode(t[p].v,t[p].cnt-s+t[t[p].l].siz);
        t[p].cnt=s-t[t[p].l].siz;
        t[p].siz=t[p].cnt;
        int pl=t[p].l,pr=t[p].r;
        t[p].l=t[p].r=0;
        L=merge(pl,p);
        R=merge(q,pr);
    }else{
        R=p;
        splits(t[p].l,s,L,t[p].l);
    }
    update(p);
}
void count(int p){
    if(!p)return;
    c[t[p].v]+=t[p].cnt;
    count(t[p].l);
    count(t[p].r);
}
int solve(int p){
    if(!p)return 0;
    memset(c,0,sizeof(c));
    count(p);
    remove(p);
    int ret=0;
    for(int i=0;i<7;i++){
        if(c[i]/2)ret=merge(ret,getnode(i,c[i]/2));
    }
    for(int i=0;i<7;i++){
        if(c[i]&1){
            ret=merge(ret,getnode(i,1));
            break;
        }
    }
    for(int i=6;i>=0;i--){
        if(c[i]/2)ret=merge(ret,getnode(i,c[i]/2));
    }
    update(ret);
    return ret;
}
void print(int p){
    if(!p)return;
    print(t[p].l);
    for(int i=1;i<=t[p].cnt;i++)cout<<(char)(t[p].v+'a');
    print(t[p].r);
}
void printe(int p){
    if(!p)return;
    cout<<p<<' '<<t[p].l<<' '<<t[p].r<<':'<<t[p].v<<' '<<t[p].cnt<<endl;
    printe(t[p].l);
    for(int i=1;i<=t[p].cnt;i++)cerr<<(char)(t[p].v+'a');
    printe(t[p].r);
}
void check(int p){
    if(!p)return;
    if(t[p].cnt==0||t[p].siz!=t[t[p].l].siz+t[t[p].r].siz+t[p].cnt)cerr<<p<<' '<<t[p].l<<' '<<t[p].r<<' '<<t[p].siz<<' '<<t[t[p].l].siz+t[t[p].r].siz+t[p].cnt<<"ERR"<<endl;
    check(t[p].l);
    check(t[p].r);
}
int main(){
    srand(114514);
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt++;
        if(s[i]!=s[i-1]){
            rt=merge(rt,getnode(s[i-1]-'a',cnt));
            cnt=0;
        }
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        update(rt);
        l=min(l,t[rt].siz);
        r=min(r,t[rt].siz);
        int x,y,z;
        splits(rt,l-1,x,y);
        splits(y,r-l+1,y,z);
        y=solve(y);
        rt=merge(merge(x,y),z);
        print(rt);cout<<endl;
        check(rt);
    }
    printe(rt);cerr<<' '<<t[rt].siz<<endl;
    return 0;
}
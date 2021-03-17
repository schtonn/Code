#include<bits/stdc++.h>
using namespace std;
const int MAXT=50010;
const int oo=(int)1e19;
const int MAX_NODES=10100100;
map<int,int>mp;
int idx=0;
int rt[MAXT];
int mi[MAXT],ma[MAXT];
long long num[MAXT],sum[MAXT];
void prepare(){
    for(int i=0;i<MAXT;++i){
        num[i]=0;
        sum[i]=0;
        mi[i]=oo;
        ma[i]=-oo;
        rt[i]=0;
    }
}
struct Node{
    int lazy;
    int v;
    int l,r;
    int h;
};
Node t[MAX_NODES];
int tot=0;
int maxt=0;
void check(int i){
    return;
    if(!rt[i])return;
    if(t[rt[i]].v+t[rt[i]].lazy!=ma[i]){
        cerr<<i<<" "<<ma[i]<<" "<<t[rt[i]].v+t[rt[i]].lazy<<endl;
    }
}
int getNode(int p){
    if(p==0)return p;
    if(p>maxt)return p;
    int id=++tot;
    t[id]=t[p];
    return id;
}
int getId(int v){
    int r=mp[v];
    if(r==0)mp[v]=r=++idx;
    return r;
}
int pushDown(int A){
    if(t[A].lazy){
        A=getNode(A);
        Node&nA=t[A];
        nA.v+=nA.lazy;
        if(nA.l){
            nA.l=getNode(nA.l);
            t[nA.l].lazy+=nA.lazy;
        }
        if(nA.r){
            nA.r=getNode(nA.r);
            t[nA.r].lazy+=nA.lazy;
        }
        nA.lazy=0;
    }
    return A;
}
int merge(int A,int B){
    if(!A||!B)return A+B;
    A=pushDown(A);
    B=pushDown(B);
    if(t[A].v<t[B].v)swap(A,B);
    A=getNode(A);
    Node&nA=t[A];
    nA.r=merge(nA.r,B);
    if(t[nA.r].h>t[nA.l].h)swap(nA.l,nA.r);
    nA.h=t[nA.r].h+1;
    return A;
}
int copyMinus(int root,int delta){
    if(!root)return 0;
    int id=++tot;
    t[id]=t[root];
    t[id].lazy-=delta;
    return id;
}
void A(int i){cout<<num[i]<<endl;}
void B(int i){cout<<sum[i]<<endl;}
void C(int i){cout<<ma[i]<<endl;}
void D(int i){cout<<mi[i]<<endl;}
void E(int i,int x){
    maxt=tot;
    int id=++tot;
    t[id].v=x;
    t[id].h=1;
    rt[i]=merge(rt[i],id);
    ++num[i];
    sum[i]+=x;
    mi[i]=min(mi[i],x);
    ma[i]=max(ma[i],x);
}
void F(int i,int x){
    maxt=tot;
    if(rt[i]){
        rt[i]=getNode(rt[i]);
        t[rt[i]].lazy+=x;
    }
    if(num[i]>0){
        sum[i]+=(long long)x*num[i];
        mi[i]+=x;
        ma[i]+=x;
    }
}
void J(int i,int j,int k,int x){
    maxt=tot;
    if(num[i]<=0)return;
    int t1=k;
    int A=rt[i];
    int R=0,X=copyMinus(A,x),y=x;
    while(t1){
        if(t1&1){
            maxt=tot;
            R=merge(copyMinus(R,y),X);
        }
        maxt=tot;
        X=merge(copyMinus(X,y),X);
        y=y+y;
        t1>>=1;
    }
    maxt=tot;
    rt[j]=merge(rt[j],R);
    num[j]+=k*num[i];
    sum[j]+=k*sum[i]-(long long)k*(k+1)/2*x*num[i];
    mi[j]=min(mi[j],mi[i]-k*x);
    ma[j]=max(ma[j],ma[i]-x);
    check(j);
}
int P(int i){
    maxt=tot;
    rt[i]=pushDown(rt[i]);
    int ret=t[rt[i]].v;
    rt[i]=merge(t[rt[i]].l,t[rt[i]].r);
    num[i]--;
    sum[i]-=ret;
    if(num[i])ma[i]=t[rt[i]].v+t[rt[i]].lazy;
    else{
        mi[i]=oo;
        ma[i]=-oo;
    }
    return ret;
}
void H(int i,int j){
    int x=P(i);
    //cerr<<"H"<<x<<endl;
    E(j,x);
    check(j);
}
void G(int i,int x){
    if(num[i]<=0)return;
    H(i,-1);
    F(i,x);
    H(-1,i);
}
void I(int i,int j,int x){
    J(i,j,1,x);
}
int main(){
    // freopen("shadow.in","r",stdin);
    // freopen("shadow.out","w",stdout);
    prepare();
    int n;
    cin>>n;
    for(int p=1;p<=n;++p){
        maxt=tot;
        char op;
        int i,j,k;
        long long x;
        cin>>op;
        //cerr<<"Step "<<p<<" "<<op<<endl;
        switch(op){
        case 'A':
            cin>>i;
            A(getId(i));
            break;
        case 'B':
            cin>>i;
            B(getId(i));
            break;
        case 'C':
            cin>>i;
            C(getId(i));
            break;
        case 'D':
            cin>>i;
            D(getId(i));
            break;
        case 'E':
            cin>>i>>x;
            E(getId(i),x);
            break;
        case 'F':
            cin>>i>>x;
            F(getId(i),x);
            break;
        case 'G':
            cin>>i>>x;
            G(getId(i),x);
            break;
        case 'H':
            cin>>i>>j;
            H(getId(i),getId(j));
            break;
        case 'I':
            cin>>i>>j>>x;
            I(getId(i),getId(j),x);
            break;
        case 'J':
            cin>>i>>j>>k>>x;
            J(getId(i),getId(j),k,x);
            break;
        default:;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAXT=50010;
const int oo=(int)1e19;
const int MAX_NODES=10100100;
map<int,int>mp;
int idx=0;
int root[MAXT];
int mi[MAXT],ma[MAXT];
long long num[MAXT],sum[MAXT];
void prepare(){
    for(int i=0;i<MAXT;++i){
        num[i]=0;
        sum[i]=0;
        mi[i]=oo;
        ma[i]=-oo;
        root[i]=0;
    }
}
struct Node{
    int lazy;
    int v;
    int l,r;
    int h;
};
Node ns[MAX_NODES];
int tot=0;
int threshold=0;
int createNode(){
    return ++tot;
}
void check(int i){
    return;
    if(!root[i])return;
    if(ns[root[i]].v+ns[root[i]].lazy!=ma[i]){
        cerr<<i<<" "<<ma[i]<<" "<<ns[root[i]].v+ns[root[i]].lazy<<endl;
    }
}
int getNode(int p){
    if(p==0)return p;
    if(p>threshold)return p;
    int nId=++tot;
    ns[nId]=ns[p];
    return nId;
}
int getId(int v){
    int r=mp[v];
    if(r==0)mp[v]=r=++idx;
    return r;
}
int pushDown(int A){
    if(ns[A].lazy){
        A=getNode(A);
        Node&nA=ns[A];
        nA.v+=nA.lazy;
        if(nA.l){
            nA.l=getNode(nA.l);
            ns[nA.l].lazy+=nA.lazy;
        }
        if(nA.r){
            nA.r=getNode(nA.r);
            ns[nA.r].lazy+=nA.lazy;
        }
        nA.lazy=0;
    }
    return A;
}
int merge(int A,int B){
    if(!A)return B;
    if(!B)return A;
    A=pushDown(A);
    B=pushDown(B);
    if(ns[A].v<ns[B].v)swap(A,B);
    A=getNode(A);
    Node&nA=ns[A];
    nA.r=merge(nA.r,B);
    if(ns[nA.r].h>ns[nA.l].h)swap(nA.l,nA.r);
    nA.h=ns[nA.r].h+1;
    return A;
}
int copyMinus(int root,int delta){
    if(!root)return 0;
    int nId=++tot;
    ns[nId]=ns[root];
    ns[nId].lazy-=delta;
    return nId;
}
void A(int i){cout<<num[i]<<endl;}
void B(int i){cout<<sum[i]<<endl;}
void C(int i){cout<<ma[i]<<endl;}
void D(int i){cout<<mi[i]<<endl;}
void E(int i,int x){
    threshold=tot;
    int nId=createNode();
    ns[nId].v=x;
    ns[nId].h=1;
    root[i]=merge(root[i],nId);
    ++num[i];
    sum[i]+=x;
    mi[i]=min(mi[i],x);
    ma[i]=max(ma[i],x);
}
void F(int i,int x){
    threshold=tot;
    if(root[i]){
        root[i]=getNode(root[i]);
        ns[root[i]].lazy+=x;
    }
    if(num[i]>0){
        sum[i]+=(long long)x*num[i];
        mi[i]+=x;
        ma[i]+=x;
    }
}
void J(int i,int j,int t,int x){
    threshold=tot;
    if(num[i]<=0)return;
    int t1=t;
    int A=root[i];
    int R=0,X=copyMinus(A,x),y=x;
    while(t1){
        if(t1&1){
            threshold=tot;
            R=merge(copyMinus(R,y),X);
        }
        threshold=tot;
        X=merge(copyMinus(X,y),X);
        y=y+y;
        t1>>=1;
    }
    threshold=tot;
    root[j]=merge(root[j],R);
    num[j]+=t*num[i];
    sum[j]+=t*sum[i]-(long long)t*(t+1)/2*x*num[i];
    mi[j]=min(mi[j],mi[i]-t*x);
    ma[j]=max(ma[j],ma[i]-x);
    check(j);
}
int P(int i){
    threshold=tot;
    //cerr<<"P "<<i<<endl;
    root[i]=pushDown(root[i]);
    //cerr<<"P x "<<ns[root[i]].v<<" "<<ns[root[i]].lazy<<endl;
    int ret=ns[root[i]].v;
    //cerr<<root[i]<<" "<<ns[root[i]].l<<" "<<ns[root[i]].r<<endl;
    root[i]=merge(ns[root[i]].l,ns[root[i]].r);
    //cerr<<root[i]<<endl;
    num[i]--;
    sum[i]-=ret;
    if(num[i])ma[i]=ns[root[i]].v+ns[root[i]].lazy;
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
        threshold=tot;
        char op;
        int i,j,t;
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
            cin>>i>>j>>t>>x;
            J(getId(i),getId(j),t,x);
            break;
        default:;
        }
    }
    return 0;
}
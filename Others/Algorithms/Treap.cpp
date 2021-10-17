#include "bits/stdc++.h"
using namespace std;
struct node{
    int v,h,l,r,s;
}t[100010];
int brand(){
    int ret=0;
    ret=(ret<<15)|(rand()&0x7fff);
    ret=(ret<<15)|(rand()&0x7fff);
    return ret;
}
void update(int p){
    t[p].s=t[t[p].l].s+t[t[p].r].s+1;
}
int merge(int L,int R){
    if(!L)return R;
    if(!R)return L;
    if(t[L].h<t[R].h){
        t[L].r=merge(t[L].r,R);
        update(L);
        return L;
    }else{
        t[R].l=merge(L,t[R].l);
        update(R);
        return R;
    }
}
void split(int u,int k,int&L,int&R){
    if(!u){
        L=R=0;
        return;
    }
    if(k>t[u].h){
        split(t[u].l,k,L,t[u].r);
        update(L);
    }else{
        split(t[u].r,k,t[u].l,R);
        update(R);
    }
}
int main(){
    srand(114514);
    return 0;
}
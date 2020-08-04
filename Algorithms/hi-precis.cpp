#include "bits/stdc++.h"
using namespace std;
#define MAXN 10010
struct num{
    int v[MAXN];
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
    for(int i=alen-1;i>=0;i--)a.v[i]=g[i];
}
void print(num a){
    int alen=len(a);
    for(int i=alen-1;i>=0;i--)cout<<a.v[i];
    cout<<endl;
}
num add(num a,num b){
    
}
int main(){
    
    return 0;
}
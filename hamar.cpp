#include "bits/stdc++.h"
using namespace std;
const long long N=500010;
long long n,a[N][5],siz[5][2]={{2,2},{4,1},{1,1},{2,2},{2,2}},shp[5][4][2]={
    {{1,1},{1,1}},{{1},{1},{1},{1},},{{1}},{{1,1},{1}},{{0,1},{1,1}}
},top=0;
void clear(long long u){
    for(register long long i=u;i<=top;i++){
        for(register long long j=0;j<5;j++){
            a[i][j]=a[i+1][j];
        }
    }
    top--;
}
void put(long long t,long long l,long long c){
    long long p=0;
    for(p=top+10;p>=0;p--){
        long long flag=0;
        for(register long long i=0;i<siz[t][0];i++){
            for(register long long j=0;j<siz[t][1];j++){
                if(shp[t][i][j]&&a[p+i][l+j]!=-1){
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
        flag=flag;
        if(flag)break;
    }
    p++;
    top=max(siz[t][0]+p-1,top);
    for(register long long i=0;i<siz[t][0];i++){
        for(register long long j=0;j<siz[t][1];j++){
            if(shp[t][i][j])a[p+i][l+j]=c;
        }
    }
    for(register long long i=top;i>=0;i--){
        long long flag=0;
        for(register long long j=0;j<5;j++){
            if(a[i][j]==-1)flag=1;
        }
        if(!flag)clear(i);
    }
}
void print(){
    for(register long long i=top;i>=0;i--){
        for(register long long j=0;j<5;j++){
            if(a[i][j]==-1)cout<<" ";
            else cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    memset(a,-1,sizeof(a));
    for(register long long i=1;i<=n;i++){
        long long t,l,c;
        cin>>t>>l>>c;
        put(t-1,l-1,c);
    }
    print();
    return 0;
}
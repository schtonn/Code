#include "bits/stdc++.h"
using namespace std;
int n,na,nb,a[1010],b[1010],ans,bns;
bool s[5][5]={
    {0,0,1,1,0},
    {1,0,0,1,0},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {1,1,0,0,0}
};
int main(){
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        int ak=a[i%na],bk=b[i%nb];
        if(ak==bk)continue;
        if(s[ak][bk])ans++;
        else bns++;
    }
    cout<<ans<<' '<<bns<<endl;
    return 0;
}
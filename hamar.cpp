//https://www.luogu.com.cn/record/44718759
#include "bits/stdc++.h"
using namespace std;
const int N=1000010;
int n,m,pat[N],txt[N];
vector<int>pos[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>pat[i];
        pos[pat[i]].push_back(i);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int L,p=0,flag=0;
        cin>>L;
        for(int j=1;j<=L;j++)cin>>txt[j];
        for(int j=1;j<=L;j++){
            vector<int>::iterator t=upper_bound(pos[txt[j]].begin(),pos[txt[j]].end(),p);
            if(pos[txt[j]].end()==t){
                flag=1;
                cout<<"NIE"<<endl;
                break;
            }else p=*t;
        }
        if(!flag)cout<<"TAK"<<endl;
    }
    return 0;
}
/*
必做：P1419，P2115，P3500，CF732D，P2985，CF359D
其他：P4951，P3576，CF553D，P2218
*/
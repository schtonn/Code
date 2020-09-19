#include "bits/stdc++.h"
using namespace std;
int n,way,price,t,ans;
struct ticket{
    int p,t;
};
queue<ticket>q;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>way>>price>>t;
        while(t-q.front().t>45&&!q.empty())q.pop();
        if(way){
            if(!q.empty()){
                int ql=q.size();
                bool usd=0;
                for(int j=0;j<ql;j++){
                    if(!usd&&q.front().p>=price){
                        q.pop();
                        usd=1;
                    }else{
                        q.push(q.front());
                        q.pop();
                    }
                }
                if(usd==0)ans+=price;
            }else{
                ans+=price;
            }
        }else{
            ticket a;
            a.t=t;
            a.p=price;
            q.push(a);
            ans+=price;
        }
    }
    cout<<ans<<endl;
    return 0;
}
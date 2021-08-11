#include "bits/stdc++.h"
using namespace std;
int main(){
    long long n,m;
    char c[100];
    cin>>n>>m>>c;
    freopen(c,"w",stdout);
    srand(time(NULL));
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<((long long)rand()*rand()*rand())%m<<' ';
    }
    return 0;
}
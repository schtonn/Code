#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("hamar.in","w",stdout);
    srand(time(NULL));
    cout<<1000<<endl;
    for(int i=0;i<1000;i++){
        cout<<rand()%200<<' ';
    }
    return 0;
}
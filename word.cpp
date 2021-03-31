#include "bits/stdc++.h"
using namespace std;
int main(){
    srand(1919810);
    freopen("a.txt","w",stdout);
    for(int i=1;i<=10000;i++){
        cout<<rand()%10;
    }
    cout<<endl;
    freopen("b.txt","w",stdout);
    for(int i=1;i<=10000;i++){
        cout<<rand()%10;
    }
    cout<<endl;
    return 0;
}
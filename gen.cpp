#include "bits/stdc++.h"
using namespace std;
int main(){
    srand(time(NULL));
    cout<<1000<<endl;
    for(int i=1;i<=1000;i++){
        cout<<(char)(rand()%7+'a');
    }
    cout<<endl<<1000<<endl;
    for(int i=1;i<=1000;i++){
        int a=rand()%1000+1,b=rand()%1000+1;
        if(a>b)swap(a,b);
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}
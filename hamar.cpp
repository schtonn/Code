#include "bits/stdc++.h"
using namespace std;
int a[100010],n;
void qs(int l,int r){
    int i=l,j=r;
    if(i<j){
        int p=a[i];
        while (i!=j){
            while(j>i&&a[j]>p)--j;
            a[i]=a[j];
            while(i<j&&a[i]<=p)++i;
            a[j]=a[i];
        }
        a[i]=p;
        qs(l,i-1);
        qs(i+1,r);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qs(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
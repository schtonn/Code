#include"bits/stdc++.h"
using namespace std;
int len,rad[2000020];
int maxid,maxr;
char fakes[1000010],s[2000020];
// inline int min( int a, int b ){
//     return a < b ? a : b;
// }

int main(){
    cin>>fakes;
    len=strlen(fakes);
    for(int i=0;i<=len*2;i+=2){
        s[i]='#';
        s[i+1]=fakes[(i+1)/2];
    }
    len=strlen(s);
    int l=0,r=-1;//区间边界
    for(int i=0;i<len;i++){
        int k;
        if(i>r)k=1;
        else k=min(rad[l+r-i],r-i);
        while(0<=i-k && i+k<len && s[i-k]==s[i+k]){
            k++;
        }
        //k表示回文串半径
        rad[i]=k--;
        //k表示到边界的距离
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
        if(rad[i]>maxr){
            maxid=i;
            maxr=rad[i];
        }
    }
    int ans=rad[maxid]-1;
    for(int i=maxid-ans;i<=maxid+ans;i++){
        if(s[i]!='#')cout<<s[i];
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define N 110
string s;
int dp[N][N],len;
int main(){
    memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=0;i<len;i++)dp[i][i]=0;
    cin>>s;
    len=s.length();
    for(int add=0;add<len;add++){
        for(int base=0;base<len;base++){
            int l=base,r=base+add;
            if(s[l]==s[r]){
                if(add>1)dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
                else dp[l][r]=0;
            }
            dp[l][r]=min(dp[l][r],min(dp[l+1][r]+1,dp[l][r-1]+1));
            if(add>1)dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
            else dp[l][r]=min(dp[l][r],1);
        }
    }
    cout<<dp[0][len-1]<<endl;
    return 0;
}
/*

*/
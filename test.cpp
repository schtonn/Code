#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
int n, m, e[25][25];
int g[N][25], dp[N][25]; //dp[i][j]表示状态为i，现在在j点的路径长
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        e[u][v] = 1;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (int i = 1; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            if (i & (1 << (j - 1))){
                for (int k = 0; k < n; k++){
                    if ((i & (1 << (k - 1))) && (dp[i ^ (1 << (j - 1))][k]) && e[i][j]){
                        dp[i][j] = min(dp[i][j], dp[i ^ 1 << j][k] + e[k][j]);
                        g[i][j] = (dp[i][j] < dp[i ^ 1 << j][k] + e[k][j]) ? i : (i ^ 1 << j);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}
/*
| | | | | |
| |-| | | |
| |-| | |-|
|-| |-|-| |
|-| | |-|-|
| | |-|-| |
|-| | | |-|
===========
|0|1|2|3|4|

| | | | | |**************| | | | | |
|-| |-| | |**************| | |-| |-|
| |-| | | |**************|-| | | | |
|-| | |-| |****Random****| | | |-|-|
| |-| | | |=============>|-| | | | |
|-|-| | | |**************|-| | | |-|
|-| | | | |**************| | | | |-|
| |-| |-|-|**************|-|-| |-| |
===========**************===========
|0|1|2|3|4|**************|0|1|2|3|4|
*/
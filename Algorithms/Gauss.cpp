#include "bits/stdc++.h"
using namespace std;
#define N 20
double a[N][N];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i][n];
    }
    for(int i=0;i<n;i++){
        int r=i;
        for(int j=i;j<n;j++){
            if(fabs(a[j][i]>fabs(a[r][i])))r=j;
        }
        for(int j=0;j<=n;j++){
            swap(a[r][j],a[i][j]);
        }
        for(int j=i+1;j<=n;j++){
            a[i][j]/=a[i][i];
        }
        for(int j=0;j<n;j++){
            if(i!=j){
                for(int k=i+1;k<=n;k++){
                    a[j][k]-=a[j][i]*a[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%.2lf\n",a[i][n]);
    }
    return 0;
}
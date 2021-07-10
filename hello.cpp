#include "bits/stdc++.h"
using namespace std;
int n,m,tot,ans,d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node{
    bool a[10][10];
    bool operator<(const node p)const{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=ceil((double)n/2);j++){
                if(a[i][j]!=p.a[i][j])return a[i][j]<p.a[i][j];
            }
        }
        return a[n][(int)ceil((double)n/2)]<p.a[n][(int)ceil((double)n/2)];
    }
    void print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j<=ceil((double)n/2))cout<<!a[i][j]<<' ';
                else cout<<!a[n-i+1][2*(int)ceil((double)n/2)-j-(n%2)+1]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}k;
map<node,int>mp;
bool check(node c){
    for(int i=1;i<=n;i++){
        int j=ceil((double)n/2);
        if(c.a[i][j]!=c.a[n-i+1][j])return 0;
    }
    return 1;
}
void dfs(node c,int x,int y,int step){
    if(mp.count(c)||x>n||y>ceil((double)n/2)||x<1||y<1)return;
    if(check(c))c.print(),ans++;
    mp[c]=tot++;
    for(int i=0;i<4;i++){
        int dx=x+d[i][0],dy=y+d[i][1];
        int flag=c.a[dx][dy];
        c.a[dx][dy]=1;
        dfs(c,dx,dy,step+1);
        c.a[dx][dy]=flag;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=ceil((double)n/2);j++){
            k.a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int j=ceil((double)n/2);
        k.a[i][j]=1;
        dfs(k,i,j,0);
        k.a[i][j]=0;
    }
    cout<<ans+1<<endl;
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
int x,y,ans;
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
void theFatUglyLargeWizardishDepthFirstSearch(vector<string> chess,int step){
    if(step>10||step>=ans)return;
    int ax=-1,bx=-1,ay=-1,by=-1;
    int axN=-1,bxN=-1,ayN=-1,byN=-1;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(chess[i][j]=='o'&&ax==-1){
                ax=i;ay=j;
                continue;
            }
            else if(chess[i][j]=='o'&&ax!=-1){
                bx=i;by=j;
                break;
            }
        }
    }
    for(int i=0;i<4;i++){
        int tmp_r=ax+dirx[i];
        int tmp_c=ay+diry[i];
        bool moved=false;
        int counter=0;
        if(tmp_r<0||tmp_r>=x||tmp_c<0||tmp_c>=y){
            counter++;
        }
        tmp_r=bx+dirx[i];
        tmp_c=by+diry[i];
        if(tmp_r<0||tmp_r>=x||tmp_c<0||tmp_c>=y){
            counter++;
        }
        if(counter==1){
            if(step<ans)ans=step;
            return;
        }
        if(counter==2)continue;
        tmp_r=ax+dirx[i];
        tmp_c=ay+diry[i];
        if(tmp_r>=0&&tmp_r<x&&tmp_c>=0&&tmp_c<y&&chess[tmp_r][tmp_c]!='#'){
            axN=tmp_r;
            ayN=tmp_c;
            moved=true;
        }
        else{
            axN=ax;
            ayN=ay;
        }
        tmp_r=bx+dirx[i];
        tmp_c=by+diry[i];
        if(tmp_r>=0||tmp_r<x||tmp_c>=0||tmp_c<y){
            counter++;
        }
        if(tmp_r>=0&&tmp_r<x&&tmp_c>=0&&tmp_c<y&&chess[tmp_r][tmp_c]!='#'){
            bxN=tmp_r;
            byN=tmp_c;
            moved=true;
        }
        else{
            bxN=bx;
            byN=by;
        }
        if(axN==bxN&&ayN==byN)continue;
        if(moved==false)continue;
        vector<string>chN=chess;
        chN[ax][ay]='.';
        chN[bx][by]='.';
        chN[axN][ayN]='o';
        chN[bxN][byN]='o';
        theFatUglyLargeWizardishDepthFirstSearch(chN,step+1);
    }
}

int theExterierOfTheFatUglyLargeWizardishDepthFirstSearch(vector <string> chess) {	
    x=chess.size();
    y=chess[0].size();
    ans=50;
    theFatUglyLargeWizardishDepthFirstSearch(chess,1);
    if(ans>10)return -1;
    return ans;
}
vector<string>chess;
int main(){
    freopen("CoinsGameEasy.in","r",stdin);
    freopen("CoinsGameEasy.out","w",stdout);
    cin>>x>>y;
    string theSmartTempOfInput;
    for(int i=0;i<x;i++){
        cin>>theSmartTempOfInput;
        chess.push_back(theSmartTempOfInput);
    }
    cout<<theExterierOfTheFatUglyLargeWizardishDepthFirstSearch(chess)<<endl;
    system("pause");
}
#include "bits/stdc++.h"

using namespace std;


int row,col;
int ans;


void dfs(vector<string> board,int step){
    int dir_row[]={0,0,1,-1};
    int dir_col[]={1,-1,0,0};
    if(step>10 || step>=ans)return;
    int r1=-1,r2=-1,c1=-1,c2=-1;
    int r1_new=-1,r2_new=-1,c1_new=-1,c2_new=-1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='o' && r1==-1){
                r1=i; c1=j;
                continue;
            }
            else if(board[i][j]=='o' && r1!=-1){
                r2=i; c2=j;
                break;
            }
        }
    }
    for(int i=0;i<4;i++){
        int tmp_r=r1+dir_row[i];
        int tmp_c=c1+dir_col[i];
        bool moved=false;
        int counter=0;
        if(tmp_r<0 || tmp_r>=row || tmp_c<0 || tmp_c>=col ){
            counter++;
        }
        tmp_r=r2+dir_row[i];
        tmp_c=c2+dir_col[i];
        if(tmp_r<0 || tmp_r>=row || tmp_c<0 || tmp_c>=col ){
            counter++;
        }
        if(counter==1){
            if(step<ans)
                ans=step;
            return;
        }
        if(counter==2)
            continue;

        tmp_r=r1+dir_row[i];
        tmp_c=c1+dir_col[i];
        if(tmp_r>=0 && tmp_r<row && tmp_c>=0 && tmp_c<col 
            && board[tmp_r][tmp_c]!='#'){
                r1_new=tmp_r; c1_new=tmp_c; moved=true;
        }
        else{
            r1_new=r1; c1_new=c1;
        }

        tmp_r=r2+dir_row[i];
        tmp_c=c2+dir_col[i];
        if(tmp_r>=0 || tmp_r<row || tmp_c>=0 || tmp_c<col ){
            counter++;
        }
        if(tmp_r>=0 && tmp_r<row && tmp_c>=0 && tmp_c<col 
            && board[tmp_r][tmp_c]!='#'){
                r2_new=tmp_r; c2_new=tmp_c; moved=true;
        }
        else{
            r2_new=r2; c2_new=c2;
        }
        
        if(r1_new==r2_new && c1_new==c2_new)
            continue;
        if(moved==false)
            continue;
        vector<string> boa=board;
        boa[r1][c1]='.'; boa[r2][c2]='.';
        boa[r1_new][c1_new]='o'; boa[r2_new][c2_new]='o';
        dfs(boa,step+1);
    }
}

int minimalSteps(vector <string> board) {	
    row=board.size();
    col=board[0].size();
    ans=50;
    dfs(board,1);
    if(ans>10)
        return -1;
    return ans;
}
vector<string>board;
int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>board[i];
    }
}
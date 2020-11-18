#include "bits/stdc++.h"
using namespace std;
int n,len,weigh[10010],elecnt;
string s,l,r,elem[10010];
bool num(char x){return '0'<=x&&x<='9';}
bool alp(char x){return 'a'<=x&&x<='z';}
bool Alp(char x){return 'A'<=x&&x<='Z';}
void eleme(string s,int coef){//元素计算
//    cout<<"element: "<<s<<' '<<coef<<endl;
    for(int i=0;i<elecnt;i++){
        if(elem[i]==s){
            weigh[i]+=coef;
            return;
        }
    }
    elem[elecnt]=s;
    weigh[elecnt++]=coef;
}
bool formu(string s,int coef){//分元素
//    cout<<"formula: "<<s<<' '<<coef<<endl;
    int len=s.length(),layer,ncoef=0,start,end;
    string newele;
    for(int i=0;i<len;i++){
        if(s[i]=='('){//有括号，直接下放
            start=i+1;
            layer=1;
            while(layer){
                i++;
                if(s[i]=='(')layer++;
                if(s[i]==')')layer--;
            }
            end=i;
            if(num(s[i+1])){
                i++;
                while(num(s[i])){
                    if(i!=0)ncoef*=10;
                    ncoef+=s[i]-'0';
                    i++;
                }
                i--;
            }
            if(ncoef==0)ncoef=1;
            formu(s.substr(start,end-start),coef*ncoef);
            ncoef=0;
        }else{//没括号，一个一个分元素
            newele=s[i];
            if(!Alp(s[i])){
                cout<<"Error: Invalid element"<<endl;
                return 1;
            }
            if(alp(s[i+1])){//考虑两个字母
                newele+=s[i+1];
                i++;
            }
            if(num(s[i+1])){
                i++;
                while(num(s[i])){
                    ncoef*=10;
                    ncoef+=s[i]-'0';
                    i++;
                }
                i--;
            }
            if(ncoef==0)ncoef=1;
            eleme(newele,coef*ncoef);
            ncoef=0;
        }
    }
    return 0;
}
bool subexpr(string s,int coef){//分系数
    int len=s.length(),ncoef=0,pos=0;
    if(num(s[0])){
        while(num(s[pos])){
            if(pos!=0)ncoef*=10;
            ncoef+=s[pos]-'0';
            pos++;
        }
    }
    if(ncoef==0)ncoef=1;
    if(s.substr(pos,len-pos)==""){
        cout<<"Error: Invalid element"<<endl;
        return 1;
    }
    if(formu(s.substr(pos,len-pos),coef*ncoef))return 1;
    return 0;
}
bool expr(string s,int coef){//分加号
    int len=s.length(),pos=0;
    for(int i=0;i<len;i++){
        if(s[i]=='+'){
            if(subexpr(s.substr(pos,i-pos),coef))return 1;
            pos=i+1;
        }
    }
    if(subexpr(s.substr(pos,len-pos),coef))return 1;
    return 0;
}
int main(){
//    cin>>n;
    while(true){
        memset(weigh,0,sizeof(weigh));
        elecnt=0;
        cin>>s;
        len=s.length();
        int eq=0;
        for(int j=0;j<len;j++){
            if(s[j]=='='){
                if(expr(s.substr(0,j),1)||expr(s.substr(j+1,len-j),-1))goto err;
                eq++;
            }
        }
        if(eq!=1){
            cout<<"Error: Invalid Equal"<<endl;
            err:
            continue;
        }
        int flag=0;
        for(int i=0;i<elecnt;i++){
            if(weigh[i])flag=1;
        }
        if(flag)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
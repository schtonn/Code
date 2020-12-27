#include "bits/stdc++.h"
using namespace std;
#define maxe 1010
#define ELM 119

//INIT

int n,len,weigh[maxe];
int E;//element count
int M;//molecule count
int rf;//first of right
bool err=0;
string chart[ELM]={"",
    "H","He",

    "Li","Be","B","C","N","O","F","Ne",

    "Na","Mg","Al","Si","P","S","Cl","Ar",

    "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",

    "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",

    "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf",
    "Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",

    "Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf",
    "Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og",
};
string s,l,r,e[maxe];
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
bool num(char x){return '0'<=x&&x<='9';}
bool alp(char x){return 'a'<=x&&x<='z';}
int m[maxe][maxe],ans[maxe],cm[maxe];

//DIVIDING & CALCULATING

void eleme(string s,int coef,int ncoef){//single element
    //cout<<"element: "<<s<<' '<<coef<<endl;
    if(err==0){
        err=1;
        for(int i=1;i<ELM;i++){
            if(s==chart[i])err=0;
        }
    }
    for(int i=0;i<E;i++){
        if(e[i]==s){
            m[M][i]+=coef;
            weigh[i]+=coef;
            return;
        }
    }
    e[E]=s;
    m[M][E]=coef;
    weigh[E++]=coef;
}
void formu(string s,int coef){//single molecule
//    cout<<"formula: "<<s<<' '<<coef<<endl;
    int len=s.length(),layer,ncoef=0,start,end;
    string newele;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
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
        }else{
            newele=s[i];
            if(alp(s[i+1])){
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
            eleme(newele,coef*ncoef,ncoef);
            ncoef=0;
        }
    }
}
void subexpr(string s,int coef){//coefficient
    int len=s.length(),ncoef=0,pos=0;
    if(num(s[0])){
        while(num(s[pos])){
            if(pos!=0)ncoef*=10;
            ncoef+=s[pos]-'0';
            pos++;
        }
    }
    if(ncoef==0)ncoef=1;
    cm[M]=ncoef;
    formu(s.substr(pos,len-pos),coef*ncoef);
}
void expr(string s,int coef){//expressions
    int len=s.length(),pos=0;
    for(int i=0;i<len;i++){
        if(s[i]=='+'){
            subexpr(s.substr(pos,i-pos),coef);
            M++;
            pos=i+1;
        }
    }
    subexpr(s.substr(pos,len-pos),coef);
    M++;
}

//BALANCING

void reduce(int x){
    int cnt=0;
    int div=m[x][0];
    for(int i=0;i<E;i++){
        if(m[x][i]){
            div=gcd(div,m[x][i]);
            cnt++;
        }
    }
    if(cnt<=1)return;
    for(int i=0;i<E;i++){
        m[x][i]/=div;
    }
}
void balance(){
    for(int i=0;i<M;i++){
        for(int j=0;j<E;j++){
            if(m[i][j]<0){
                if(!rf)rf=i;
                m[i][j]=-m[i][j];
            }
        }
    }
    for(int i=0;i<M;i++){
        //reduce(i);
        for(int j=0;j<E;j++){
            m[i][j]/=cm[i];
        }
    }
    for(int i=0;i<E;i++){
        int l=0,r=0;
        for(int j=0;j<rf;j++)l+=m[j][i]*ans[j];
        for(int j=rf;j<M;j++)r+=m[j][i]*ans[j];
        int div=gcd(l,r);
        l/=div;
        r/=div;
        swap(l,r);
        for(int j=0;j<rf;j++)/*if(m[j][i])*/ans[j]*=l;
        for(int j=rf;j<M;j++)/*if(m[j][i])*/ans[j]*=r;
    }
    int div=ans[0];
    for(int i=0;i<M;i++){
        div=gcd(ans[i],div);
    }
    for(int i=0;i<M;i++){
        ans[i]/=div;
    }
}

//HELPERS

void clean(){
    M=0;
    err=0;
    for(int i=0;i<maxe;i++){
        for(int j=0;j<maxe;j++){
            m[i][j]=0;
        }
        ans[i]=1;
    }
}
void help(){
    cout<<"Formatting:"<<endl;
    cout<<"<equation> ::= <expr> \"=\" <expr>"<<endl;
    cout<<"<expr> ::= <coef> <formula> | <expr> \"+\" <coef> <formula>"<<endl;
    cout<<"<coef> ::= <digits> | \"\""<<endl;
    cout<<"<digits> ::= <digit> | <digits> <digit>"<<endl;
    cout<<"<digit> ::= \"0\" | \"1\" | ... | \"9\""<<endl;
    cout<<"<formula> ::= <term> <coef> | <formula> <term> <coef>"<<endl;
    cout<<"<term> ::= <element> | \"(\" <formula> \")\""<<endl;
    cout<<"<element> ::= <uppercase> | <uppercase> <lowercase>"<<endl;
    cout<<"<uppercase> ::= \"A\" | \"B\" | ... | \"Z\""<<endl;
    cout<<"<lowercase> ::= \"a\" | \"b\" | ... | \"z\""<<endl<<endl;
    cout<<"The program requires an chemical equation(<equation>) and outputs the state of the equation. An equation should be settled as above, or the program may not work properly."<<endl;
    cout<<"\"Y\" means this equation is balanced."<<endl;
    cout<<"\"N\" means this equation is unbalanced."<<endl;
    cout<<"\"unknown elemet\" means this equation contains an unknown element that has not yet be discovered by humanity, or you are inputting illigal equations."<<endl<<endl;
    cout<<"help\tProvides Help information."<<endl;
    cout<<"exit\tQuits the program."<<endl<<endl;
    cout<<"Warning: This program supports up to 1000 expressions with 1000 elements, but no more."<<endl;
}
void print(){
    for(int i=0;i<rf;i++){
        if(ans[i]!=1)cout<<ans[i];
        for(int j=0;j<E;j++){
            if(m[i][j]){
                cout<<e[j];
                if(m[i][j]!=1)cout<<m[i][j];
            }
        }
        if(i!=rf-1)cout<<'+';
    }
    cout<<'=';
    for(int i=rf;i<M;i++){
        if(ans[i]!=1)cout<<ans[i];
        for(int j=0;j<E;j++){
            if(m[i][j]){
                cout<<e[j];
                if(m[i][j]!=1)cout<<m[i][j];
            }
        }
        if(i!=M-1)cout<<'+';
    }
    cout<<endl;
}


int main(){
    while(true){
        clean();
        cout<<"Chemical>";
        memset(weigh,0,sizeof(weigh));
        E=0;
        cin>>s;
        if(s=="help"){
            help();
            continue;
        }
        if(s=="exit"){
            break;
        }
        len=s.length();
        for(int j=0;j<len;j++){
            if(s[j]=='='){
                expr(s.substr(0,j),1);
                expr(s.substr(j+1,len-j),-1);
            }
        }
        int flag=0;
        for(int i=0;i<E;i++){
            if(weigh[i])flag=1;
        }
        if(err==1)cout<<"unknown element"<<endl;
        else{
            if(flag){
                cout<<"N"<<endl;
                balance();
                print();
            }
            else cout<<"Y"<<endl;
        }
    }
    system("pause");
    return 0;
}
/*
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au
*/
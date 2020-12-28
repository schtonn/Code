#include "bits/stdc++.h"
using namespace std;
#define maxe 1010
#define ELM 119

//INIT

int n,len,weigh[maxe];
int E,lE,rE;//element count
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
bool isNum(char x){return '0'<=x&&x<='9';}
bool isAlpha(char x){return 'a'<=x&&x<='z';}
int m[maxe][maxe],ans[maxe],cm[maxe];

//DIVIDING & CALCULATING

void eleme(string s,int c,int newC){//single element
    //cout<<"element: "<<s<<' '<<c<<endl;
    if(err==0){
        err=1;
        for(int i=1;i<ELM;i++)if(s==chart[i])err=0;
    }
    for(int i=0;i<E;i++){
        if(e[i]==s){
            m[M][i]+=c;
            weigh[i]+=c;
            return;
        }
    }
    e[E]=s;
    m[M][E]=c;
    weigh[E++]=c;
}
void formu(string s,int c){//single molecule
//    cout<<"formula: "<<s<<' '<<c<<endl;
    int len=s.length(),layer,newC=0,start,end;
    string newS;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            start=i+1;layer=1;
            while(layer){
                i++;
                if(s[i]=='(')layer++;
                if(s[i]==')')layer--;
            }
            end=i;
            if(isNum(s[i+1])){
                i++;
                while(isNum(s[i])){
                    if(i!=0)newC*=10;
                    newC+=s[i]-'0';
                    i++;
                }
                i--;
            }
            if(newC==0)newC=1;
            formu(s.substr(start,end-start),c*newC);
        }else{
            newS=s[i];
            if(isAlpha(s[i+1])){
                newS+=s[i+1];
                i++;
            }
            if(isNum(s[i+1])){
                i++;
                while(isNum(s[i])){
                    newC*=10;
                    newC+=s[i]-'0';
                    i++;
                }
                i--;
            }
            if(newC==0)newC=1;
            eleme(newS,c*newC,newC);
        }
        newC=0;
    }
}
void subExpr(string s,int c){//cficient
    int len=s.length(),newC=0,pos=0;
    if(isNum(s[0])){
        while(isNum(s[pos])){
            if(pos!=0)newC*=10;
            newC+=s[pos]-'0';
            pos++;
        }
    }
    if(newC==0)newC=1;
    cm[M]=newC;
    formu(s.substr(pos,len-pos),c*newC);
}
void expr(string s,int c){//expressions
    int len=s.length(),pos=0;
    for(int i=0;i<len;i++){
        if(s[i]=='+'){
            subExpr(s.substr(pos,i-pos),c);
            M++;
            pos=i+1;
        }
    }
    subExpr(s.substr(pos,len-pos),c);
    M++;
}

//BALANCING

void pre(){
    for(int i=0;i<M;i++){
        for(int j=0;j<E;j++){
            if(m[i][j]<0){
                if(!rf)rf=i;
                m[i][j]=-m[i][j];
            }
        }
    }
}
bool lrBalance(){
	bool l[1010],r[1010];
	int lcnt=0,rcnt=0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=0;i<rf;i++){
		for(int j=0;j<E;j++){
			if(m[i][j])l[j]=1;
		}
	}
	for(int i=rf;i<M;i++){
		for(int j=0;j<E;j++){
			if(m[i][j])r[j]=1;
		}
	}
	for(int i=0;i<E;i++){
		if(l[i])lcnt++;
		if(r[i])rcnt++;
	}
	if(lcnt!=rcnt)return false;
	return true;
}
bool dfs(){

}
bool balancable(){
	return lrBalance();
}
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
void declare(bool t){
    if(t){
        cout<<"4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH"<<endl<<endl;
    }else{
        cout<<"\t<equation> ::= <expr> \"=\" <expr>"<<endl;
        cout<<"\t<expr> ::= <c> <formula> | <expr> \"+\" <c> <formula>"<<endl;
        cout<<"\t<c> ::= <digits> | \"\""<<endl;
        cout<<"\t<digits> ::= <digit> | <digits> <digit>"<<endl;
        cout<<"\t<digit> ::= \"0\" | \"1\" | ... | \"9\""<<endl;
        cout<<"\t<formula> ::= <term> <c> | <formula> <term> <c>"<<endl;
        cout<<"\t<term> ::= <element> | \"(\" <formula> \")\""<<endl;
        cout<<"\t<element> ::= <uppercase> | <uppercase> <lowercase>"<<endl;
        cout<<"\t<uppercase> ::= \"A\" | \"B\" | ... | \"Z\""<<endl;
        cout<<"\t<lowercase> ::= \"a\" | \"b\" | ... | \"z\""<<endl<<endl;
    }
}
void help(){
    cout<<"INPUT"<<endl;
    cout<<"The program requires an chemical equation(<equation>) and outputs wether it is balanced. An equation should be settled as below, or the program may not work properly."<<endl;
    declare(0);
    cout<<"For example: ";
    declare(1);
    cout<<"OUTPUT"<<endl;
    cout<<"\"Y\" means this equation is balanced."<<endl;
    cout<<"\"N\" means this equation is unbalanced."<<endl;
    cout<<"\"unknown elemet\" means this equation contains an unknown element that has not yet be discovered by humanity, or you are inputting illigal equations."<<endl<<endl;
    cout<<"COMMANDS"<<endl;
    cout<<"help\tProvides Help information."<<endl;
    cout<<"exit\tQuits the program."<<endl<<endl;
    cout<<"Warning: This program supports up to 1000 expressions with 1000 elements, but no more."<<endl<<endl;
    cout<<"输入"<<endl;
    /*cout<<"程序输入一个化学式，并判断其是否配平。化学式的格式如下，不合法的化学式可能引起未定义行为。"<<endl;
    declare(0);
    cout<<"例如: ";
    declare(1);
    cout<<"输出"<<endl;
    cout<<"\"Y\" 代表化学式已配平。"<<endl;
    cout<<"\"N\" 代表化学式未配平。"<<endl;
    cout<<"\"unknown elemet\" 代表化学式中的某一元素还没有被发现，或者输入的化学式不合法。"<<endl<<endl;
    cout<<"指令"<<endl;
    cout<<"help\t提供帮助信息。"<<endl;
    cout<<"exit\t退出程序。"<<endl<<endl;
    cout<<"警告：此程序最多接受1000种元素，和1000个分子式，否则可能会引发未定义行为。"<<endl;*/ 
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
                pre(); 
                if(balancable()){
    	            balance();
    	            cout<<"Attempt to balance: ";
    	            print();
	                cout<<"Beware, the attempt will come out unsuccessful most of the times."<<endl;
	            }else{
	            	cout<<"Unable to balance."<<endl;
				}
            }
            else cout<<"Y"<<endl;
        }
    }
//    system("pause");
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

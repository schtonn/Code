#include "bits/stdc++.h"
using namespace std;
#define maxm 1010
#define E 119//element count
#define maxp 3

//******************INIT*****************//

int n,len,weigh[E];
int M;//molecule count
bool err=0;
int priv[E]={0,
    2,2,
    1,1,2,2,2,3,2,2,
    1,1,1,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
};
string e[E]={"",
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
string s;
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
bool isNum(char x){return '0'<=x&&x<='9';}
bool isAlpha(char x){return 'a'<=x&&x<='z';}

//******************DIVIDING & CALCULATING*****************//

int m[maxm][E],cm[E];
void eleme(string s,int c,int newC){//single element
    //cout<<"element: "<<s<<' '<<c<<endl;
    for(int i=0;i<E;i++){
        if(e[i]==s){
            m[M][i]+=c;
            weigh[i]+=c;
            return;
        }
    }
    err=1;
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
void subExpr(string s,int c){//coefficient
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

//******************BALANCING*****************//

int ans[E],vis[E];
int fR=-1;//first of right
void findCenter(){
    for(int i=0;i<M;i++){
        for(int j=0;j<E;j++){
            if(m[i][j]<0){
                if(fR==-1)fR=i;
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
	for(int i=0;i<fR;i++){
		for(int j=0;j<E;j++){
			if(m[i][j])l[j]=1;
		}
	}
	for(int i=fR;i<M;i++){
		for(int j=0;j<E;j++){
			if(m[i][j])r[j]=1;
		}
	}
	for(int i=0;i<E;i++){
		if(l[i]!=r[i])return false;
	}
    return true;
}
void down(){
    int div=ans[0];
    for(int i=0;i<M;i++){
        div=gcd(ans[i],div);
    }
    for(int i=0;i<M;i++){
        ans[i]/=div;
    }
}
bool balanceProcess(int k,int step){
    if(step>20)return false;
    down();
    int l=0,r=0;
    for(int i=0;i<fR;i++)l+=m[i][k]*ans[i];
    for(int i=fR;i<M;i++)r+=m[i][k]*ans[i];
    if(l==0&&r==0)return true;
    if(l==0||r==0)return false;
    int div=gcd(l,r);
    l/=div;
    r/=div;
    swap(l,r);
    if(l<0||r<0)return false;
    bool changed[E];
    memset(changed,false,sizeof(changed));
    for(int i=0;i<fR;i++)if(m[i][k]){
        ans[i]*=l;
        if(l!=1)changed[i]=true;
    }
    for(int i=fR;i<M;i++)if(m[i][k]){
        ans[i]*=r;
        if(r!=1)changed[i]=true;
    }
    for(int i=0;i<M;i++){
        if(changed[i]){
            for(int j=0;j<E;j++){
                if(m[i][j]&&j!=k){
                    if(!balanceProcess(j,step+1))return false;
                }
            }
        }
    }
    return true;
}
bool balance(){
    bool flag=true;
    for(int i=0;i<M;i++){
        for(int j=0;j<E;j++){
            m[i][j]/=cm[i];
        }
    }
    for(int i=0;i<E;i++){
        if(!balanceProcess(i,0))flag=false;
    }
    down();
    return lrBalance()&&flag;
}
bool forceBalance(int step){
    if(step>=M){
        memset(weigh,0,sizeof(weigh));
        for(int i=0;i<M;i++){
            for(int j=0;j<E;j++){
                if(m[i][j])weigh[j]+=m[i][j]*ans[i]*(i<fR?1:-1);
            }
        }
        for(int i=0;i<E;i++){
            if(weigh[i]!=0)return false;
        }
        return true;
    }
    for(int i=1;i<=30;i++){
        ans[step]=i;
        if(forceBalance(step+1)){
            return true;
        }
        ans[step]=0;
    }
    return false;
}

//******************HELPERS*****************//

void clean(){
    M=0;
    err=0;
    memset(weigh,0,sizeof(weigh));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<maxm;i++){
        for(int j=0;j<E;j++){
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
    cout<<"Warning: This program supports up to 119 expressions with 1000 elements, but no more."<<endl<<endl;
    /*cout<<"输入"<<endl;
    cout<<"程序输入一个化学式，并判断其是否配平。化学式的格式如下，不合法的化学式可能引起未定义行为。"<<endl;
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
    cout<<"警告：此程序最多接受119种元素，和1000个分子式，否则可能会引发未定义行为。"<<endl;*/ 
}
void P(int i,int j){
    cout<<e[j];
    if(m[i][j]!=1)cout<<m[i][j];
}
void printM(int k){
    int cnt=0,mcnt=0;
    for(int i=0;i<E;i++){
        if(m[k][i]){
            cnt++;
            if(priv[i]==1)mcnt++;
        }
    }
    if(cnt==2){
        int a=0,b=0;
        for(int i=0;i<E;i++){
            if(m[k][i]&&!a)a=i;
            else if(m[k][i])b=i;
        }
        if((a==1||b==1)&&!mcnt){
            if(b==1)swap(a,b);
            if(m[k][1]<3){
                P(k,1);P(k,b);
            }else{
                P(k,b);P(k,1);
            }
        }else{
            goto notHO;
        }
    }else{
        notHO:
        for(int p=1;p<=maxp;p++){
            for(int i=0;i<E;i++){
                if(m[k][i]&&priv[i]==p){
                    P(k,i);
                }
            }
        }
    }
}
void print(){
    for(int i=0;i<fR;i++){
        if(ans[i]!=1)cout<<ans[i];
        printM(i);
        if(i!=fR-1)cout<<'+';
    }
    cout<<'=';
    for(int i=fR;i<M;i++){
        if(ans[i]!=1)cout<<ans[i];
        printM(i);
        if(i!=M-1)cout<<'+';
    }
    cout<<endl;
}

//******************MAIN*****************//

int main(){
    while(true){
        clean();
        cout<<"Chemical>";
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
                break;
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
                findCenter(); 
                if(balance()){
    	            cout<<"Attempt to balance: ";
    	            print();
	                cout<<"Beware, the attempt will wipe out all the formatting, and it's not always succesful."<<endl;
	            }else{
	            	cout<<"Attempt to balance failed."<<endl;
                    cout<<"Do you want to try forcibly(may cause serious lag)?(Y/N)";
                    char YN;
                    cin>>YN;
                    if(toupper(YN)=='Y'){
                        memset(ans,1,sizeof(ans));
                        if(forceBalance(0))print();
                        else cout<<"Impossible within 30."<<endl;
                    }
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

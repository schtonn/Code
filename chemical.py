import math

eles=["H","He",
    "Li","Be","B","C","N","O","F","Ne",
    "Na","Mg","Al","Si","P","S","Cl","Ar",
    "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
    "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",

    "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf",
    "Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",

    "Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf",
    "Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"
]

priv=[2,2,
    1,1,2,2,2,3,2,2,
    1,1,1,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2
]

weigh=[0]*120
ans=[1]*120

m=[[0]*120 for i in range(1010)]
mc=0
err=0

def getc(s,pos):
    # print("getc",s,pos)
    s=s[pos:len(s)]
    ret=1
    for i in range(len(s)):
        if(s[0:i+1].isnumeric()):ret=int(s[0:i+1])
        if(not s[0:i+1].isnumeric()):break
    return ret

def ele(s,coef):
    # print("ele",s,coef)
    global weigh
    for i in eles:
        if(s==i):
            weigh[eles.index(i)]+=coef
            global mc,m
            m[mc][eles.index(i)]+=abs(coef)
            return
    global err
    err=1

def term(s,coef):
    # print("term",s,coef)
    i=0
    while i<len(s):
        if(s[i]=='('):
            sub=s.rfind(')')
            ncoef=getc(s,sub+1)
            pre=int(math.log10(ncoef))
            if(sub<len(s)-1 and (not s[sub+1].isdigit())):pre=0
            term(s[i+1:sub-pre],coef*ncoef)
            i=sub
        elif(s[i].isupper()):
            nele=s[i]
            if(i<len(s)-1 and s[i+1].islower()):
                nele+=s[i+1]
                i+=1
            ncoef=getc(s,i+1)
            pre=int(math.log10(ncoef))
            if(i<len(s)-1 and (not s[i+1].isdigit())):pre=0
            ele(nele,coef*ncoef)
            i+=pre
        i+=1

def form(s,coef):
    # print("form",s,coef)
    ncoef=getc(s,0)
    pre=int(math.log10(ncoef)+1)
    if(not s[0].isdigit()):pre=0
    term(s[pre:len(s)],coef*ncoef)

def expr(s,coef):
    # print("expr",s,coef)
    forms=s.split('+')
    global mc
    for i in range(len(forms)):
        mc+=1
        form(forms[i],coef)

def printt():
    for i in range(len(weigh)):
        if(weigh[i]!=0):print(eles[i],'=',weigh[i],sep="")
    print(mc)
    for i in range(mc+1):
        for j in range(len(m[i])):
            if(m[i][j]!=0):print(i,'.',j,',',eles[j],'=',m[i][j],sep="")

def init():
    global weigh,err,ans,mc,m
    weigh=[0]*120
    ans=[1]*120
    m=[[0]*120 for i in range(1010)]
    err=mc=0

while 1:
    init()
    s=input()
    lr=s.split('=',1)
    expr(lr[0],1)
    expr(lr[1],-1)
    if(err==1):print("err!")
    else:printt()
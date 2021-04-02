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

lel=len(eles)
weigh=[0]*lel
ans=[int(1)]*lel

m=[[0]*lel for i in range(1010)]
global mc,err,center,isbalanced

def gcd(a,b):
    if(b==0):return a
    else:return gcd(b,a%b)

# calc

def getc(s,pos):
    s=s[pos:len(s)]
    ret=1
    for i in range(len(s)):
        if(s[0:i+1].isnumeric()):ret=int(s[0:i+1])
        if(not s[0:i+1].isnumeric()):break
    return ret

def ele(s,coef):
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
    ncoef=getc(s,0)
    ans[mc]=ncoef
    pre=int(math.log10(ncoef)+1)
    if(not s[0].isdigit()):pre=0
    term(s[pre:len(s)],coef*ncoef)

def expr(s,coef):
    forms=s.split('+')
    global mc
    for i in range(len(forms)):
        form(forms[i],coef)
        mc+=1

# balance

def balcheck():
    global center
    l=[0]*lel
    r=[0]*lel
    for i in range(center):
        for j in range(lel):
            if(m[i][j]):l[j]=1
    for i in range(center,mc+1):
        for j in range(lel):
            if(m[i][j]):r[j]=1
    if(l!=r):return False
    return True

def balanced():
    global center
    l=[0]*lel
    r=[0]*lel
    for i in range(center):
        for j in range(lel):
            if(m[i][j]):l[j]+=ans[i]*m[i][j]
    for i in range(center,mc+1):
        for j in range(lel):
            if(m[i][j]):r[j]+=ans[i]*m[i][j]
    if(l!=r):return False
    return True

def clean():
    div=0
    for i in ans:div=gcd(div,i)
    for i in range(len(ans)):ans[i]=int(ans[i]/div)

def dfs(k,step):
    if(balanced()):
        global isbalanced
        isbalanced=1
        return True
    if(step>50):return False
    clean()
    for i in ans:
        if(i>1145141919810):return False
    l=0
    r=0
    for i in range(center):l+=m[i][k]*ans[i]
    for i in range(center,mc+1):r+=m[i][k]*ans[i]
    if(l==0 and r==0):return True
    if(l==0 or r==0):return False
    div=gcd(l,r)
    l=int(l/div)
    r=int(r/div)
    changed=[0]*lel
    if(r!=1):
        for i in range(center):
            if(m[i][k]):
                ans[i]*=r
                changed[i]=True
    if(l!=1):
        for i in range(center,mc+1):
            if(m[i][k]):
                ans[i]*=l
                changed[i]=True
    for i in range(mc+1):
        if(changed[i]):
            for j in range(lel):
                if(m[i][j] and j!=k):
                    if(not dfs(j,step+1)):return False
    return True

def recbal():
    for i in range(mc):
        ans[i]=1
    for i in range(len(eles)):
        global isbalanced
        if(not dfs(i,0)):return False
        if(isbalanced):return True
    clean()
    return True

def brutforce(step,rang):
    if(step==mc):return balanced()
    for i in range(1,rang):
        ans[step]=i
        if(brutforce(step+1,rang)):return True
        ans[step]=0
    return False

def brutbal():
    for i in range(3,20):
        if(brutforce(0,i)):return True
    return False

# utilities

def printans(s):
    global center
    lr=s.split('=')
    exps=lr[0].split('+')
    for i in range(len(exps)):
        s=exps[i]
        ncoef=getc(s,0)
        pre=int(math.log10(ncoef)+1)
        if(not s[0].isdigit()):pre=0
        s=s[pre:len(s)]
        if(ans[i]!=1):print(ans[i],end="")
        print(s,end="")
        if(i<len(exps)-1):print('+',end="")
    print('=',end="")
    exps=lr[1].split('+')
    for i in range(len(exps)):
        s=exps[i]
        ncoef=getc(s,0)
        pre=int(math.log10(ncoef)+1)
        if(not s[0].isdigit()):pre=0
        s=s[pre:len(s)]
        if(ans[i+center]!=1):print(ans[i+center],end="")
        print(s,end="")
        if(i<len(exps)-1):print('+',end="")
    print()

def init():
    global weigh,err,mc,m,ans,isbalanced
    weigh=[0]*lel
    ans=[1]*lel
    m=[[0]*lel for i in range(1010)]
    err=0
    mc=0
    isbalanced=0

while True:
    init()
    s=input()
    lr=s.split('=',1)
    expr(lr[0],1)
    center=mc
    expr(lr[1],-1)
    if(err==1):print("err!")
    for i in range(mc):
        for j in range(lel):
            m[i][j]=int(m[i][j]/ans[i])
    if(balanced()):
        print("balanced!")
    else:
        if(balcheck()):
            if(recbal()):printans(s)
            elif(brutbal()):printans(s)
            else:print("failed")
        else:print("impossible")

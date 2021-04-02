import math

priv=[2,2,
    1,1,2,2,2,3,2,2,
    1,1,1,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
]

def getc(s,pos):
    s=s[pos:len(s)]
    ret=1
    for i in range(len(s)):
        if(s[0:i+1].isnumeric()):ret=int(s[0:i+1])
        if(not s[0:i+1].isnumeric()):break
    return ret

def term(s,coef):
    print(s,coef)
    i=0
    while i<len(s):
        if(s[i]=='('):
            sub=s.rfind(')')
            ncoef=getc(s,sub+1)
            pre=int(math.log10(ncoef))
            term(s[i+1:sub-pre],coef*ncoef)
            i=sub
        else:
            nele=s[i]
            if(s[i+1].isalpha()):nele+=s[i+1]
            
        i+=1

def form(s):
    coef=getc(s,0)
    pre=int(math.log10(coef)+1)
    term(s[pre:len(s)],coef)

def expr(s):
    forms=s.split('+')
    for i in forms:form(i)

s=input()
lr=s.split('=',1)
expr(lr[0])
expr(lr[1])
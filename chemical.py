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
        if(not s[0:i+1].isnumeric()):break
    return ret


def term(s,coef):
    i=0
    while i<len(s):
        if(s[i]=='('):
            sub=s.rfind(')')
            ncoef=1
            term(s[i+1:sub],coef*ncoef)
            i=sub
        i+=1

def form(s):
    coef=getc(s,0)
    pre=math.log10(coef)+1
    term(s[pre:len(s)],coef)

def expr(s):
    forms=s.split('+')
    for i in forms:form(i)

s=input()
lr=s.split('=',1)
expr(lr[0])
expr(lr[1])
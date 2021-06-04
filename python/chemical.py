# -*- coding: UTF-8 -*-

import math
from tkinter import *
# import sys    
# import time
from functools import partial
import re # for removing space

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

elm=[[0 for row in range(0,12)] for col in range(0,58)]

elm[0]=["Ac","Ag","Al","Am","Ar","As","At","Au","","","",""]
elm[32]=["Ba","Ca","Ga","La","Na","Pa","Ra","Ta","","","",""]
elm[1]=["B","Ba","Be","Bh","Bi","Bk","Br","","","","",""]
elm[33]=["Db","Nb","Pb","Rb","Sb","Tb","Yb","","","","",""]
elm[2]=["C","Ca","Cd","Ce","Cf","Cl","Cm","Cn","Co","Cr","Cs","Cu"]
elm[34]=["Ac","Mc","Sc","Tc","","","","","","","",""]
elm[3]=["Db","Ds","Dy","","","","","","","","",""]
elm[35]=["Cd","Gd","Md","Nd","Pd","","","","","","",""]
elm[4]=["Er","Es","Eu","","","","","","","","",""]
elm[36]=["Be","Ce","Fe","Ge","He","Ne","Re","Se","Te","Xe","",""]
elm[5]=["F","Fe","Fl","Fm","Fr","","","","","","",""]
elm[37]=["Cf","Hf","Rf","","","","","","","","",""]
elm[6]=["Ga","Gd","Ge","","","","","","","","",""]
elm[38]=["Ag","Hg","Mg","Og","Rg","Sg","","","","","",""]
elm[7]=["H","He","Hf","Hg","Ho","Hs","","","","","",""]
elm[39]=["Bh","Nh","Rh","Th","","","","","","","",""]
elm[8]=["I","In","Ir","","","","","","","","",""]
elm[40]=["Bi","Li","Ni","Si","Ti","","","","","","",""]
elm[9]=["","","","","","","","","","","",""]
elm[41]=["","","","","","","","","","","",""]
elm[10]=["K","Kr","","","","","","","","","",""]
elm[42]=["Bk","","","","","","","","","","",""]
elm[11]=["La","Li","Lr","Lu","Lv","","","","","","",""]
elm[43]=["Al","Cl","Fl","Tl","","","","","","","",""]
elm[12]=["Mc","Md","Mg","Mn","Mo","Mt","","","","","",""]
elm[44]=["Am","Cm","Fm","Pm","Sm","Tm","","","","","",""]
elm[13]=["N","Na","Nb","Nd","Ne","Nh","Ni","No","Np","","",""]
elm[45]=["Cn","In","Mn","Rn","Sn","Zn","","","","","",""]
elm[14]=["O","Og","Os","","","","","","","","",""]
elm[46]=["Co","Ho","Mo","No","Po","","","","","","",""]
elm[15]=["P","Pa","Pb","Pd","Pm","Po","Pr","Pt","Pu","","",""]
elm[47]=["Np","","","","","","","","","","",""]
elm[16]=["","","","","","","","","","","",""]
elm[48]=["","","","","","","","","","","",""]
elm[17]=["Ra","Rb","Re","Rf","Rg","Rh","Rn","Ru","","","",""]
elm[49]=["Ar","Br","Cr","Er","Fr","Ir","Kr","Lr","Pr","Sr","Zr",""]
elm[18]=["S","Sb","Sc","Se","Sg","Si","Sm","Sn","Sr","","",""]
elm[50]=["As","Cs","Ds","Es","Hs","Os","Ts","","","","",""]
elm[19]=["Ta","Tb","Tc","Te","Th","Ti","Tl","Tm","Ts","","",""]
elm[51]=["At","Mt","Pt","","","","","","","","",""]
elm[20]=["U","","","","","","","","","","",""]
elm[52]=["Au","Cu","Eu","Lu","Pu","Ru","","","","","",""]
elm[21]=["V","","","","","","","","","","",""]
elm[53]=["Lv","","","","","","","","","","",""]
elm[22]=["W","","","","","","","","","","",""]
elm[54]=["","","","","","","","","","","",""]
elm[23]=["Xe","","","","","","","","","","",""]
elm[55]=["","","","","","","","","","","",""]
elm[24]=["Y","Yb","","","","","","","","","",""]
elm[56]=["Dy","","","","","","","","","","",""]
elm[25]=["Zn","Zr","","","","","","","","","",""]
elm[57]=["","","","","","","","","","","",""]


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
        if(i>1000000000000):return False
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
    ret=""
    lr=s.split('=')
    exps=lr[0].split('+')
    for i in range(len(exps)):
        s=exps[i]
        ncoef=getc(s,0)
        pre=int(math.log10(ncoef)+1)
        if(not s[0].isdigit()):pre=0
        s=s[pre:len(s)]
        if(ans[i]!=1):ret+=str(ans[i])
        ret+=s
        if(i<len(exps)-1):ret+='+'
    ret+='='
    exps=lr[1].split('+')
    for i in range(len(exps)):
        s=exps[i]
        ncoef=getc(s,0)
        pre=int(math.log10(ncoef)+1)
        if(not s[0].isdigit()):pre=0
        s=s[pre:len(s)]
        if(ans[i+center]!=1):ret+=str(ans[i+center])
        ret+=s
        if(i<len(exps)-1):ret+='+'
    return ret

def init():
    global weigh,err,mc,m,ans,isbalanced
    weigh=[0]*lel
    ans=[1]*lel
    m=[[0]*lel for i in range(1010)]
    err=0
    mc=0
    isbalanced=0


def btn_chg(input_ltt):
    '''
    with the input letter, correspondingly change the text of the buttons
    '''
    ordltt=ord(input_ltt)
    if ordltt > 64 and ordltt < 123:
        for i in range(len(elm[ordltt-65])):
            bttn[i].config(text=elm[ordltt-65][i])
    else:
        for i in range(len(elm[ordltt-65])):
            bttn[i].config(text="")


rt = Tk()

fm1 = Frame(rt)
fm2 = Frame(rt)

num = StringVar()
equ = ""
rt.title("化学式配平")
rt.geometry("750x400")
lbl = Label(fm1, text="键入待配平的化学式")
lbl.grid(column=0, row=0)
txt = Entry(fm1, textvariable=num, width=68)
txt.grid(column=0, row=1)
bal_equ = Label(fm1, text="已配平的化学式")
bal_equ.grid(column=0, row=2)
# txt_dif = Label(fm1, text="last letter")
# txt_dif.grid(column=1,row=2)

def btn_clk(x): #click the button, the content of the text entry will be updated by adding the text of the button.
    global equ
    btn_content = bttn[x].cget('text')
    if btn_content in eles:
        tmp_equ = equ[0:-1]
        tmp_equ = tmp_equ + btn_content
        txt.delete(0,"end")
        txt.insert(0, tmp_equ)

# explanation_lbl = Label(fm2, textvariable="Choose the Chemical Element you want to \nreplace your last input in the equation", width=98)
# explanation_lbl.grid(column=0, row=0)
hlp=Label(fm2,text="样例：\nFe+CuSO4=FeSO4+Cu\n1458H2+729O2=1458H2O\nCaCO3+HCl=CaCl2+H2O+CO2\nH2((((O)2)2)2)2=H2+O2",width=40,height=10,justify='center')
hlp.grid(column=0,row=2, columnspan=6)

bttn = [0 for x in range(12)]
for x in range(12):
    btn_txt = "Emt Name"
    bttn[x] = Button(fm2,text=btn_txt, command=partial(btn_clk, x))
    bttn[x].grid(column=x%6, row=x//6)

def clicked(event):
    global center
    init()
    bal_equ.config(text="......")
    s=txt.get()
    s = re.sub('\s+', '', s).strip() # remove all space
    have_equ=False
    if "=" in s and s[len(s)-1] != "=":
        lr=s.split('=',1)
        expr(lr[0],1)
        center=mc
        expr(lr[1],-1)
        if(err==1):
            res="err"
            return
        for i in range(mc):
            for j in range(lel):
                m[i][j]=int(m[i][j]/ans[i])
        if(balanced()):
            res="已配平！"
        else:
            if(balcheck()):
                if(recbal()):res=printans(s)
                else:
                    bal_equ.configure(text="thinking...")
                    if(brutbal()):res=printans(s)
                    else:res="失败"
            else:res="无法配平"
        bal_equ.configure(text=res)

# stch=Switcher()

def _number_check(event): #check the input and see 
    global equ
    # global stch
    data = num.get().strip()
    data_len = len(data)
    txt_str=''
    if(data_len > 0):
        txt_str=data[data_len - 1]
        btn_chg(txt_str)
    # txt_dif.config(text = txt_str)
    equ = data

txt.bind('<Return>', clicked)
txt.bind('<KeyRelease>', _number_check)
btn = Button(fm1, text="Done")
btn.bind('<Button-1>',clicked)
btn.grid(column=1, row=1)
fm1.pack(padx=1,pady=1)
fm2.pack(padx=1,pady=20)

rt.mainloop()

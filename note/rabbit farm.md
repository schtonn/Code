### Dpug8. 兔农
```
时间限制：1.0s   内存限制：256.0MB
输入文件名：rabbit.in   输出文件名：rabbit.out
试题来源：NOI2011
```
### 问题描述
农夫栋栋近年收入不景气，正在他发愁如何能多赚点钱时，他听到隔壁的小朋友在讨论兔子繁殖的问题。

问题是这样的：第一个月初有一对刚出生的小兔子，经过两个月长大后，这对兔子从第三个月开始，每个月初生一对小兔子。新出生的小兔子生长两个月后又能每个月生出一对小兔子。问第n个月有多少对兔子？

聪明的你可能已经发现，第n个月的兔子数正好是第n个Fibonacci(斐波那契)数。栋栋不懂什么是Fibonacci数，但他也发现了规律：第i+2个月的兔子对数等于第i个月的兔子对数加上第i+1个月的兔子对数。前几个月的兔子对数依次为：

1 1 2 3 5 8 13 21 34 …

栋栋发现越到后面兔子对数增长的越快，期待养兔子一定能赚大钱，于是栋栋在第一个月初买了一对小兔子开始饲养。

每天，栋栋都要给兔子们喂食，兔子们吃食时非常特别，总是每k对兔子围成一圈，最后剩下的不足k对的围成一圈，由于兔子特别害怕孤独，从第三个月开始，如果吃食时围成某一个圈的只有一对兔子，这对兔子就会很快死掉。

我们假设死去的总是刚出生的兔子，那么每个月的兔子对数仍然是可以计算的。例如，当k=7时，前几个月的兔子对数依次为：

1 1 2 3 5 **7** 12 19 31 **49** 80 …

给定n，你能帮助栋栋计算第n个月他有多少对兔子么？由于答案可能非常大，你只需要告诉栋栋第n个月的兔子对数除p的余数即可。
### 输入格式
从文件rabbit.in中读入数据。

输入一行，包含三个正整数n, k, p。
### 输出格式
输出到文件rabbit.out中。

输出一行，包含一个整数，表示栋栋第n个月的兔子对数除p的余数。
### 样例输入   
```6 7 100```
### 样例输出   
```7```
### 样例输入   
```7 7 5```
### 样例输出   
```2```

思路：
### 1.题意
首先理解一下题意：

$$F_i=\left\{
\begin{array}{lr}
F_{i-1}+F_{i-2}& F_{i-1}+F_{i-2}\not\equiv1\pmod k\\
F_{i-1}+F_{i-2}-1& F_{i-1}+F_{i-2}\equiv1\pmod k\\
\end{array}
\right.
$$

给定 $n$，$k$，$p$，求 $F(n)\bmod p$。

可以看出，它是一个略加修改的斐波那契数列，我们显然会想到使用矩阵快速幂，然而由于它会在不可预知的地方进行减一，简单地套用矩阵快速幂就无法达成目标。

### 2.规律

遇到这种问题，可以先手推一下规律。

由于一个具有斐波那契数列性质地数列可以完全由一个二元组 $(a,b)$ 固定，我们可以用一个二元组来表示当前状态。

例如从 $(1,1)$ 开始，$k=7$。

$$(1,1)-(1,2)-(2,3)-(3,5)-(5,1\rightarrow0)-(0,5)-(5,5)-\cdots$$

又如从 $(2,2)$ 开始：

$$\begin{array}{lr}(2,2)-(2,4)-(4,6)-(6,3)-(3,2)-(2,5)-(5,0)-(0,5)-\\(5,5)-(5,3)-(3,1\rightarrow0)-(0,3)-(3,3)-\cdots\end{array}$$

可以得知，如果某个状态进入了 $(b,1)$，它就会被减一成为 $(b,0)$，接下来成为 $(0,b)-(b,b)$，这样我们就可以以 $(a,a)$ 为节点，从某个 $(a,a)$ 用简单矩阵快速幂推到下一个 $(b,1)$，然后减一并继续推进到 $(b,b)$，循环完成整个过程。

放上一个 $k=7$ 时的完整图表：

```
(1,1)-(1,2)-(2,3)-(3,5)-(5,1);
(2,2)-(2,4)-(4,6)-(6,3)-(3,2)-(2,5)-(5,0)-(5,5)-(5,3)-(3,1);
(3,3)-(3,6)-(6,2)-(2,1);
(4,4)-(4,1);
(5,5)-(5,3)-(3,1);
(6,6)-(6,5)-(5,4)-(4,2)-(2,6)-(6,1);
```

注意到它没有那么友好，可能出现自环，两条路径的交集等情况，特别需要注意死循环，编写部分分代码时需要小心。

### 3.$k^2$ 算法
令 $(i,i)$ 经过 $e_i$ 步到达 $(g_i,1)$，可以在 $O(k^2)$ 的时间内维护 $e_i$ 和 $g_i$。

还是以 $k=7$ 为例：

$$e:4,10,3,1,2,5$$
$$g:5,3,2,4,3,6$$

即 $(1,1)$ 经过 $4$ 步到达 $(5,1)$，$(2,2)$ 经过 $10$ 步到达 $(3,1)$，etc.

求出这个之后我们就可以用矩阵快速幂来解决 $(a,a)$ 到 $(b,b)$ 的跳跃了。

这里面还有一些实现细节需要说明一下。由于原来斐波那契数列的递推矩阵实际上是做不到减一的，不过精通矩阵运算的人们都知道，我们只需要加一个常数项，然后稍微修改一下递推矩阵就好了。

原来的矩阵是这样的：

$$
\left[\begin{array}{lr}F_{n+1}\\F_n\end{array}\right]=
\left[\begin{array}{lr}1&1\\1&0\end{array}\right]\times
\left[\begin{array}{lr}F_n\\F_{n-1}\end{array}\right]
$$

现在正常递推改成了这样：
$$
\left[\begin{array}{lr}F_{n+1}\\F_n\\1\end{array}\right]=
\left[\begin{array}{lr}1&1&0\\1&0&0\\0&0&1\end{array}\right]\times
\left[\begin{array}{lr}F_n\\F_{n-1}\\1\end{array}\right]
$$

如果我们想减一，就可以这样：
$$
\left[\begin{array}{lr}F_n-1\\F_{n-1}\\1\end{array}\right]=
\left[\begin{array}{lr}1&0&-1\\0&1&0\\0&0&1\end{array}\right]\times
\left[\begin{array}{lr}F_n\\F_{n-1}\\1\end{array}\right]
$$

如果想推一步的同时减一，就是这样：
$$
\left[\begin{array}{lr}F_{n+1}-1\\F_n\\1\end{array}\right]=
\left[\begin{array}{lr}1&1&-1\\1&0&0\\0&0&1\end{array}\right]\times
\left[\begin{array}{lr}F_n\\F_{n-1}\\1\end{array}\right]
$$

将正常递推的那个矩阵设为 $A$，推一步同时加一的矩阵设为 $B$，最终的算式就是这样：

$$\cdots BA^{e_{g_1}-1}A^2BA^{e_1-1}
\left[\begin{array}{lr}F_2\\F_1\\1\end{array}\right]$$

然后为了符号方便，我们记 $F_0=0$，$F_{-1}=1$，就可以将递推式写为：

$$\cdots BA^{e_{g_1}+1}BA^{e_1+1}\left[\begin{array}{lr}F_0\\F_{-1}\\1\end{array}\right]$$

这样，$O(k^2)$ 算法就妥妥地实现了。

### 4.$k\log k$ 算法

原来求 $e$ 和 $g$ 地算法其实有很大的提升空间，如果你进行了深入的调试就会发现，对于大点的数据，它有 90% 以上的 $(a,a)$ 都陷入了死循环，这说明我们做了大量无用的计算，何不换个角度想想？

如果我们不用二元组，而用正常方式，把斐波那契数列取模 $k$，不管题目中的减一，写出来看看有什么发现？

```
1 1 2 3 5 1 6 0 6 6 5 4 2 6 1 0 1 1
```

发现它在这里进入了循环。

那么我们把数列乘上某个系数，并继续对 $k$ 取模，只写到第一次出现1的地方，再列出来看看有什么发现？

```
1 1 2 3 5 1 6 0 6 6 5 4 2 6 1 0 1 1
2 2 4 6 3 2 5 0 5 5 3 1
3 3 2 6 1
4 4 1
5 5 3 1
6 6 5 4 2 6 1
```

这跟前面的二元组好像没什么区别，但是如果仔细观察，其实每一行的值都是它所对应的真正的数列值，乘上这行的系数，再取模k，也就是那个列最上面的数乘那行最左边的数。

如果我们对第一行的每个数求逆元，求得的就正是它所对应的 $1$ 的位置所在的行数！

这时我们只需要用扩展欧几里得再 $O(k\log k)$ 的时间内求逆元，就可以随之求出所有 $e$ 和 $g$ 的值！

当然，这只是第一部分，求出 $e,g$ 后要需要做一些优化，因为对于矩阵的跳跃，如果 $n$ 足够大，很有可能会进入一个循环，这时记录下一整个循环的递推矩阵之乘积 $C$，然后再套用一次矩阵快速幂，可以省去大量时间，具体实现细节都在代码里了、

### 5.代码
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=1000010;
ll m,n,k,p;
struct matrix{
    ll v[5][5];
    ll x,y;
}f,A,B,I,ans;
ll e[N],g[N],inv[N],vis[N];
void exgcd(ll a,ll b,ll& d,ll& x,ll& y){//这些是求逆元
    if(!b){
        d=a;
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,d,y,x);
    y-=x*(a/b);
}
ll getinv(ll a){
    ll d,x,y;
    exgcd(a,k,d,x,y);
    return d==1?(x+k)%k:-1;
}
ostream&operator<<(ostream&ous,matrix a){//矩阵运算
    for(ll i=0;i<a.x;i++){
        for(ll j=0;j<a.y;j++){
            ous<<a.v[i][j]<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    ll x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%p;
        }
    }
    return c;
}
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    ll x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=0;
            for(ll k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%p;
            }
        }
    }
    return c;
}
matrix operator^(matrix a,ll b){//我把快速幂也重载了
    matrix c=I;
    while(b){
        if(b&1)c=c*a;
        a=a*a;
        b>>=1;
    }
    return c;
}
void init(){
    A.x=A.y=B.x=B.y=3;
    I.x=I.y=3;
    f.x=3;f.y=1;
    f.v[1][0]=f.v[2][0]=1;
    A.v[0][0]=A.v[0][1]=A.v[1][0]=A.v[2][2]=1;
    B.v[0][0]=B.v[0][1]=B.v[1][0]=B.v[2][2]=1;
    B.v[0][2]=-1;
    I.v[0][0]=I.v[1][1]=I.v[2][2]=1;
}
int main(){
    // freopen("rabbit.in","r",stdin);
    // freopen("rabbit.out","w",stdout);
    init();
    cin>>n>>k>>p;
    int a=1,b=2;
    memset(e,-1,sizeof(e));
    for(int i=1;i<=k*k;i++){//先预处理e和g
        if(a==1&&b==1)break;
        if(!inv[b])inv[b]=getinv(b);
        if(inv[b]==-1){
            swap(a,b);
            b=(a+b)%k;
            continue;
        }
        if(e[inv[b]]==-1){
            e[inv[b]]=i;
            g[inv[b]]=a*inv[b]%k;
        }
        swap(a,b);
        b=(a+b)%k;
    }
    ll flag=0;
    ll cur=1,ptr=0;
    while(true){//沿着路线走一走，碰到循环就退出
        if(vis[cur]){
            flag=cur;
            break;
        }
        vis[cur]=1;
        if(ptr+e[cur]+1>n||e[cur]==-1){
            f=(A^(n-ptr))*f;
            break;
        }
        f=(A^(e[cur]+1))*f;
        ptr+=e[cur]+1;
        if(ptr>=n)break;
        f=B*f;
        ptr++;
        cur=g[cur];
        if(ptr>=n)break;
    }
    matrix C;
    ll siz;
    if(flag){//如果在循环里，那就求一下C
        siz=e[flag]+2;
        C=B*(A^(e[flag]+1));
        for(ll i=g[flag];i!=flag;i=g[i]){
            C=B*(A^(e[i]+1))*C;
            siz+=e[i]+2;
        }
        f=(C^((n-ptr)/siz))*f;//这一行做了大部分运算
        if((n-ptr)%siz){//还有剩下的部分，那就接着算完
            ptr=n-((n-ptr)%siz);
            while(true){
                if(ptr+e[cur]+1>n){
                    f=(A^(n-ptr))*f;
                    break;
                }
                f=(A^(e[cur]+1))*f;
                ptr+=e[cur]+1;
                if(ptr>=n)break;
                f=B*f;
                ptr++;
                cur=g[cur];
                if(ptr>=n)break;
            }
        }
    } 
    cout<<(f.v[0][0]+p)%p<<endl;//完结
    return 0;
}
```
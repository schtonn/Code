# Math

## C
$$\text{C}^{n}_{r}=\dfrac{n!}{r!(n-r)!}$$
## Ferbonacci
$$\text{F}(n)=\dfrac{\sqrt{5}}{5}\cdot\left[\left(1+\sqrt{5}\right)^n-\left(1-\sqrt{5}\right)^n\right]$$
## 组合数学

### 证：$\dbinom{m+n}{m}=\dbinom{m+n}{n}$

||$(m+n)$|
|-|-|
|-|-|
|-|-|
|-|-|
|$(0,0)$|||
$(0,0)\rightarrow(m,n)$ 路径数

转化为m个x卡片和n个y卡片置入n+m个盒子中：


$$m\times\colorbox{green}{x},n\times\colorbox{red}{y}$$
$$\downarrow$$
$$\begin{matrix}\underbrace{\colorbox{grey}{box}\colorbox{grey}{box}\colorbox{grey}{box}\cdots\colorbox{grey}{box}}\\n+m\end{matrix}$$

即m+n中选m个，剩下都是y。

即$\dbinom{m+n}{m}$或$\dbinom{m+n}{n}$

$\therefore\dbinom{m+n}{m}=\dbinom{m+n}{n}$

### 证$\dbinom{n}{r}=\dbinom{n-1}{r}+\dbinom{n-1}{r-1}$

$\dbinom{n}{r}:(0,0)\rightarrow(n-r,r)$

$\dbinom{n-1}{r}:(0,0)\rightarrow(n-r-1,r)$

$\dbinom{n-1}{r-1}:(0,0)\rightarrow(n-r,r-1)$

$\because(0,0)\rightarrow(n-r,r)=(0,0)\rightarrow(n-r,r)+(0,0)\rightarrow(n-r,r-1)$

$\therefore\dbinom{n}{r}=\dbinom{n-1}{r}+\dbinom{n-1}{r-1}$

$$\begin{gathered}\textbf{数学入门}\cr\boxed{\begin{aligned}&\kern{15pt} \begin{aligned} \cr &\text{先假设你有一个小蛤蟆。}\cr&\text{假设现在有人又给了一个蛤蟆。}\cr &\text{现在，看一看你的蛤蟆们。}\cr &{1+1=2}\cr&\text{也就是说，你有了两只蛤蟆。}\cr \cr &\text{那么，现在你已经对数学的基本运算有了一定的了解，就让我们来看}\cr &\text{一看下面这个简单的例子，来把我们刚刚学到的东西运用到实践中吧。}\kern{15pt}\cr &\underline{\kern{310pt}}\cr[-13pt] &\underline{\kern{310pt}}\cr \end{aligned}\cr &\kern{10pt}\boxed{\stackrel{\normalsize\quad\textbf{试试看!}\quad}{\normalsize\quad\text{例题 1.8}\quad}}\cr &\begin{gathered} \kern{5pt}\log \Pi(N)=\Big(N+\dfrac{1}{2}\Big)\log N -N+A-\int_{N}^{\infty}\dfrac{\overline{B}_1(x){\rm d} x}{x}, A=1+\int_{1}^{\infty}\dfrac{\overline{B}_1(x){\rm d} x}{x} \cr \log \Pi(s)=\Big(s+\dfrac{1}{2}\Big)\log s-s+A-\int_{0}^{\infty}\dfrac{\overline{B}_1(t){\rm d} t}{t+s} \end{gathered}\cr &\kern{5pt}\begin{aligned} \log \Pi(s)=&\lim_{n\to \infty}\Big[s \log(N+1)+\sum_{n=1}^{N}\log n-\sum_{n=1}^{N}\log(s+n)\Big]\cr =&\lim_{n\to \infty}\Big[s \log (N+1)+\int_{1}^{N}\log x {\rm d} x-\dfrac{1}{2}\log N +\int_{1}^{N}\dfrac{\overline{B}_1{\rm d} x}{x}\cr &-\int_{1}^{N}\log(s+x){\rm d} x-\dfrac{1}{2}[\log(s+1)+\log(s+N)]\cr &-\int_{1}^{N}\dfrac{\overline{B}_1(x){\rm d} x}{s+x}\Big]\cr =&\lim_{n\to \infty}\Big[s\log(N+1)+N\log N-N+1+\dfrac{1}{2}\log N+\int_{1}^{N}\dfrac{\overline{B}_1(x){\rm d} x}{x} \cr &-(s+N)\log(s+N)+(s+N)+(s+1)\log(s+1)\cr &-(s+1)-\dfrac{1}{2}\log(s+1)-\dfrac{1}{2}\log(s+N)-\int_{1}^{N}\dfrac{\overline{B}_1(x){\rm d} x}{s+x}\Big]\cr =&\Big(s+\dfrac{1}{2} \Big)\log(s+1)+\int_{1}^{\infty}\dfrac{\overline{B}_1(x){\rm d} x}{x}-\int_{1}^{N}\dfrac{\overline{B}_1(x){\rm d} x}{s+x}\cr &+\lim_{n \to \infty}\Big[s\log(N+1)+\Big(N\dfrac{1}{2}\Big)\log N\cr &-\Big(s+N+\dfrac{1}{2}\Big)\log(s+N)\Big]\cr =&\Big(s+\dfrac{1}{2}\Big)\log(s+1)+(A-1)-\int_{1}^{\infty}\dfrac{\overline{B}_1(x){\rm d} x}{s+x}\cr &+\lim\Big[s\log\dfrac{N+1}{2}-\Big(N+\dfrac{1}{2}\Big)\log\Big(1+\dfrac{s}{2}\Big)\Big] \end{aligned}\end{aligned}}\cr\cr[-44pt]{\kern{347pt}}\cr[-7pt]\end{gathered}$$

$$y_i=\sum_{j=l_i}^{r_i}\times\sum_{j=l_i}^{r_i}v_j(w_j>W)$$


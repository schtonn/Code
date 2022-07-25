# Exploring The Game of Nim


## Notes

*You can take your own note.*

>- Randomly 随机
>- Pile 堆
>- Bound to ... 一定会... 
>- Opponent 对手
>- Property 性质
>- State 状态
>- Convert 转换
>- Binary 二进制
>- Scenario 情境
>
>Additional help
>- Definition 定义
>- Skip 跳过
>- Align 排列，对正
>- Digit 数位
>&nbsp;
>
>&nbsp;
>
>&nbsp;
>
>&nbsp;
>
>&nbsp;
>
>&nbsp;
>
>&nbsp;
>
>&nbsp;

## Free space

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

## Script

### **Introduction**

The Game of Nim, is not a specific game, but a definition.

We start by having some piles of stones and two players(Alice and Bob). Alice picks one of the piles, and takes some stones out of it. Then Bob does the same thing. The one who takes the last stone away wins. 

*Note: Skipping a round is not allowed.*

### **Example**
### **Trial**
### **Explanation (with 2 piles)**

Did you find the pattern?

It’s actually quite simple, you’ll just have to check whether the two piles are equal. If they aren’t, then you should take stones from the greater pile and make them equal. Otherwise, you are bound to lose, because your opponent can always make them equal, and finally take all of them away.

That solution was using an important property of this kind of game:

>If you can keep your opponent in one state(equal), and it is the state that you can win(0 equals 0), then you will win.

### **Further Explanation (with more piles)**

We can use the same idea to solve more piles of stones. However, this needs some knowledge about binary.

First, every number can be converted into binary. For example, $1=(1)_2$, $2=(10)_2$, $3=(11)_2$, $4=(100)_2$, $100=(1100100)_2$.

Second, there is a binary operation called ‘XOR’, repersented as '$\oplus$'. To do this operation, we need to:

1. Align the two numbers.
2. Compare each digit.
3. Set it to 1 if they are different, 0 if they are the same.
   
For example, $1001010\oplus 0011011=1010001$.

>This operation has a useful property: If you do it twice with the same number, it leaves the original number.
>
>That’s to say, for any $a$ and $b$, $a\oplus b\oplus b=a$.
>
>So, if we XOR 0011011 again, it will leave the original 1001010.

>Another property is that if you XOR two same numbers, it will end up with zero.

We define a state of winning, $x$, by XOR-ing the numbers of stones together. For example, if we have three piles of 3, 5, 7 stones, then $x=3 \oplus 5 \oplus 7=011 \oplus 101 \oplus 111=1$.

If $x\neq 0$, then you will win. Otherwise, you are bound to lose because there is always a way to set it to zero, and the final state is also zero($0 \oplus … \oplus 0=0$).

### **Further, Further Explanation (for advanced players)**

See how this fits with the 2 piles scenario? If the 2 piles are equal, then $x=0$, and you will lose.

Do you want to know how to set $x$ to zero? It’s simple, just pick the largest pile and XOR it with $x$. Then, take some stones in order to set that pile to that number. Do it repeatedly and you will win.

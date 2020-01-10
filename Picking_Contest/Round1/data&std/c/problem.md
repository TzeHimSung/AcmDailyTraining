# C.橘猫与电梯

### Time: 1s  Memery: 128MB

从前有一座神奇的大楼，这栋楼有 $n$ 层。

有一天，邪恶的 $lzh$ 把橘猫最喜欢的小鱼干放在了这栋楼的顶层（即第 $n$ 层）。

而在这栋大楼中，从第 $i$ 层到第 $i+1$ 层有如下两种方式，

* 走电梯，将耗费 $a_i$ 的时间，并且需要 $m$ 的时间来等待电梯门的开启。

* 走楼梯，将耗费 $b_i$ 的时间。

橘猫想要尽快吃掉它最爱的小鱼干，所以它会选择用时最短的路线。

橘猫现在在第 $1$ 层，聪明的你能知道橘猫到达第 $n$ 层需要的最短时间吗？

## Input

第一行是一个整数 $T (1 \le T \le 200)$ ，代表数据组数。

接下来，对于每组测试数据，

第一行是两个整数 $n,m (1 \le n \le 2 \cdot 10^5,1 \le m \le 1000)$，表示大楼的层数跟电梯开门的时间。

第二行是 $n-1$ 个整数 $a_1 , a_2 , ... , a_{n-1}$，其中 $a_i(1 \le a_i \le 1000)$ 表示从第 $i$ 层到第 $i+1$ 层乘坐电梯所需的时间。

第三行是 $n-1$ 个整数 $b_1 , b_2 , ... , b_{n-1}$，其中 $b_i(1 \le b_i \le 1000)$ 表示从第 $i$ 层到第 $i+1$ 层爬楼梯所需的时间。

## Output

对于每组数据，输出一行，为最短时间。

## Sample Input

1  
10 2  
7 6 18 6 16 18 1 17 17  
6 9 3 10 9 1 10 1 5  

## Sample Output

44 
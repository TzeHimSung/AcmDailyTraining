## Sequence

### Description

> SJoshua：你知道什么是Fibonacci sequence吗？
>
> JHSeng：说人话！
>
> SJoshua：斐波那契数列啊。
>
> JHSeng：emmmmmm这超出了我的知识范围。
>
> SJoshua：不会了吧，就是一个长这样的数列啊：

$$f[i]=\begin{cases} 1 & i=1,2 \\ f[i-1]+f[i-2] & i \ge 3 \end{cases}$$

> SJoshua：这下你懂了吧
>
> JHSeng：喔喔，原来是这样子。恩，这下我完全明白了。(完全没搞懂)
>
> SJoshua：那么问题来了，你能帮我求这个数列的第n项吗？
>
> JHSeng：？！

### Input format

第一行一个整数$T$，代表有$T$个测试用例。

接下来T行，每行一个正整数$n(1 \le n \le 100)$。

### Output format

包含$T$行，每行一个正整数，代表$f[n]$。

### Sample Input

5

1

2

3

4

5

### Sample Output

1

1

2

3

5


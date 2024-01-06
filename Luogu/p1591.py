from math import factorial


def solve():
    n, a = [int(i) for i in input().split()]
    n = factorial(n)
    cnt = {i: 0 for i in range(10)}
    while n > 0:
        cnt[n % 10] += 1
        n //= 10
    print(cnt[a])


t = int(input())
while t > 0:
    solve()
    t -= 1

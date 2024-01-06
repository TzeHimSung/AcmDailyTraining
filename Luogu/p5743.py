def solve():
    n = int(input())
    ans = 1
    n -= 1
    while n > 0:
        n -= 1
        ans = (ans + 1) * 2
    print(ans)


solve()

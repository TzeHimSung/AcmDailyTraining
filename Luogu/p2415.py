def solve():
    a = [int(i) for i in input().split()]
    ans = sum(a)
    ans *= pow(2, len(a) - 1)
    print(ans)


solve()

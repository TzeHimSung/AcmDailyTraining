def check(year):
    return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0


def solve():
    x, y = [int(i) for i in input().split()]
    ans = [i for i in range(x, y + 1) if check(i)]
    print(len(ans))
    print(*ans)


solve()

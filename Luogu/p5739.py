def solve():
    def fac_n(n):
        if n == 0 or n == 1:
            return 1
        return n * fac_n(n - 1)

    n = int(input())
    print(fac_n(n))


solve()

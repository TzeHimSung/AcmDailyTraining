def solve():
    a = list(map(int, input().split()))
    a = a[1:]
    b = [abs(a[i + 1] - a[i]) for i in range(len(a) - 1)]
    b = list(set(sorted(b)))
    for i in range(len(b)):
        if b[i] != i + 1:
            print("Not jolly")
            return
    print("Jolly")


solve()

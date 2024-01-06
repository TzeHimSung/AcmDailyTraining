def solve():
    a = [int(i) for i in input().split()]
    a = sorted(a)
    if a[0] == a[1]:
        print(a[2])
    else:
        print(a[0])


t = int(input())
while t > 0:
    solve()
    t -= 1

def solve():
    n = int(input())
    if n == 3:
        print("1 2\n2")
        return
    elif n == 4:
        print("1 3\n3")
        return
    a = []
    sum, i = 0, 1
    while sum < n:
        i += 1
        a.append(i)
        sum += i
    if sum - n == 1:
        a = a[1:]
        a[-1] += 1
    elif sum - n > 1:
        a = a[: sum - n - 2] + a[sum - n - 1 :]
    print(*a)
    ans = 1
    for i in a:
        ans *= i
    print(ans)


solve()

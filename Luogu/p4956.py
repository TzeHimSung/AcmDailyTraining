n = int(input())
for x in reversed(range(1, 101)):
    remain = n - 52 * 7 * x
    if remain % (21 * 52) == 0:
        k = int(remain // (21 * 52))
        if k <= 0:
            continue
        print(x)
        print(k)
        break

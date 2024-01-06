n = int(input())
ans = [n]

while n != 1:
    if n % 2 == 1:
        n = 3 * n + 1
    else:
        n = int(n // 2)
    ans.append(n)

print(" ".join([str(i) for i in reversed(ans)]))

#!/usr/bin/env python
num = list(map(int, input().split()))
a, b, c, n = num[0], num[1], num[2], num[3]
mod = 2 ** 64

if n % 2 == 0:
    ans = n * (n + 8) * (n - 2) // 24 % mod
else:
    ans = n * (n + 1) * (n - 1) // 24 % mod

if a != b and a != c and b != c:
    ans = ans * 6 % mod
elif a != b or a != c or b != c:
    ans = ans * 3 % mod

print(ans)

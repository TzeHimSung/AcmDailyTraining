n = int(input())
a = []
for i in range(n):
    x, y, z = [int(i) for i in input().split()]
    a.append(tuple([x, y, z]))

a = sorted(a)
ans = 0
for i in a:
    for j in a:
        if i == j:
            continue
        if (
            abs(i[0] - j[0]) <= 5
            and abs(i[1] - j[1]) <= 5
            and abs(i[2] - j[2]) <= 5
            and abs(sum(i) - sum(j)) <= 10
        ):
            ans += 1

print(int(ans // 2))

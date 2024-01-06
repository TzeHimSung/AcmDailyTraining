def solve():
    n = int(input())
    max_score, line = -1, []
    while n > 0:
        n -= 1
        a = input().split()
        score = sum([int(i) for i in a[1:]])
        if score > max_score:
            max_score = score
            line = a
    print(*line)


solve()

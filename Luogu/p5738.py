def solve():
    n, m = [int(i) for i in input().split()]
    max_score = 0
    for man in range(n):
        score = [int(i) for i in input().split()]
        score = sorted(score)[1:-1]
        max_score = max(max_score, sum(score) / (m - 2))
    print("{:.2f}".format(max_score))


solve()

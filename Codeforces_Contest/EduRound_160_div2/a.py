def solve():
    s = input()
    ans_a, ans_b = -1, -1
    for i in range(len(s)):
        a, b = s[:i], s[i:]
        if not a or not b or a.startswith("0") or b.startswith("0"):
            continue
        # print(f"a: {a}, b: {b}")
        a, b = int(a), int(b)
        if a < b:
            ans_a, ans_b = a, b
    if ans_a == -1:
        print("-1")
    else:
        print(f"{ans_a} {ans_b}")


t = int(input())
while t:
    solve()
    t -= 1

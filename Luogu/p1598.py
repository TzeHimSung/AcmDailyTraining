import string


def solve():
    cnt = {i: 0 for i in list(string.ascii_uppercase)}
    maxx = 0
    for n in range(4):
        s = input()
        for i in s:
            if i.isupper():
                if i in cnt:
                    cnt[i] += 1
                else:
                    cnt[i] = 1
                maxx = max(maxx, cnt[i])
    while maxx > 0:
        print(
            " ".join(
                ["*" if cnt[i] >= maxx else " " for i in list(string.ascii_uppercase)]
            )
        )
        maxx -= 1
    print(" ".join(string.ascii_uppercase))


solve()

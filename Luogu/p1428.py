n = int(input())
a = [int(i) for i in input().split()]

cnt = {}
ans = []

for fish in a:
    if fish not in cnt:
        cnt[fish] = 1
    else:
        cnt[fish] += 1
    curr = 0
    for cute, num in cnt.items():
        if cute < fish:
            curr += cnt[cute]
    ans.append(curr)

print(" ".join([str(i) for i in ans]))

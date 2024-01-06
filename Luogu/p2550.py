cnt = [0] * 8
n = int(input())
lucky = set([int(i) for i in input().split()])
tickets = []
for tt in range(n):
    x = set([int(i) for i in input().split()])
    tickets.append(x)
for ticket in tickets:
    num_in = len(ticket.intersection(lucky))
    cnt[7 - num_in] += 1

ans = [cnt[i] for i in range(7)]
print(" ".join([str(i) for i in ans]))

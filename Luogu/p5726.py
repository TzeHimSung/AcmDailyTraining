n = int(input())
a = [int(i) for i in input().split()]
a = sorted(a)
a = a[1:-1]
print("{:.2f}".format(sum(a) / len(a)))

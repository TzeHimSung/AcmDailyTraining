t, k = map(int, input().split())
# print(t, k)
totalTime = 2 * t + t * (k - 1)
print((totalTime % k != 0) + (totalTime // k))

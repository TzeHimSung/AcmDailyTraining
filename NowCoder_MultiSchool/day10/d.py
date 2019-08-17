ai = []
bi = []
 
for i in range(200):
    ai.append(0)
    bi.append(0)
 
def mul(a, b, mod):
    ret = 0
    while b > 0:
        if b & 1:
            ret = (ret + a) % mod
        a = (a + a) % mod
        b >>= 1
    return ret
 
x = 0
y = 0
 
def exgcd(a, b):
    global x, y
    if b == 0:
        x = 1
        y = 0
        return a
    gcd = exgcd(b, a % b)
    tp = x
    x = y
    y = tp - a // b * y
    return gcd
 
def excrt():
    global x, y
    M = bi[1]
    ans = ai[1]
    for i in range(2, n + 1):
        a = M
        b = bi[i]
        c = (ai[i] - ans % b + b) % b
        gcd = exgcd(a, b)
        bg = b // gcd
        if c % gcd != 0:
            print("he was definitely lying")
            exit()
        x = mul(x, c // gcd, bg)
        ans += x * M
        M *= bg
        ans = (ans % M + M) % M
    return (ans % M + M) % M
 
(n, k) = map(int, input().split())
for i in range(1, n + 1):
    (t1, t2) = map(int, input().split())
    bi[i] = t1
    ai[i] = t2
ans = excrt()
if ans <= k:
    print(ans)
else:
    print("he was probably lying")

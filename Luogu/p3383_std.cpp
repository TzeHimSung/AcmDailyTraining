/* basic header */
#include <bits/stdc++.h>
using namespace std;

bool isPrime[100000010];
int prime[5000010], cnt = 0;

void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isPrime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    getPrime(n);
    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}
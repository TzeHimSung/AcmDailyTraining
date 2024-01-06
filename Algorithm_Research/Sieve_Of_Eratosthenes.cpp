// O(n)欧拉筛
// luogu p3383
/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e8 + 10, maxp = 6e6 + 10;
int prime[maxp], cnt = 0;
bool isPrime[maxn];

void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
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
    scanf("%d%d", &n, &q);
    getPrime(n);
    while (q--) {
        int k; scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}
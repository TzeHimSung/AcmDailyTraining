/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2750131;
int vis[maxn + 5], p[maxn + 5], cnt[2 * maxn + 5], a[maxn + 5], b[2 * maxn + 5];
int tot = 1;

void getPrime() {
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= maxn; i++) {
        if (vis[i] == 0)
            p[tot++] = i;
        for (int j = 1; j <= maxn && i * p[j] <= maxn; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    getPrime();
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &b[i]);
        cnt[b[i]]++; // count times
    }
    int q = 0;
    sort(b, b + 2 * n, cmp);
    for (int i = 0; i < 2 * n; i++) {
        if (cnt[b[i]] == 0)continue;
        if (vis[b[i]]) // if b[i] is not a prime, it must be in array a
            for (int j = 1; j < tot; j++)
                if (b[i] % p[j] == 0) {
                    int t = b[i] / p[j]; // t is the greatest divisor
                    a[q++] = b[i];
                    cnt[b[i]]--;
                    cnt[t]--;
                    break;
                }
    }
    for (int i = 2; i <= maxn; i++)
        while (cnt[i]) {
            a[q++] = i;
            cnt[i]--;
            cnt[p[i]]--;
        }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
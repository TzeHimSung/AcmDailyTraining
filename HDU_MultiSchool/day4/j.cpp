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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 4010;
int t, tot, p[maxn], vis[maxn];
ll n;

void getPrime() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < maxn; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    getPrime();
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        int cnt = int_inf, flag = 0;
        for (int i = 0; i < tot; i++)
            if (n % p[i] == 0) {
                int num = 0;
                while (n % p[i] == 0) {
                    num++; n /= p[i];
                }
                if (num == 1) flag = 1;
                cnt = min(cnt, num);
            }
        if (flag) {
            puts("1");
            continue;
        }
        if (n == 1) {
            printf("%d\n", cnt);
            continue;
        }
        ll tmp = pow(n, 0.25);
        if (tmp * tmp * tmp * tmp == n) cnt = min(cnt, 4);
        else {
            ++tmp;
            if (tmp * tmp * tmp * tmp == n) cnt = min(cnt, 4);
            else {
                tmp = pow(n, 0.5);
                if (tmp * tmp == n) cnt = min(cnt, 2);
                else {
                    tmp++;
                    if (tmp * tmp == n) cnt = min(cnt, 2);
                    else {
                        tmp = pow(n, 1.0 / 3);
                        if (tmp * tmp * tmp == n) cnt = min(3, cnt);
                        else {
                            tmp++;
                            if (tmp * tmp * tmp == n) cnt = min(3, cnt);
                            else cnt = min(1, cnt);
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
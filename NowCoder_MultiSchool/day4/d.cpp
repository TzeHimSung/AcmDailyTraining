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

const int maxn = 1e2 + 10;
int func[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        if (n % 3 == 0) {
            printf("1 %lld\n", n);
            continue;
        }
        ll cmp = n;
        int cnt = 0;
        while (cmp) {
            func[++cnt] = cmp & 1;
            cmp >>= 1;
        }
        rep0(i, 2, cnt) {
            ll ans1 = 0, ans2 = 0;
            for (int j = cnt; j >= i + 1; j--) ans1 = ans1 * 2 + func[j];
            for (int j = i; j >= 1; j--) ans2 = ans2 * 2 + func[j];
            rep1(j, 1, i) ans1 *= 2;
            if (ans2 % 3 == 1) {
                rep1(j, i + 1, cnt)
                if (j % 2 == 0 && func[j]) {
                    ans2 |= (1ll << j - 1);
                    break;
                }
                int flag = 0;
                if (ans2 % 3 != 0)
                    rep1(j, i + 1, cnt)
                    if (j % 2 == 1 && func[j]) {
                        if (!flag)flag = j;
                        else {
                            ans2 |= (1ll << flag - 1); ans2 |= (1ll << j - 1);
                            break;
                        }
                    }
            } else if (ans2 % 3 == 2) {
                rep1(j, i + 1, cnt)
                if (j % 2 == 1 && func[j]) {
                    ans2 |= (1ll << j - 1);
                    break;
                }
                int flag = 0;
                if (ans2 % 3 != 0)
                    rep1(j, i + 1, cnt)
                    if (j % 2 == 0 && func[j]) {
                        if (!flag)flag = j;
                        else {
                            ans2 |= (1ll << flag - 1); ans2 |= (1ll << j - 1);
                            break;
                        }
                    }
            }
            if (ans2 % 3 != 0)continue;
            if (ans1 % 3 == 1) {
                rep1(j, 1, i)
                if (j % 2 == 0 && func[j]) {
                    ans1 |= (1ll << j - 1);
                    break;
                }
                int flag = 0;
                if (ans2 % 3 != 0)
                    rep1(j, 1, i)
                    if (j % 2 == 1 && func[j]) {
                        if (!flag) flag = j;
                        else {
                            ans1 |= (1ll << flag - 1); ans1 |= (1ll << j - 1);
                            break;
                        }
                    }
            } else if (ans1 % 3 == 2) {
                rep1(j, 1, i)
                if (j % 2 == 1 && func[j]) {
                    ans1 |= (1ll << j - 1);
                    break;
                }
                int flag = 0;
                if (ans1 % 3 != 0)
                    rep1(j, 1, i)
                    if (j % 2 == 0 && func[j]) {
                        if (!flag) flag = j;
                        else {
                            ans1 |= (1ll << flag - 1); ans1 |= (1ll << j - 1);
                            break;
                        }
                    }
            }
            if (ans1 % 3 != 0)continue; if ((ans1 | ans2) != n)continue;
            printf("2 %lld %lld\n", ans1, ans2);
            break;
        }
    }
}
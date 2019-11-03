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

const int maxn = 1e6 + 5;
ll cnt[maxn];
int n, a[maxn][3];
vector<int>peop[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll current = 0, counter = 0, total = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i][0]);
            peop[i].clear(); cnt[i] = 0;
            if (a[i][0] != 1) scanf("%d%d", &a[i][1], &a[i][2]);
            else {
                int len; scanf("%d", &len);
                while (len--) {
                    int x; scanf("%d", &x);
                    peop[i].push_back(x);
                }
            }
        }
        cnt[n] = 1;
        for (int i = n; i >= 1; i--)
            if (a[i][0] == 2) {
                cnt[a[i][1]] += cnt[i];
                cnt[a[i][2]] += cnt[i];
            }
        for (int i = 1; i <= n; i++)
            if (a[i][0] == 1 && cnt[i] != 0)
                for (auto j : peop[i]) {
                    if (!current) {
                        current = j;
                        counter += cnt[i];
                    } else if (current == j) counter += cnt[i];
                    else {
                        counter -= cnt[i];
                        if (counter < 0) {
                            current = j;
                            counter = -counter;
                        }
                    }
                    total += cnt[i];
                }
        counter = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][0] == 1 && cnt[i] != 0) {
                for (auto j : peop[i])
                    if (j == current) {
                        counter += cnt[i];
                    }
            }
        printf("%lld\n", (counter > total - counter) ? (total - counter) << 1 : total);
    }
    return 0;
}
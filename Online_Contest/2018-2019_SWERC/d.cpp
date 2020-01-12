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

const int maxn = 200010, lim = 100001;
struct Point {
    int x, y;
} p[maxn];
int n, x, y, maxx[maxn], minn[maxn], monument[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        p[i].x = p[i].y = monument[i] = 0;
        maxx[i] = -1;
    }
    memset(minn, 0x3f, sizeof(minn));
}

int main() {
    while (~scanf("%d%d", &x, &y)) {
        init();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            maxx[p[i].x] = max(maxx[p[i].x], p[i].y);
            minn[p[i].x] = min(minn[p[i].x], p[i].y);
        }
        int cnt = 0;
        for (int i = 0; i < lim; i++) {
            if (maxx[i] != -1 && minn[i] != 0x3f3f3f3f) {
                monument[cnt++] = maxx[i];
                monument[cnt++] = minn[i];
            }
        }
        sort(monument, monument + cnt);
        ll ans = x - 1, mid = monument[(cnt - 1) / 2];
        for (int i = 0; i < lim; i++)
            if (maxx[i] != -1 && minn[i] != 0x3f3f3f3f)
                ans += (ll)maxx[i] - minn[i] + abs(mid - maxx[i]) + abs(mid - minn[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
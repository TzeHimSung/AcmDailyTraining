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

const int maxn = 1e4 + 10;
int n, m, tot1 = 0, tot2 = 0, c[maxn], vis[maxn];
ll ans = 0;

struct Vert {
    int x, y, xx;
    bool operator<(const Vert &rhs)const {
        return y < rhs.y;
    }
} v[maxn];

struct Hori {
    int x, y, yy;
    bool operator<(const Hori &rhs)const {
        return yy < rhs.yy;
    }
} h[maxn];

int lowbit(int x) {
    return x & -x;
}

int find(int x) {
    int ret = 0;
    while (x > 0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int val) {
    while (x <= 10001) {
        c[x] += val;
        x += lowbit(x);
    }
}

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) {
        int x, y, xx, yy; scanf("%d%d%d%d", &x, &y, &xx, &yy);
        x += 5001, y += 5001, xx += 5001, yy += 5001;
        if (x == xx) h[++tot2] = (Hori) {
            x, min(y, yy), max(y, yy)
        };
        else v[++tot1] = (Vert) {
            min(x, xx), y, max(x, xx)
        };
    }
    sot(v, tot1); sot(h, tot2);
    sort(v + 1, v + 1 + tot1);
    sort(h + 1, h + 1 + tot2);
    rep1(i, 1, tot1) {
        rep0(j, 0, maxn) c[j] = 0;
        rep1(j, 1, tot2) {
            if (h[j].y <= v[i].y && h[j].yy >= v[i].y) {
                add(h[j].x, 1);
                vis[j] = 1;
            } else vis[j] = 0;
        }
        int k = 1;
        rep1(j, i + 1, tot1) {
            while (k <= tot2 && h[k].yy < v[j].y) {
                if (vis[k]) add(h[k].x, -1);
                k++;
            }
            int l = max(v[i].x, v[j].x) - 1, r = min(v[i].xx, v[j].xx);
            if (l < r) {
                int x = find(r) - find(l);
                ans += 1LL * x * (x - 1) / 2;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
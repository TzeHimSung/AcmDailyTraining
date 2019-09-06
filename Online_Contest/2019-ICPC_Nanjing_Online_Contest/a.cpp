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

const int maxn = 1e6 + 10;
struct Point {
    int x, y, val, id;
    Point() {}
    Point(int a, int b, int c, int d): x(a), y(b), val(c), id(d) {}
    bool operator<(const Point &rhs)const {
        return x != rhs.x ? x < rhs.x : y != rhs.y ? y < rhs.y : id < rhs.id;
    }
} p[maxn];

int n, m, q, len;
ll ans[maxn];

struct BIT {
    int bit[maxn];

    void init(int n) {
        rep0(i, 0, n) bit[i] = 0;
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int pos, int val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += lowbit(pos);
        }
    }

    ll query(int pos) {
        ll res = 0;
        while (pos) {
            res += bit[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
} bit;

int getval(int x, int y) {
    x = n + 1 - x, y = n + 1 - y;
    ll ans = 0, minn = min(x, min(y, min(n - x + 1, n - y + 1))), ret = 0;
    ans = x <= y ? minn * (4 * (n - 1) - 4 * minn) + 10 * minn - 4 * n - 3 + x + y : minn * (4 * n - 4 * minn) + 2 * minn + 1 - x - y;
    while (ans) {
        ret += ans % 10;
        ans /= 10;
    }
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &q); len = m;
        bit.init(n);
        rep1(i, 1, m) {
            int x, y; scanf("%d%d", &x, &y);
            p[i] = Point(x, y, getval(x, y), 0);
        }
        rep1(i, 1, q) {
            ans[i] = 0;
            int x1, x2, y1, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            p[++len] = Point(x1 - 1, y1 - 1, 1, i); // when id != 0, means reaching a boarder of rectangle
            p[++len] = Point(x2, y2, 1, i);
            p[++len] = Point(x1 - 1, y2, -1, i);
            p[++len] = Point(x2, y1 - 1, -1, i);
        }
        sort(p + 1, p + 1 + len);
        for (int i = 1; i <= len; i++) //enum each point
            if (p[i].id) ans[p[i].id] += bit.query(p[i].y) * p[i].val; // if it's a boarder
            else bit.add(p[i].y, p[i].val); // else add contribution to ans
        rep1(i, 1, q) printf("%lld\n", ans[i]);
    }
    return 0;
}
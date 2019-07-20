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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e7 + 10;
struct Node {
    int l, r;
    bool operator<(const Node &rhs) const {
        if (l != rhs.l) return l < rhs.l;
        else return r < rhs.r;
    }
};
struct Interval {
    int l, r, len, type; // type equals to -1 or 1
    Interval() {}
    Interval(int a, int b, int c, int d): l(a), r(b), len(c), type(d) {}
};
vector<Interval> v;
Node a[maxn];
ll ans = 0;

// return the position of next interval to be solved
int solve(int cur) {
    int curL = v[cur].l, curR = v[cur].r, numOfOne = v[cur].len, p = cur;
    // while (p - 2 >= 0 && v[p - 2].len + numOfOne > v[p - 1].len) {
    //     curL = v[p - 2].l;
    //     numOfOne += v[p - 2].len;
    //     p -= 2;
    // }
    while (p + 2 < (int)v.size() && v[p + 2].len + numOfOne > v[p + 1].len) {
        curR = v[p + 2].r;
        numOfOne += v[p + 2].len;
        p += 2;
    }

}

int main() {
    int n, lastL = 0, lastR = 0; scanf("%d", &n);
    // initw
    rep1(i, 1, n) scanf("%d%d", &a[i].l, &a[i].r);
    sot(a, n);
    rep1(i, 1, n) {
        int l = a[i].l, r = a[i].r;
        if (i == 1) {
            if (l) v.pb(0, l - 1, l, -1);
        }
        if (i > 1) v.pb(lastR + 1, l - 1, l - 1 - lastR, 0);
        v.pb(l, r, r - l + 1, 1);
        if (i == n) {
            if (r != 1e9 - 1) v.pb(r + 1, 1e9 - 1, 1e9 - 1 - r, 0);
        }
        lastL = l; lastR = r;
    }
    // for (auto i : v)
    //     cout << i.l << " " << i.r << " " << i.len << " " << i.type << endl;

    // solve
    int i; n = v.size();
    for (i = 0; i < n;) {
        if (v[i].type == -1) i++;
        else i = solve(i);
    }
    printf("%lld\n", ans);
    return 0;
}
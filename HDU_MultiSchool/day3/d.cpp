/*************************************************************************
*File Name: d.cpp
*Author: JHSeng
*zxc98567@163.com
*Created Time: Tue 30 Jul 2019 12:35:56 PM CST
 ************************************************************************/
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

const int maxn = 2e5 + 10;
vector<ll>v;
struct Node {
    ll w = 0;
} segt[maxn << 2];
ll a[maxn], sum[maxn];
int n, m, k;

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].w = 0;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    segt[curpos].w = 0;
}

void update(int curpos, int pos, int curl, int curr, ll x) {
    if (curl == curr) {
        segt[curpos].w = max(segt[curpos].w, x);
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(lson, pos, curl, mid, x);
    else update(rson, pos, mid + 1, curr, x);
    segt[curpos].w = max(segt[lson].w, segt[rson].w);
}

ll query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos].w;
    int mid = curl + curr >> 1; ll ret = 0;
    if (ql <= mid) ret = max(ret, query(lson, curl, mid, ql, qr));
    if (qr > mid) ret = max(ret, query(rson, mid + 1, curr, ql, qr));
    return ret;
}

int check(ll x) {
    build(1, 1, m);
    rep1(i, 1, n) {
        ll l = lower_bound(v.begin(), v.end(), sum[i] - x) - v.begin() + 1;
        ll r = lower_bound(v.begin(), v.end(), sum[i]) - v.begin() + 1;
        if (l > m) {
            if (sum[i] <= x) update(1, r, 1, m, 1);
            continue;
        }
        ll w = query(1, 1, m, l, m);
        if (w) update(1, r, 1, m, w + 1);
        else if (sum[i] <= x) update(1, r, 1, m, 1);
    }
    return query(1, 1, m, 1, m) >= k;
}

int main() {
    sum[0] = 0;
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        v.clear();
        rep1(i, 1, n) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            v.pb(sum[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        m = v.size();
        ll l = -1e14 - 10, r = 1e14 + 10, ans = 0;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (check(mid)) {
                ans = mid, r = mid - 1;
            } else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


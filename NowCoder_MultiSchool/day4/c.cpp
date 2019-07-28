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

const int maxn = 3e6 + 10;
ll a[maxn], b[maxn], s1[maxn], s2[maxn], ans = -1e18;
int n, l[maxn], r[maxn];

struct SegT {
    struct Node {
        ll maxx, minn;
    } node[maxn << 2];

    void build(ll *s, int curpos, int curl, int curr) {
        if (curl == curr) {
            node[curpos].maxx = node[curpos].minn = s[curl];
            return;
        }
        int mid = curl + curr >> 1;
        build(s, lson, curl, mid); build(s, rson, mid + 1, curr);
        node[curpos].maxx = max(node[lson].maxx, node[rson].maxx);
        node[curpos].minn = min(node[lson].minn, node[rson].minn);
    }

    ll queryMax(int curpos, int curl, int curr, int ql, int qr) {
        if (ql <= curl && curr <= qr) return node[curpos].maxx;
        int mid = curl + curr >> 1;
        if (qr <= mid) return queryMax(lson, curl, mid, ql, qr);
        if (ql > mid) return queryMax(rson, mid + 1, curr, ql, qr);
        return max(queryMax(lson, curl, mid, ql, mid), queryMax(rson, mid + 1, curr, mid + 1, qr));
    }

    ll queryMin(int curpos, int curl, int curr, int ql, int qr) {
        if (ql <= curl && curr <= qr) return node[curpos].minn;
        int mid = curl + curr >> 1;
        if (qr <= mid) return queryMin(lson, curl, mid, ql, qr);
        if (ql > mid) return queryMin(rson, mid + 1, curr, ql, qr);
        return min(queryMin(lson, curl, mid, ql, mid), queryMin(rson, mid + 1, curr, mid + 1, qr));
    }
} segt1, segt2;

void determinLR() {
    stack<int>st; st.push(1);
    l[1] = 1; r[n] = n;
    rep1(i, 2, n) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) l[i] = 1; else l[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(n);
    for (int i = n - 1; i >= 1; i--) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) r[i] = n; else r[i] = st.top() - 1;
        st.push(i);
    }
}

int main() {
    scanf("%d", &n);
    s1[0] = s2[n + 1] = 0;
    rep1(i, 1, n) scanf("%lld", &a[i]);
    rep1(i, 1, n) {
        scanf("%lld", &b[i]);
        s1[i] = s1[i - 1] + b[i];
    }
    for (int i = n; i >= 1; i--) s2[i] = s2[i + 1] + b[i];
    segt1.build(s1, 1, 1, n); segt2.build(s2, 1, 1, n);
    determinLR();
    rep1(i, 1, n) {
        if (a[i] >= 0) {
            ll lsum = segt2.queryMax(1, 1, n, l[i], i) - s2[i + 1], rsum = segt1.queryMax(1, 1, n, i, r[i]) - s1[i - 1];
            ll tmp = a[i] * (lsum + rsum - b[i]);
            ans = max(tmp, ans);
        } else {
            ll lsum = segt2.queryMin(1, 1, n, l[i], i) - s2[i + 1], rsum = segt1.queryMin(1, 1, n, i, r[i]) - s1[i - 1];
            ll tmp = a[i] * (lsum + rsum - b[i]);
            ans = max(ans, tmp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e5 + 10;
int n;
ll a[maxn], ans[maxn];

struct Node {
    ll val;
    int pos;
    Node() {}
    Node(ll x, int y): val(x), pos(y) {}
    bool operator<(const Node &rhs)const {
        if (val != rhs.val) return val < rhs.val;
        else return pos < rhs.pos;
    }
} segt[maxn << 2];

void maintain(int curpos) {
    if (segt[lson].val > segt[rson].val) {
        segt[curpos].val = segt[rson].val;
        segt[curpos].pos = segt[rson].pos;
    } else {
        segt[curpos].val = segt[lson].val;
        segt[curpos].pos = segt[lson].pos;
    }
}

void build(int curpos, int curl, int curr) {
    if (curl > curr) return;
    if (curl == curr) {
        segt[curpos].val = a[curl];
        segt[curpos].pos = curl;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

Node query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) return segt[curpos];
    int mid = curl + curr >> 1;
    Node minn = Node(1e9 + 7, 1);
    if (ql <= mid) {
        Node res = query(lson, curl, mid, ql, qr);
        if (res.val < minn.val) {
            minn.val = res.val, minn.pos = res.pos;
        }
    }
    if (qr > mid) {
        Node res = query(rson, mid + 1, curr, ql, qr);
        if (res.val < minn.val) {
            minn.val = res.val, minn.pos = res.pos;
        }
    }
    maintain(curpos);
    return minn;
}

ll solve(int l, int r) {
    if (l > r) return 0LL;
    if (l == r) {
        ans[l] = a[l];
        return a[l];
    }
    Node minn = query(1, 1, n, l, r);
    ll sum1 = solve(l, minn.pos - 1), sum2 = solve(minn.pos + 1, r);
    if (1LL * (r - minn.pos + 1) * minn.val + minn.val + sum1 > 1LL * (minn.pos - l + 1) * minn.val + minn.val + sum2) {
        for (int i = minn.pos; i <= r; i++) ans[i] = minn.val;
        return 1LL * (r - minn.pos - 1 + 1) * minn.val + minn.val + sum1;
    } else {
        for (int i = l; i <= minn.pos; i++) ans[i] = minn.val;
        return 1LL * (minn.pos - 1 - l + 1) * minn.val + minn.val + sum2;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    solve(1, n);
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    puts("");
    return 0;
}
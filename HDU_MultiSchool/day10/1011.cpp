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

const int maxn = 3e5 + 10;

struct Node {
    int maxx, pos;
} segt[maxn << 2];
int n, k, a[maxn], vis[maxn], pre[maxn], suf[maxn];

void maintain(int curpos) {
    segt[curpos].maxx = max(segt[lson].maxx, segt[rson].maxx);
    segt[curpos].pos = segt[lson].maxx > segt[rson].maxx ? segt[lson].pos : segt[rson].pos;
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxx = a[curl];
        segt[curpos].pos = curl;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

int query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos].pos;
    int mid = curl + curr >> 1, lpos = -1, rpos = -1;
    if (ql <= mid) lpos = query(lson, curl, mid, ql, qr);
    if (mid < qr) rpos = query(rson, mid + 1, curr, ql, qr);
    if (lpos == -1) return rpos;
    else if (rpos == -1) return lpos;
    else return a[lpos] > a[rpos] ? lpos : rpos;
}

void dfs(int l, int r, ll &ans) {
    if (l > r) return;
    int mid = query(1, 1, n, l, r), len = max(1, a[mid] - k); // mid是区间[l,r]最大值的位置，len是最小长度
    if (mid - l <= r - mid) { // 最大值位置更靠左时，枚举最大值左侧元素作为区间左端点并维护答案
        for (int i = l; i <= mid; i++) {
            int L = max(mid, i + len - 1), R = min(pre[i], r);
            ans += max(0, R - L + 1);
        }
    } else {
        for (int i = mid; i <= r; i++) {
            int L = max(suf[i], l), R = min(mid, i - len + 1);
            ans += max(0, R - L + 1);
        }
    }
    dfs(l, mid - 1, ans); dfs(mid + 1, r, ans);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        int pos = 0;
        for (int i = 1; i <= n; i++) { // 计算从当前位置开始，向右延伸最远到什么位置，区间内的元素依然unique
            while (pos < n && !vis[a[pos + 1]]) {
                pos++;
                vis[a[pos]] = true;
            }
            pre[i] = pos;
            vis[a[i]] = false;
        }
        pos = n + 1;
        for (int i = n; i >= 1; i--) {
            while (pos > 1 && !vis[a[pos - 1]]) {
                pos--;
                vis[a[pos]] = true;
            }
            suf[i] = pos;
            vis[a[i]] = false;
        }
        ll ans = 0;
        dfs(1, n, ans);
        printf("%lld\n", ans);
    }
    return 0;
}

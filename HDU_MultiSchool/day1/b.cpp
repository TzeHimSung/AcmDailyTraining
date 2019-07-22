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

const int maxn = 1e5 + 10;
struct Node {
    Node() {}
    int l, r, sum;
};
Node segt[maxn * 25];
vector<int>v;
int n, m, cnt = 0, root[maxn], lastAns = 0, rootP = 0;
ll a[maxn];

int getid(ll x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int curl, int curr, int &cur, int last, int pos) {
    cnt++;
    segt[cnt] = segt[last];
    segt[cnt].sum++;
    cur = cnt;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    if (mid >= pos) update(curl, mid, segt[cur].l, segt[last].l, pos);
    else update(mid + 1, curr, segt[cur].r, segt[last].r, pos);
}

void init() {
    cnt = lastAns = rootP = 0;
    rep0(i, 0, maxn) root[i] = a[i] = 0;
    v.clear();
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d%d", &n, &m);
        rep1(i, 1, n) {
            scanf("%d", &a[i]);
            v.pb(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        rep1(i, 1, n) {
            update(1, n, root[i], root[i - 1], getid(a[i]));
        }
        rootP = a[0] = n;
        rep1(i, 1, m) {
            int op; scanf("%d", &op);
            if (!op) {
                int l, r; scanf("%d%d", &l, &r);

            } else {
                int val; scanf("%d", &val);
                rootP++; a[++a[0]] = val;
                int pos = lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
                if (v[pos] != val) v.insert(pos, val);
                update(1, n, root[rootP], root[rootP - 1], getid(val));
            }
        }
    }
    return 0;
}
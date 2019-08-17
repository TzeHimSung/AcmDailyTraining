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

const int maxn = 1e5 + 10;
int cntX[maxn], cntY[maxn];
ll sumX[maxn], sumY[maxn];
int n, r;
map<pair<int, int>, int>m;

struct SegmentTree {
    struct Node {
        int num;
        ll sum;
    } mem[maxn << 2];

    void maintain(int curpos) {
        if (mem[lson].sum > mem[rson].sum) {
            mem[curpos].num = mem[lson].num;
            mem[curpos].sum = mem[lson].sum;
        } else {
            mem[curpos].num = mem[rson].num;
            mem[curpos].sum = mem[rson].sum;
        }
    }

    void build(ll *a, int curpos, int curl, int curr) {
        if (curl == curr) {
            mem[curpos].num = curl;
            mem[curpos].sum = a[curl];
            return;
        }
        int mid = curl + curr >> 1;
        build(a, lson, curl, mid); build(a, rson, mid + 1, curr);
        maintain(curpos);
    }
} seg1, seg2;

int main() {
    m.clear();
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) cntX[i] = cntY[i] = sumX[i] = sumY[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        cntX[i]++, cntY[i]++;
        if (!m.count(mp(x, y))) m[mp(x, y)] = 1;
        else m[mp(x, y)]++;
    }
    for (int i = 0; i <= 1e5; i++) {
        sumX[i] = cntX[i], sumY[i] = cntY[i];
        if (i - r >= 1) sumX[i] += cntX[i - r], sumY[i] += cntY[i - r];
        if (i + r <= 100000) sumX[i] += cntX[i + r], sumY[i] += cntY[i + r];
    }
    seg1.build(sumX, 1, 0, 100000);
    seg2.build(sumY, 1, 0, 100000);
    ll ans = seg1.mem[1].sum + seg2.mem[1].sum;
    if (seg1.mem[1].num - r >= 1 && seg2.mem[1].num - r >= 1) ans -= m[mp(seg1.mem[1].num - r, seg2.mem[1].num - r)];
    if (seg1.mem[1].num + r <= 100000 && seg2.mem[1].num + r <= 100000) ans -= m[mp(seg1.mem[1].num + r, seg2.mem[1].num + r)];
    printf("%lld\n", ans);
    return 0;
}
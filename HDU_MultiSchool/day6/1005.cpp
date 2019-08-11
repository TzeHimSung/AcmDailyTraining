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

const int maxn = 2e3 + 10, maxm = 4e3 + 10;
struct Point {
    int x, y, weight;
    bool operator<(cosnt Point &rhs)const {
        return x < rhs.x;
    }
} point[maxn];

struct Node {
    int pre, suf, s, v;
} segt[maxn * 2];

int pos[maxn];

void build(int curpos, int curl, int curr) {
    segt[curpos].pre = segt[curpos].suf = segt[curpos].s = segt[curpos].v = 0;
    if (curl == curr) {
        pos[curl] = curpos;
        return ;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
}

void update(int curpos, int p) {
    curpos = pos[curpos];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, tot = 0, b[maxn];
        ll nas = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].weight);
            b[++tot] = point[i].y;
        }
        sort(b + 1, b + 1 + tot);

    }
    return 0;
}
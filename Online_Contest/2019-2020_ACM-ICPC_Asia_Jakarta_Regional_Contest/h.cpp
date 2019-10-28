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
struct Square {
    int l, w;
    ll area;
    Square() {}
    Square(int _l, int _w): l(_l), w(_w) {}
    bool operator<(const Square &rhs)const {
        return l < rhs.l;
    }
} a[maxn];
struct Node {
    int maxx, pos;
    Node() {}
} segt[maxn << 2];
int n;
double ans = 0;

void maintain(int curpos) {
    segt[curpos].maxx = max(segt[lson].maxx, segt[rson].maxx);
    segt[curpos].pos = segt[lson].maxx > segt[rson].maxx ? segt[lson].pos : segt[rson].pos;
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxx = a[curl].w;
        segt[curpos].pos = curl;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

pair<int, int> query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) {
        return mp(segt[curpos].maxx, segt[curpos].pos);
    }
    int mid = curl + curr >> 1;
    if (qr <= mid) return query(lson, curl, mid, ql, qr);
    else if (ql > mid) return query(rson, mid + 1, curr, ql, qr);
    pair<int, int> p1 = query(lson, curl, mid, ql, mid), p2 = query(rson, mid + 1, curr, mid + 1, qr);
    return p1.first > p2.first ? p1 : p2;
}

int main() {
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].l, &a[i].w);
        a[i].area = (ll)a[i].l * a[i].w;
        ans = max(ans, double(a[i].area) / 2.0);
    }
    sot(a, n);
    build(1, 1, n);
    for (int i = 1; i < n; i++) {
        pair<int, int> curP = query(1, 1, n, i + 1, n);
        ans = max(ans, min(double(a[i].l), double(a[curP.second].l)) * min(double(a[i].w), double(a[curP.second].w)));
        ans = max(ans, min(double(a[i].w), double(a[curP.second].l)) * min(double(a[i].l), double(a[curP.second].w)));
    }
    printf("%.1f\n", ans);
    fclose(stdin);
    return 0;
}
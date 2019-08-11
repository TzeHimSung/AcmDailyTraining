#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define MOD 1000000007
#define N 2005
#define ll long long
using namespace std;
ll sum[N * 4], maxv[N * 4], Prev[N * 4], sufv[N * 4];
void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    maxv[rt] = max(maxv[rt], sufv[rt << 1] + Prev[rt << 1 | 1]);
    Prev[rt] = max(Prev[rt << 1], sum[rt << 1] + Prev[rt << 1 | 1]);
    sufv[rt] = max(sufv[rt << 1 | 1], sum[rt << 1 | 1] + sufv[rt << 1]);
}
void build(int rt, int l, int r) {
    if (l == r) {
        maxv[rt] = Prev[rt] = sufv[rt] = sum[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, ll v) {
    if (l == r) {
        sum[rt] += v;
        maxv[rt] = Prev[rt] = sufv[rt] = max(0ll, sum[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, v);    else update(rt << 1 | 1, mid + 1, r, pos, v);
    pushup(rt);
}
ll query() {
    return maxv[1];
}
struct node {
    int x, y, c;
    bool operator < (const node &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} p[N];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        vector <int> keyx;
        vector <int> keyy;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
            keyx.push_back(p[i].x);
            keyy.push_back(p[i].y);
        }
        sort(keyx.begin(), keyx.end());
        sort(keyy.begin(), keyy.end());
        int pp = unique(keyx.begin(), keyx.end()) - keyx.begin();
        int qq = unique(keyy.begin(), keyy.end()) - keyy.begin();
        for (int i = 0; i < n; i++) {
            p[i].x = lower_bound(keyx.begin(), keyx.begin() + pp, p[i].x) - keyx.begin() + 1;
            p[i].y = lower_bound(keyy.begin(), keyy.begin() + qq, p[i].y) - keyy.begin() + 1;
        }
        sort(p, p + n);
        ll ans = 0;
        for (int i = 0; i < pp; i++) {
            int x = i + 1;
            int tmp = 0;
            while (tmp < n && p[tmp].x < x) tmp++;
            build(1, 1, qq);
            while (tmp < n) {
                int curx = p[tmp].x;
                while (tmp < n && p[tmp].x == curx) {
                    update(1, 1, qq, p[tmp].y, p[tmp].c);
                    tmp++;
                }
                ans = max(ans, query());
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
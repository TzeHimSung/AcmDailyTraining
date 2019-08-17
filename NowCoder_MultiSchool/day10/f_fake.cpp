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
int n, r;
struct Point {
    int x, y;
    Point() {}
    Point(int a, int b): x(a), y(b) {}
    bool operator<(const Point &rhs)const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};
vector<int>keyX, keyY;
vector<Point>v;
map<pair<int, int>, int>mulCnt;
map<int, int>cntX, cntY;

int main() {
    keyX.clear(), keyY.clear(), v.clear(), mulCnt.clear(), cntX.clear(), cntY.clear();
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) {
        int p, q; scanf("%d%d", &p, &q);
        v.pb(Point(p, q));
        keyX.pb(p), keyY.pb(q);
    }
    sort(v.begin(), v.end());
    sort(keyX.begin(), keyX.end());
    sort(keyY.begin(), keyY.end());
    keyX.erase(unique(keyX.begin(), keyX.end()), keyX.end());
    keyY.erase(unique(keyY.begin(), keyY.end()), keyY.end());
    int _t = v.size();
    for (int i = 0; i < _t; i++) {
        v[i].x = lower_bound(keyX.begin(), keyX.end(), v[i].x) - keyX.begin();
        v[i].y = lower_bound(keyY.begin(), keyY.end(), v[i].y) - keyY.begin();
    }
    for (auto i : v) {
        if (!mulCnt.count(mp(i.x, i.y))) mulCnt[mp(i.x, i.y)] = 1;
        else mulCnt[mp(i.x, i.y)]++;
        cntX[i.x]++, cntY[i.y]++;
    }

    return 0;
}
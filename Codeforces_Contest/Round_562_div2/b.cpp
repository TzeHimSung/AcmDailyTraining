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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 3e5 + 10;
int n, m, cnt[maxn];
vector<pair<int, int>>v;

int check(int x) {
    rep0(i, 0, maxn) cnt[i] = 0;
    int s = 0;
    rep0(i, 0, m)
    if (v[i].first != x && v[i].second != x) {
        cnt[v[i].first]++, cnt[v[i].second]++;
        s++;
    }
    rep1(i, 1, n)
    if (cnt[i] == s)
        return 1;
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, m) {
        int x, y; scanf("%d%d", &x, &y);
        v.pb(mp(x, y));
    }
    if (check((*v.begin()).first) || check((*v.begin()).second))
        puts("YES");
    else puts("NO");
    return 0;
}
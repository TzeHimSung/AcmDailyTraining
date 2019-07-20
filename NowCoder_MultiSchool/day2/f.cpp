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

struct Edge {
    int from, to, weight;
    Edge() {}
    Edge(int a, int b, int c) {
        if (a < b) from = a, to = b;
        else to = a, from = b;
        weight = c;
    }
    bool operator<(const Edge &rhs)const {
        if (weight != rhs.weight) return weight > rhs.weight;
        else return from < rhs.from;
    }
};
vector<Edge>v;
const int maxn = 20;
int n, vis[maxn];
map<pair<int, int>, int>cnt;
ll ans = 0;

int main() {
    cnt.clear();
    scanf("%d", &n);
    n *= 2;
    rep1(i, 1, n) {
        rep1(j, 1, n) {
            int k; scanf("%d", &k);
            if (i == j) continue;
            int aa = min(i, j), bb = max(i, j);
            if (!cnt.count(mp(aa, bb))) {
                v.pb(aa, bb, k);
                cnt[mp(aa, bb)] = 1;
            } else continue;
        }
    }
    sort(v.begin(), v.end());
    memset(vis, -1, sizeof(vis));
    int num[2] = {0}; //num of color
    for (auto i : v) {
        if (vis[i.from] != -1 && vis[i.to] != -1) continue;
        else {
            ans += i.weight;
            if (num[0] == n / 2) {
                if (vis[i.from] == 0) {
                    vis[i.to] = 1;
                    num[1]++;
                } else {
                    vis[i.from] = 1;
                    num[1]++;
                }
            } else if (num[1] == n / 2) {
                if (vis[i.from] == 1) {
                    vis[i.to] = 0;
                    num[0]++;
                } else {
                    vis[i.from] = 0;
                    num[0]++;
                }
            } else {
                if (vis[i.from] == 1 || vis[i.from] == 0) {
                    vis[i.to] = vis[i.from] ^ 1;
                    num[vis[i.to]]++;
                } else if (vis[i.to] == 1 || vis[i.to] == 0) {
                    vis[i.from] = vis[i.to] ^ 1;
                    num[vis[i.from]]++;
                } else {
                    vis[i.from] = 1; vis[i.to] = 0;
                    num[0]++; num[1]++;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
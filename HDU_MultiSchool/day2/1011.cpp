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
priority_queue<int, vector<int>>q;
ll curCir = -1;

void maintain() {
    multiset<int>tmp; tmp.clear();
    int firstL = 0, secondL = 0;

    if (q.empty()) return;
    else {
        firstL = q.top(); tmp.insert(firstL);
        q.pop();
    }
    if (q.empty()) return;
    else {
        secondL = q.top(); tmp.insert(secondL);
        q.pop();
    }
    while (!q.empty()) {
        int curr = q.top();
        if (firstL - secondL < curr) {
            curCir = firstL + secondL + curr;
            break;
        } else {
            q.pop();
            tmp.insert(curr);
        }
    }
    for (auto i : tmp) q.push(i);
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        // init
        int a[maxn];
        ll ans[maxn];
        vector<pair<int, pair<int, int>>>v; // length l r
        map<pair<int, int>, int> pos;
        curCir = -1;
        while (!q.empty()) q.pop();
        pos.clear();
        // input
        rep1(i, 1, n) scanf("%d", &a[i]);
        rep1(i, 1, m) {
            int l, r; scanf("%d%d", &l, &r);
            if (l > r) swap(l, r);
            v.pb(mp(r - l + 1, mp(l, r))); pos[mp(l, r)] = i;
        }
        sort(v.begin(), v.end());
        int curl = (*v.begin()).second.first, curr = (*v.begin()).second.second;
        // init state
        rep1(i, curl, curr) q.push(a[i]);
        maintain();
        ans[pos[(*v.begin()).second]] = curCir;
        v.erase(v.begin());
        // enlarge interval
        for (auto it : v) {
            while (it.second.first < curl) {
                q.push(a[--curl]);
                maintain();
            }
            while (it.second.first > curl) {

                q.push(a[++curl]);
                maintain();
            }
            while (it.second.second < curr) {

                q.push(a[--curr]);
                maintain();
            }
            while (it.second.second > curr) {
                q.push(a[++curr]);
                maintain();
            }
            ans[pos[it.second]] = curCir;
        }
        rep1(i, 1, m) printf("%lld\n", ans[i]);
    }
    return 0;
}
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

int l, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

int main() {
    while (!q.empty()) q.pop();
    scanf("%d%d", &l, &m);
    l += 1;
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        q.push(mp(x, y));
    }
    while (1) {
        auto top = q.top();
        q.pop();
        if (q.empty()) {
            l -= top.second - top.first + 1;
            break;
        }
        auto top2 = q.top();
        if (top.second >= top2.first) {
            q.pop();
            q.push(mp(min(top.first, top2.first), max(top.second, top2.second)));
        } else l -= top.second - top.first + 1;
    }
    printf("%d\n", l);
    return 0;
}
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
// const int maxn = 5;
struct Job {
    int earn, wait;
    bool operator<(const Job &rhs)const {
        if (wait != rhs.wait) return wait < rhs.wait;
        else return earn > rhs.earn;
    }
} a[maxn];
int n, m, tot = 0, p = 0;
ll ans = 0;

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) {
        int earn, wait; scanf("%d%d", &wait, &earn);
        if (wait > m) continue;
        a[++tot].wait = wait; a[tot].earn = earn;
    }
    int p = 0;
    sort(a + 1, a + 1 + tot);
    priority_queue<int>q;
    while (!q.empty()) q.pop();
    for (int reDay = 1; reDay <= m && p <= tot; reDay++) {
        while (p < tot && a[p + 1].wait <= reDay) {
            p++; q.push(a[p].earn);
        }
        if (!q.empty()) ans += (ll)q.top();
        if (!q.empty()) q.pop();
    }
    printf("%lld\n", ans);
    return 0;
}
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
int n, curr = 0, benefit = 0;
struct Node {
    int w, cost;
} a[maxn];
ll ans = 0;

int main() {
    scanf("%d%d", &n, &curr);
    rep1(i, 1, n) scanf("%d", &a[i].w);
    scanf("%d", &benefit);
    rep1(i, 1, n) scanf("%d", &a[i].cost);
    int flag = 1;
    priority_queue<int, vector<int>, greater<int>>q;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) {
        q.push(a[i].cost);
        while (!q.empty() && curr < a[i].w) {
            curr += benefit;
            ans += q.top();
            q.pop();
        }
        if (curr < a[i].w) {
            flag = 0;
            break;
        }
    }
    if (!flag) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}

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

const int maxn = 2e5 + 10;
ll a[maxn];

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        ll n, m, ans[maxn], currSum = 0;
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        priority_queue<ll>q;
        priority_queue<ll, vector<ll>, greater<ll>>p;
        while (!q.empty()) q.pop();
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (currSum + a[i] <= m) {
                q.push(a[i]);
                currSum += a[i];
            } else {
                ll tmp = a[i - 1], _size = q.size();
                while (!p.empty() && tmp >= p.top()) {
                    tmp -= p.top(); currSum += p.top();
                    cnt--;
                    p.pop();
                }
                while (!q.empty() && currSum + a[i] > m) {
                    currSum -= q.top(); p.push(q.top());
                    q.pop();
                    cnt++;
                }
                if (a[i] <= m) {
                    q.push(a[i]); currSum += a[i];
                } else cnt++;
            }
            ans[i] = cnt;
        }
        for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        puts("");
    }
    return 0;
}
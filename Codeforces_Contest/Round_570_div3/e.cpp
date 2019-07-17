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

int n, k;
ll ans = 0;
string s;
queue<string>q;
set<string>ss;

int main() {
    cin >> n >> k >> s;
    q.push(s); ss.insert(s);
    while (!q.empty() && (int)ss.size() < k) {
        auto curr = q.front();
        q.pop();
        rep1(i, 0, (int)curr.size()) {
            string tmp = curr;
            tmp.erase(i, 1);
            if (ss.find(tmp) == ss.end() && ss.size() < k) {
                q.push(tmp); ss.insert(tmp); ans += n - tmp.size();
            }
        }
    }
    if ((int)ss.size() < k) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}
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
int n, k, cnt[maxn], a[maxn], in[maxn], ans[maxn];

int main() {
    for (int i = 0; i < maxn; i++) cnt[i] = in[i] = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    stack<int>s;
    s.push(a[1]); cnt[a[1]]--; in[a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        cnt[a[i]]--;
        if (in[a[i]]) continue;
        for (; !s.empty() && a[i] < s.top() && cnt[s.top()];) {
            in[s.top()] = 0;
            s.pop();
        }
        s.push(a[i]);
        in[a[i]] = 1;
    }
    for (int i = k; i >= 1; i--) ans[i] = s.top(), s.pop();
    for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}
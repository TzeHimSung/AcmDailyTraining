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

int n, I, k, K = 1, total = 0, ans;
map<int, int>cnt;
vector<pair<int, int>>v;

int main() {
    scanf("%d%d", &n, &I); k = (I << 3) / n;
    rep1(i, 1, k) {
        K <<= 1;
        if (K > n) break;
    }
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (auto i : cnt) v.pb(i);
    for (int i = 0; i < min(K, (int)v.size()); i++)
        total += v[i].second;
    ans = total;
    for (int i = K; i < (int)v.size(); i++)
        total = total + v[i].second - v[i - K].second, ans = max(ans, total);
    printf("%d\n", n - ans);
    return 0;
}
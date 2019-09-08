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
vector<pair<pair<int, int>, int>>interval;
int n, q;
char s[maxn];

int main() {
    interval.clear();
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        interval.pb(mp(mp(l, r), i));
    }

    return 0;
}
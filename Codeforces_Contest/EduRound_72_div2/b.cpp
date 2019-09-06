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

const int maxn = 200;
pair<int, int>cut[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, head, maxx = 0;
        scanf("%d%d", &n, &head);
        rep1(i, 1, n) {
            int a, b; scanf("%d%d", &a, &b);
            maxx = max(a, maxx);
            cut[i].first = a - b, cut[i].second = a;
        }
        head -= maxx;
        sort(cut + 1, cut + 1 + n, greater<pair<int, int>>());
        if (head <= 0) {
            puts("1");
            continue;
        }
        if (cut[1].first <= 0) {
            puts("-1");
            continue;
        }
        int ans = head / cut[1].first + 1;
        if (head % cut[1].first) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

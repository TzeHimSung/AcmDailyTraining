#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

pii h[200010];
int v1[200010], v2[200010];
int main() {
    int n;
    scanf("%d", &n);
    int cnth = 0, cntv = 0;
    for (int i = 1; i <= n; i++) {
        char s[10];
        int x, y, z;
        scanf("%s%d%d%d", s + 1, &x, &y, &z);
        if (s[1] == 'h')
            h[++cnth] = make_pair(x - z, x - z + y - 1);
        else {
            v1[++cntv] = x - z;
            v2[cntv] = x - z + y - 1;
        }
    }
    sort(v1 + 1, v1 + 1 + cntv);
    sort(v2 + 1, v2 + 1 + cntv);
    ll ans = 0;
    for (int i = 1; i <= cnth; i++) {
        int l, r;
        l = lower_bound(v2 + 1, v2 + 1 + cntv, h[i].ff) - v2;
        r = upper_bound(v1 + 1, v1 + 1 + cntv, h[i].ss) - v1;
        ans += r - l;
    }
    printf("%lld\n", ans);
}
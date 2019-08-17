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

int d[10], d2[10];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        vector<int>a[10];
        for (int i = 0; i < 7; i++) {
            d[i] = d2[i] = 0; a[i].clear();
        }
        for (int i = 1; i <= 5; i++) {
            int x, y; scanf("%d%d", &x, &y);
            d2[x]++, d2[y]++; d[x]++, d[y]++;
            a[x].pb(y), a[y].pb(x);
        }
        sort(d2 + 1, d2 + 7);
        if (d2[6] == 2) puts("n-hexane"); //
        else if (d2[6] == 4) puts("2,2-dimethylbutane"); //
        else if (d2[4] == 1) puts("2,3-dimethylbutane"); //
        else {
            int pos;
            for (pos = 1; pos < 7; pos++)
                if (d[pos] == 3) break;
            // sort(a[pos].begin(), a[pos].end());
            if (d[a[pos][0]] + d[a[pos][1]] + d[a[pos][2]] == 4) puts("2-methylpentane");
            else if (d[a[pos][0]] + d[a[pos][1]] + d[a[pos][2]] == 5) puts("3-methylpentane");
        }
    }
    return 0;
}
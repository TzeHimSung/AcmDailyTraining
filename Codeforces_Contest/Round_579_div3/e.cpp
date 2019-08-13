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

int n, ans = 0;
vector<int>a;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a.pb(x);
    }
    sort(a.begin(), a.end());
    int last = 0;
    for (auto i : a) {
        if (i - 1 > last) ans++, last = i - 1;
        else if (i - 1 == last) ans++, last = i;
        else if (i == last) ans++, last = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}
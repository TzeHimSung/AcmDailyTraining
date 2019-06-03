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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 15;
int t, a[maxn];

int check(set<int> &s) {
    int b[maxn],p=0;
    for (auto i:s) b[++p]=i;
    for (int i=1;i<=p;i++)
        for (int j=i+1;j<=p;j++)
            if (__gcd(b[i],b[j])>1) return 0;
    return 1;
}

int main() {
    cin >> t;
    while (t--) {
        int n, ans = 1;
        cin >> n;
        rep1(i, 1, n) cin >> a[i];
        for (int cnt = 1; cnt < (1 << n); cnt++) {
            int tmp = cnt;
            set<int>s; s.clear();
            rep1(i, 1, n) {
                if (tmp & 1) s.insert(a[i]);
                tmp >>= 1;
            }
            if (check(s)) ans = max(ans, (int)s.size());
        }
        cout << ans << endl;
    }
    return 0;
}
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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

vector<int>v[26];
string a, b;
int n, m, p = 0;

int main() {
    cin >> n >> a;
    for (auto i : a) v[i - 'a'].pb(++p);
    cin >> m;
    while (m--) {
        cin >> b;
        int cnt[26] = {0};
        for (auto i : b) cnt[i - 'a']++;
        int ans = 0;
        rep0(i, 0, 26)
        if (cnt[i]) ans = max(ans, v[i][cnt[i] - 1]);
        printf("%d\n", ans);
    }
    return 0;
}
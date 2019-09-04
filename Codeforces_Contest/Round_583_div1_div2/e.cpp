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

pair<int, int>a[maxn];
vector<int>s;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = 2 * i - 1;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    s.resize(1);
    for (int i = 1; i <= n; i++) s.push_back(a[i].second);
    for (int i = 1; i <= n - 1; i++) printf("%d %d\n", a[i].second, a[i + 1].second);
    for (int i = 1; i <= n; i++) {
        int j = i + a[i].first - 1;
        printf("%d %d\n", a[i].second + 1, s[j]);
        if (j == (int)s.size() - 1) s.push_back(a[i].second + 1);
    }
    return 0;
}
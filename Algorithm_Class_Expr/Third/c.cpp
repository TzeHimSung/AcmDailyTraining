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

const int maxn = 1e5 + 10;
struct Node {
    int s, f;
    bool operator<(const Node &rhs)const {
        return f < rhs.f;
    }
} a[maxn];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].s, &a[i].f);
    sort(a, a + n);
    int ans = 1, j = 0;
    for (int i = 1; i < n; i++)
        if (a[i].s > a[j].f) {
            j = i; ans++;
        }
    printf("%d\n", ans);
    return 0;
}
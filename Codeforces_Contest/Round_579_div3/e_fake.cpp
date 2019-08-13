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

const int maxn = 150010;
int a[maxn], p = 0;

int main() {
    set<int>s; s.clear();
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (!s.count(x)) s.insert(x);
        else a[++p] = x;
    }
    if (p) {
        sort(a + 1, a + 1 + p);
        for (int i = 1; i <= p; i++) {
            if (a[i] - 1 >= 1 && !s.count(a[i] - 1)) s.insert(a[i] - 1);
            else if (!s.count(a[i] + 1)) s.insert(a[i] + 1);
        }
    }
    printf("%d\n", (int)s.size());
    return 0;
}
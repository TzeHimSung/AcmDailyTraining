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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
stack<int>s1, s2;

int main() {
    a[0] = b[0] = 0;
    while (~scanf("%d", &n)) {
        rep1(i, 1, n) scanf("%d", &a[i]);
        rep1(i, 1, n) scanf("%d", &b[i]);
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        s1.push(1); s2.push(1);
        int p;
        for (p = 2; p <= n; p++) {
            int num = 0;
            while (!s1.empty() && a[p] < a[s1.top()]) num++, s1.pop();
            while (!s2.empty() && b[p] < b[s2.top()]) num--, s2.pop();
            if (num) break;
            s1.push(p); s2.push(p);
        }
        printf("%d\n", p - 1);
    }
    return 0;
}
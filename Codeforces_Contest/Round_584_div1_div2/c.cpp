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
int n, ans[maxn], a[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        rep1(i, 1, n) {
            scanf("%1d", &a[i]);
        }
        ans[1] = 1;
        rep1(i, 2, n) {
            if (a[i] >= a[i - 1]) ans[i] = ans[i - 1];
            else ans[i] = ans[i - 1] == 1 ? 2 : 1;
        }
        int flag = 1;
        stack<int>at, b;
        while (!at.empty()) at.pop();
        while (!b.empty()) b.pop();
        rep1(i, 1, n) {
            if (ans[i] == 1) {
                if (at.empty()) at.push(a[i]);
                else if (at.top() <= a[i]) at.push(a[i]); else flag = 0;
            } else {
                if (b.empty()) b.push(a[i]);
                else if (b.top() <= a[i]) b.push(a[i]); else flag = 0;
            }
        }
        if (!flag) puts("-");
        else {
            for (int i = 1; i <= n; i++) printf("%d", ans[i]);
            puts("");
        }
    }
    return 0;
}
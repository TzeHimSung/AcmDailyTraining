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
int t, n, a[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        int m = INT_MAX, k, mm = INT_MAX;
        set<int>pos, val; pos.clear(), val.clear();
        int maxx = -INT_MAX, minn = INT_MAX;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i > 1 && a[i - 1] != -1 && a[i] != -1) mm = min(mm, abs(a[i - 1] - a[i]));
            if (a[i] == -1) pos.insert(i);
            else maxx = max(maxx, a[i]), minn = min(minn, a[i]);
        }
        if ((int)pos.size() == n) {
            puts("0 0");
            continue;
        }
        for (auto i : pos) {
            if (i == 1) {
                int j;
                for (j = 2; j <= n; j++)
                    if (a[j] != -1) break;
                val.insert(a[j]);
            } else if (i == n) {
                int j;
                for (j = n - 1; j >= 1; j--)
                    if (a[j] != -1) break;
                val.insert(a[j]);
            } else {
                int p = i, q = i;
                for (p = i; p >= 1; p--)
                    if (a[p] != -1) break;
                for (q = i; q <= n; q++)
                    if (a[q] != -1) break;
                val.insert((a[p] + a[q]) / 2);
                val.insert((a[p] + a[q]) / 2 + 1);
            }
        }
        for (auto v : val) {
            int tmp = -1;
            for (auto p : pos) {
                if (p - 1 >= 1 && a[p - 1] != -1) tmp = max(tmp, abs(v - a[p - 1]));
                if (p + 1 <= n && a[p + 1] != -1) tmp = max(tmp, abs(v - a[p + 1]));
            }
            if (tmp < m) {
                m = tmp;
                k = v;
            }
        }
        printf("%d %d\n", mm == INT_MAX ? m : max(mm, m), k);
    }
    return 0;
}
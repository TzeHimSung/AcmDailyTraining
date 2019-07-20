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

const int maxn = 1e3 + 10;
char s[maxn][maxn];
int h[maxn], n, m, maxx = 0, maxx2 = 0, x, y;

int main() {
    scanf("%d%d", &n, &m);
    rep0(i, 0, n) scanf("%s", s[i]);
    rep0(i, 0, n) {
        rep0(j, 0, m) {
            if (s[i][j] == '1') h[j]++;
            else h[j] = 0;
        }
        stack<int>q;
        rep0(j, 0, m) {
            while (!q.empty() && h[j] <= h[q.top()]) {
                int l = q.top();
                q.pop();
                int k = q.empty() ? -1 : q.top(), sum = (j - k - 1) * h[l];
                if (sum > maxx) {
                    x = j - k - 1;
                    y = h[l];
                    maxx2 = maxx; maxx = sum;
                } else if (sum > maxx2) maxx2 = sum;
            }
            q.push(j);
        }
        if (!q.empty()) {
            int l = q.top();
            q.pop();
            int k = q.empty() ? -1 : q.top();
            int sum = (m - k - 1) * h[l];
            if (sum > maxx) {
                x = m - k - 1;
                y = h[l];
                maxx2 = maxx; maxx = sum;
            } else if (sum > maxx2) maxx2 = sum;
        }
    }
    int ans = max(max(maxx - x, maxx - y), maxx2);
    printf("%d\n", ans);
    return 0;
}
#include<bits/stdc++.h>
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pqueue priority_queue
#define NEW(a,b) memset(a,b,sizeof(a))
#define lowbit(x) (x&(-x))
const double pi = 4.0 * atan(1.0);
const double e = exp(1.0);
const int maxn = 2e7 + 8;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;
const ULL base = 1e7 + 7;
using namespace std;
int s[maxn];
int l[1000008], r[1000008];
int p[1000008];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + (r[i] - l[i] + 1) - (l[i] - r[i - 1] - 1);
    }
    for (int i = n - 1; i >= 1; i--) {
        p[i] = max(p[i], p[i + 1]);
    }
    LL sum = 0;
    int x = 0;
    int now = 0;
    int Zero = 1e7 + 3;
    s[Zero] = 1;
    int k = 0;
    int st = Zero;
    int L = Zero, R = Zero;
    for (int i = 1; i <= n; i++) {
        while (x < l[i]) {
            if (!now && k - p[i] < l[i] && k > p[i]) {
                x += k - p[i];
                k = p[i];
                st = L = Zero;
                R = Zero - 1;
            }
            x++;
            k--;
            if (--st < L) {
                L--;
                s[st] = 0;
            }
            now -= s[st]++;
            sum += now;
        }
        while (x <= r[i]) {
            x++;
            k++;
            now += s[st];
            sum += now;
            if (++st > R) {
                R++;
                s[st] = 0;
            }
            s[st]++;
        }
    }
    while (now > 0 && x < 1000000000 && st >= 0 && st <= 2 * Zero) {
        x++;
        now -= s[--st]++;
        sum += now;
    }
    cout << sum << endl;
}
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
struct Function {
    ll a, b;
    Function(int _a = 1, int _b = 0): a(_a), b(_b) {
        if (a < 0) a = -a, b = -b;
    }
    void simplicate() {
        if (!b) a = 1;
        else {
            ll gg = __gcd(a, abs(b));
            a /= gg, b /= gg;
        }
    }
    bool operator<(const Function &rhs) const {
        return b * rhs.a < a * rhs.b;
    }
    bool operator<=(const Function &rhs) const {
        return b * rhs.a <= a * rhs.b;
    }
    bool operator==(const Function &rhs) const {
        return b * rhs.a == a * rhs.b;
    }
} f[maxn];
int tot;

void solve() {
    int n; ll c; scanf("%d%lld", &n, &c); tot = 0;
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        b = -b;
        if (!a) c -= abs(b);
        else {
            if (a < 0) a = -a, b = -b;
            f[tot++] = Function(a, b);
        }
    }
    if (!tot) {
        if (!c) puts("-1"); else puts("0");
        return;
    }
    sort(f, f + tot);
    vector<Function> func;
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < tot; i++)
        sumA += f[i].a, sumB += f[i].b;
    {
        Function res(sumA, c + sumB);
        if (f[tot - 1] <= res) func.pb(res);
    }
    for (int i = tot - 1; i >= 0; i--) {
        sumA -= f[i].a * 2, sumB -= f[i].b * 2;
        if (!sumA) {
            if (!(sumB + c)) {
                if (f[i - 1] < f[i]) {
                    puts("-1");
                    return;
                }
            }
            continue;
        }
        Function res(sumA, c + sumB);
        if (i) {
            if (res <= f[i] && f[i - 1] <= res)
                func.pb(res);
        } else if (res <= f[i]) func.pb(res);
    }
    rep0(i, 0, (int)func.size()) func[i].simplicate();
    sort(func.begin(), func.end());
    func.resize(distance(func.begin(), unique(func.begin(), func.end())));
    printf("%d", (int)func.size());
    for (auto i : func) printf(" %lld/%lld", i.b, i.a);
    puts("");
}
int main() {
    int caseNum; scanf("%d", &caseNum);
    while (caseNum--) solve();
    return 0;
}

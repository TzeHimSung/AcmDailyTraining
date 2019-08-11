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

struct CombineSmall {
    int m;
    vector<vector<int>> F;
    CombineSmall(int n, int m): m(m), F(n) {
        for (int i = 1; i < n; i++) F[i].resize(i + 1);
    }
    int com(int n, int k) {
        return !k ? 1 : k > n ? 0 : k + k > n ? com(n, n - k) : F.at(n)[k] ? F[n][k] : F[n][k] = (com(n - 1, k) + com(n - 1, k - 1)) % m;
    }
};

int main() {
    int p; scanf("%d", &p);
    vector<int>b(p);
    CombineSmall cb(p, p);
    for (int i = 0; i < p; i++) {
        int ai; scanf("%d", &ai);
        if (!ai) continue;
        vector<int> pa(p); pa[0] = 1;
        for (int j = 1; j < p; j++) pa[j] = (ll)pa[j - 1] * i % p;
        b[0] = (b[0] + 1) % p;
        for (int j = 0; j < p; j++) {
            int cof = (ll)cb.com(p - 1, j) * pa[p - 1 - j] % p;
            if (~(p - 1 - j) & 1) cof = p - cof;
            b[j] = (b[j] + cof) % p;
        }
    }
    for (int i = 0; i < p; i++) printf("%d%c", b[i], i == p - 1 ? '\n' : ' ');
    return 0;
}
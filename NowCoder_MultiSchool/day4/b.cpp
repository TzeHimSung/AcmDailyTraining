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
struct LinerBase {
    int cnt;
    ll b[32];
    void init() {
        cnt = 0;
        memset(b, 0, sizeof(b));
    }
    int insert(ll x) {
        for (int i = 31; i >= 0; i--)
            if (x & (1ll << i)) {
                if (b[i]) x ^= b[i];
                else {
                    b[i] = x;
                    cnt++;
                    return 1;
                }
            }
        return 0;
    }
    bool check(ll x) {
        for (int i = 31; i >= 0; i--)
            if (x & (1ll << i)) x ^= b[i];
        return x == 0;
    }
}

int main() {
    /* main body */
    return 0;
}
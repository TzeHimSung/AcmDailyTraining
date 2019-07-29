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

// 不显式构造出集合B，支持动态插入
struct LinearBasis {
    static const int LBsize = 63;
    int cnt; ll b[LBsize];
    LinearBasis() {}
    // x为集合，n为集合元素个数
    LinearBasis(ll *x, int n) {
        build(x, n);
    }
    // 插入元素
    void insert(ll val) {
        for (int i = LBsize - 1; i >= 0; i--) {
            if (!val) return;
            if (!(val & (1ll << i))) continue;
            if (b[i]) val ^= b[i];
            else {
                for (int j = 0; j < i; j++)
                    if (val & (1ll << j)) val ^= b[j];
                for (int j = i + 1; j < LBsize; j++)
                    if (b[j] & (1ll << i)) b[j] ^= val;
                b[i] = val;
                break;
            }
        }
    }
    // 由现有集合建立线性基
    void build(ll *x, int n) {
        rep1(i, 1, n) insert(x[i]);
    }
    // 查询最大异或和
    ll queryMax() {
        ll ret = 0;
        for (int i = 0; i < LBsize; i++) ret ^= b[i];
        return ret;
    }
    // 从另一个线性基合并
    void mergeFrom(const LinearBasis &rhs) {
        rep0(i, 0, LBsize) insert(rhs.b[i]);
    }
    // 合并两个线性基
    static LinearBasis mergeLB(const LinearBasis &lhs, const LinearBasis &rhs) {
        LinearBasis ret = lhs;
        rep0(i, 0, LBsize) ret.insert(rhs.b[i]);
        return ret;
    }
};

const int LBsize = 1e4 + 10;
int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        int n; ll a[LBsize];
        scanf("%d", &n);
        rep1(i, 1, n) scanf("%lld", &a[i]);

    }
    return 0;
}
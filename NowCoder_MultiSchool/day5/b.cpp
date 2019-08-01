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

const int maxn = 1e6 + 10;
int x0, x1, a, b, mod;
char s[maxn];

struct Matrix {
    ll mem[2][2];
    void init() {
        memset(mem, 0, sizeof(mem));
    }
    Matrix operator*(const Matrix &rhs)const {
        Matrix ret; ret.init();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++)
                    ret.mem[i][j] += mem[i][k] * rhs.mem[k][j];
                ret.mem[i][j] %= mod;
            }
        }
        return ret;
    }
} mAns, mBase;

ll solve(char *s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int curr = s[i] - '0';
        while (curr--) mAns = mAns * mBase;
        Matrix tmp = mBase * mBase;
        mBase = tmp * tmp;
        mBase = mBase * mBase * tmp;
    }
    return mAns.mem[0][1];
}

int main() {
    mAns.init(), mBase.init();
    scanf("%d%d%d%d", &x0, &x1, &a, &b);
    scanf("%s %lld", s, &mod);
    mAns.mem[0][0] = x1, mAns.mem[0][1] = x0;
    mBase.mem[0][0] = a, mBase.mem[0][1] = 1, mBase.mem[1][0] = b;
    ll ans = solve(s);
    printf("%lld\n", ans);
    return 0;
}
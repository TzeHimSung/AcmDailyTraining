#include<bits/stdc++.h>
typedef long long ull;

using namespace std;

const int maxn = 1e6 + 10;
const ull mod = 998244353;

struct Matrix {
    ull mem[2][2];
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
unordered_map<ull, Matrix> M;

int tot = 0;
Matrix solve(ull n) {
    if (M.count(n)) return M[n];
    if (n == 1) {
        M[n] = mBase;
        return mBase;
    }
    Matrix ret = solve(n / 2ull);
    ret = ret * ret;
    if (n % 2ull == 1ull) ret = ret * mBase;
    return M[n] = ret;
}

int main() {
    ull q, n;
    cin >> q >> n;
    ull lastans = 0ull;
    ull ans = 0;
    for (int i = 1ull; i <= q; i++) {
        mAns.mem[0][0] = 1, mAns.mem[0][1] = 0;
        mBase.mem[0][0] = 3, mBase.mem[0][1] = 1, mBase.mem[1][0] = 2;
        if (i >= 2ull) n = (n ^ (ans * ans));
        Matrix val = solve(n % (mod - 1));
        ans = val.mem[0][1];
        lastans = (lastans ^ ans);
    }
    cout << lastans << endl;
    return 0;
}
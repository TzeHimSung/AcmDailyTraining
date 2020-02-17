/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
ll base[2] = {131LL, 313LL};
ll b[2][maxn], s[2][2][maxn << 2];
char str[2][maxn];
int T, n, m;

void op1(int pos, char sign) {
    if (str[0][pos0] == sign) return;
    int pos0 = pos, pos1 = n - pos + 1;
    ll delta = (sign - str[0][pos0] + mod) % mod;
    update(0, pos0, delta, 1, n, 1);
    update(1, pos1, delta, 1, n, 1);
    str[0][pos0] = sign;
    str[1][pos1] = sign;
}

void op2(int L, int R) {
    int L0 = L, R0 = R, L1 = n - R + 1, R1 = n - L + 1;
    ti
}

int main() {
    b[0][0] = 1LL; b[1][0] = 1LL;
    for (int i = 1; i < maxn; i++) {
        b[0][i] = b[0][i - 1] * base[0] % mod;
        b[1][i] = b[1][i - 1] * base[1] % mod;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(s, 0, sizeof(s));
        scanf("%s", str[0] + 1);
        for (int i = 1; i <= n; i++) str[1][i] = str[0][n - i + 1];
        for (int t = 0; t < 2; t++) {
            for (int i = 1; i <= n; i++) {
                update(t, i, (ll)(str[t][i] - 'a' + 1), 1, n, 1);
            }
        }
        while (m--) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                int pos; char sign[2]; scanf("%d%s", &pos, sign);
                op1(pos, sign[0]);
            } else {
                int l, r; scanf("%d%d", &l, &r);
                op2(l, r);
            }
        }
    }
    return 0;
}
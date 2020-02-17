#include <bits/stdc++.h>
#define ll long long
#define lson (curpos<<1)
#define rson (curpos<<1|1)
using namespace std;

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
ll base[2] = {131LL, 313LL};
ll b[2][maxn];
ll s[2][2][4 * maxn];
char str[2][maxn];
int T, n, m;

void maintain(int t, int curpos) {
    for (int i = 0; i < 2; i ++) {
        s[t][i][curpos] = (s[t][i][lson] + s[t][i][rson]) % mod;
    }
}

void update(int t, int pos, ll delta, int l, int r, int curpos) {
    if (l == r) {
        for (int i = 0; i < 2; i ++) {
            s[t][i][curpos] = (s[t][i][curpos] + (b[i][pos] * delta % mod)) % mod;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(t, pos, delta, l, mid, lson);
    else update(t, pos, delta, mid + 1, r, rson);
    maintain(t, curpos);
}

pair<ll, ll> sum(int t, int L, int R, int l, int r, int curpos) {
    if (L <= l && r <= R) {
        return make_pair(s[t][0][curpos], s[t][1][curpos]);
    }
    int mid = (l + r) / 2;
    pair<ll, ll> left = make_pair(0LL, 0LL);
    pair<ll, ll> right = make_pair(0LL, 0LL);
    if (L <= mid) left = sum(t, L, R, l, mid, lson);
    if (R > mid) right = sum(t, L, R, mid + 1, r, rson);
    return make_pair((left.first + right.first) % mod, (left.second + right.second) % mod);
}

void op1(int pos, char sign) {
    int pos0 = pos;
    int pos1 = n - pos + 1;
    if (str[0][pos0] == sign) {
        return;
    }
    ll delta = (sign - str[0][pos0] + mod) % mod;
    update(0, pos0, delta, 1, n, 1);
    update(1, pos1, delta, 1, n, 1);
    str[0][pos0] = sign;
    str[1][pos1] = sign;
}

void op2(int L, int R) {
    int L0 = L, R0 = R;
    int L1 = n - R + 1, R1 = n - L + 1;
    pair<ll, ll> pi0 = sum(0, L0, R0, 1, n, 1);
    pair<ll, ll> pi1 = sum(1, L1, R1, 1, n, 1);
    if (L0 <= L1) {
        pi0.first = pi0.first * b[0][L1 - L0] % mod;
        pi0.second = pi0.second * b[1][L1 - L0] % mod;
    } else {
        pi1.first = pi1.first * b[0][L0 - L1] % mod;
        pi1.second = pi1.second * b[1][L0 - L1] % mod;
    }
    if (pi0 == pi1) {
        printf("Adnan Wins\n");
    } else {
        printf("ARCNCD!\n");
    }
}

int main() {
    b[0][0] = 1LL;
    b[1][0] = 1LL;
    for (int i = 1; i < maxn; i ++) {
        b[0][i] = b[0][i - 1] * base[0] % mod;
        b[1][i] = b[1][i - 1] * base[1] % mod;
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        memset(s, 0, sizeof s);
        scanf("%s", str[0] + 1);
        for (int i = 1; i <= n; i ++) {
            str[1][i] = str[0][n - i + 1]; // str[1]是str[0]的reverse
        }
        for (int t = 0; t < 2; t ++) {
            for (int i = 1; i <= n; i ++) {
                update(t, i, (ll)(str[t][i] - 'a' + 1), 1, n, 1);
            }
        }
        while (m --) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                int pos;
                char sign[5];
                scanf("%d%s", &pos, sign);
                op1(pos, sign[0]);
            } else {
                int L, R;
                scanf("%d%d", &L, &R);
                op2(L, R);
            }
        }
    }
    return 0;
}
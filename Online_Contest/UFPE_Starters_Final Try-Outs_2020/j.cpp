#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

vector<pii> v[100010];
ll dp[100010][10];
const ll mod = 1e9 + 7;
int baoli2[20][2] = { 1, 2, 1, 3, 1, 4, 1, 5, 2, 1, 2, 3, 2, 4, 2, 5, 3, 1, 3, 2, 3, 4, 3, 5, 4, 1, 4, 2, 4, 3, 4, 5, 5, 1, 5, 2, 5, 3, 5, 4 };
int baoli3[60][3] = { 1, 2, 3, 1, 2, 4, 1, 2, 5, 1, 3, 2, 1, 3, 4, 1, 3, 5, 1, 4, 2, 1, 4, 3, 1, 4, 5, 1, 5, 2, 1, 5, 3, 1, 5, 4, 2, 1, 3, 2, 1, 4, 2, 1, 5, 2, 3, 1, 2, 3, 4, 2, 3, 5, 2, 4, 1, 2, 4, 3, 2, 4, 5, 2, 5, 1, 2, 5, 3, 2, 5, 4, 3, 1, 2, 3, 1, 4, 3, 1, 5, 3, 2, 1, 3, 2, 4, 3, 2, 5, 3, 4, 1, 3, 4, 2, 3, 4, 5, 3, 5, 1, 3, 5, 2, 3, 5, 4, 4, 1, 2, 4, 1, 3, 4, 1, 5, 4, 2, 1, 4, 2, 3, 4, 2, 5, 4, 3, 1, 4, 3, 2, 4, 3, 5, 4, 5, 1, 4, 5, 2, 4, 5, 3, 5, 1, 2, 5, 1, 3, 5, 1, 4, 5, 2, 1, 5, 2, 3, 5, 2, 4, 5, 3, 1, 5, 3, 2, 5, 3, 4, 5, 4, 1, 5, 4, 2, 5, 4, 3 };

void dfs(int x, int pre) {
    int col = 0;
    vector<int> nex;
    for (auto i : v[x])
        if (i.ff != pre) {
            dfs(i.ff, x);
            nex.push_back(i.ff);
        } else
            col = i.ss;
    int sz = v[x].size();
    if (pre == -1)
        return;

    if (sz == 1) {
        if (v[x][0].ss)
            dp[x][v[x][0].ss] = 1;
        else
            for (int i = 1; i <= 5; i++)
                dp[x][i] = 1;
        return;
    } else if (sz == 2) {
        for (int i = 0; i < 20; i++)
            if (!col || col == baoli2[i][1]) {
                dp[x][baoli2[i][1]] = (dp[x][baoli2[i][1]] + dp[nex[0]][baoli2[i][0]]) % mod;
            }
    } else if (sz == 3) {
        for (int i = 0; i < 60; i++)
            if (!col || col == baoli3[i][2]) {
                dp[x][baoli3[i][2]] = (dp[x][baoli3[i][2]] + dp[nex[0]][baoli3[i][0]] * dp[nex[1]][baoli3[i][1]] % mod) % mod;
            }
    } else {
        int a[10];
        for (int i = 1; i <= 5; i++)
            a[i] = i;
        do {
            if (!col || col == a[sz]) {
                ll tmp = 1;
                for (int i = 1; i <= sz - 1; i++)
                    tmp = tmp * dp[nex[i - 1]][a[i]] % mod;

                dp[x][a[sz]] = (dp[x][a[sz]] + tmp) % mod;
            }
        } while (next_permutation(a + 1, a + 1 + 5));
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back(mp(b, c));
        v[b].push_back(mp(a, c));
    }
    for (int i = 1; i <= n; i++)
        if (v[i].size() > 5) {
            printf("0\n");
            return 0;
        }
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n == 2) {
        if (v[1][0].ss)
            printf("1\n");
        else
            printf("5\n");
        return 0;
    }
    dfs(1, -1);

    ll ans = 0;
    vector<int> nex;
    for (auto i : v[1])
        nex.push_back(i.ff);
    if (v[1].size() == 1) {
        for (int i = 1; i <= 5; i++) {
            ans = (ans + dp[nex[0]][i]) % mod;
        }
    } else if (v[1].size() == 2) {
        for (int i = 0; i < 20; i++) {
            ll tmp = 1;
            for (int j = 0; j < 2; j++)
                tmp = tmp * dp[nex[j]][baoli2[i][j]] % mod;
            ans = (ans + tmp) % mod;
        }
    } else if (v[1].size() == 3) {
        for (int i = 0; i < 60; i++) {
            ll tmp = 1;
            for (int j = 0; j < 3; j++)
                tmp = tmp * dp[nex[j]][baoli3[i][j]] % mod;
            ans = (ans + tmp) % mod;
        }
    } else {
        int a[10], sz = v[1].size();
        for (int i = 1; i <= 5; i++)
            a[i] = i;
        do {
            ll tmp = 1;
            for (int i = 1; i <= sz; i++)
                tmp = tmp * dp[nex[i - 1]][a[i]] % mod;
            ans = (ans + tmp) % mod;
        } while (next_permutation(a + 1, a + 1 + 5));
    }

    printf("%lld\n", ans);
}
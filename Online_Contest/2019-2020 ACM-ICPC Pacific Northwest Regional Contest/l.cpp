#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

char s[30];
ll ans = 1e18;
const ll ansinf = 1e18;
int a[30], cal[15][15], len;
vector<pii> f[30];
void dfs(int x) {
    if (ans != ansinf)
        return;
    if (x == len - 1) {
        for (int i = 1; i <= len - 1; i++) {
            int tmp = 0;
            for (auto j : f[i])
                tmp += cal[a[j.ff]][a[j.ss]];
            if (tmp % 10 != s[i] - '0')
                return;
        }
        ans = 0;
        for (int i = len; i >= 1; i--)
            ans = ans * 10 + a[i];
        return;
    }
    for (int i = 0; i <= 9; i++) {
        int tmp = 0;
        a[x - len + 1] = i;
        for (auto j : f[x])
            tmp += cal[a[j.ff]][a[j.ss]];
        if (tmp % 10 == s[x] - '0') {
            dfs(x - 1);
        }
    }
}
int main() {
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            cal[i][j] = i * j % 10;

    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (n % 2 == 0) {
        printf("-1\n");
        return 0;
    }

    len = (n + 1) / 2;
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            f[i + j - 1].push_back(make_pair(i, j));

    char tmpc[30];
    for (int i = 1; i <= n; i++)
        tmpc[i] = s[n - i + 1];
    for (int i = 1; i <= n; i++)
        s[i] = tmpc[i];

    dfs(n);
    if (ans == 1e18)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}
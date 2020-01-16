#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

unordered_map<ll, pair<int, vector<ll>>> m;
void dfs(ll x, vector<ll> &tmpp) {
    if (!x)
        return;
    if (m[x].ff) {
        tmpp = m[x].ss;
        return;
    }

    ll tmp = 10, res = x;
    vector<ll> minn = vector<ll>(1, x);

    while (x / tmp) {
        ll tmp1 = x / tmp, tmp2 = x % tmp;
        tmpp = vector<ll>(1, x);
        dfs(abs(tmp1 - tmp2), tmpp);
        if (tmpp.back() < res) {
            res = tmpp.back();
            minn = tmpp;
        }
        tmp *= 10;
    }
    if (res != x)
        tmpp = vector<ll>(1, x);
    else
        tmpp.clear();
    for (auto i : minn)
        tmpp.push_back(i);
    m[x] = mp(res, tmpp);
}

int main() {
    for (int i = 1; i <= 9; i++)
        m[i] = mp(i, vector<ll>(1, i));
    int t = 1000;
    scanf("%d", &t);
    while (t--) {
        ll n = t + 1;
        scanf("%lld", &n);
        vector<ll> ans;
        dfs(n, ans);
        if (!m[n].ff)
            m[n] = mp(n, vector<ll>(1, n));
        ans = m[n].ss;
        printf("%d ", ans.size());
        for (auto i : ans)
            printf("%lld ", i);
        printf("\n");
    }
}
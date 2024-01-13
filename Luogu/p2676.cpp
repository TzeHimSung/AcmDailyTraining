#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, b, cur = 0, ans = 0; cin >> n >> b;
    map<int, int>cnt;
    vector<int>high;
    for (int i = 0;i < n;i++) {
        int x;cin >> x;
        cnt[x]++;
        high.push_back(x);
    }
    sort(high.begin(), high.end());
    high.erase(unique(high.begin(), high.end()), high.end());
    for (auto i = high.rbegin();i <= high.rend();i++) {
        while (cur < b && cnt[*i]) {
            cur += *i;
            cnt[*i]--;
            ans++;
        }
        if (cur >= b) {
            cout << ans << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
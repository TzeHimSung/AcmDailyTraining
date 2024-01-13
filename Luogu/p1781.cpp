#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;cin >> n;
    map<int, string>cnt;
    int ans_index = 0;
    string ans_cnt = "0";
    for (int i = 1;i <= n;i++) {
        string x;cin >> x;
        cnt[i] = x;
    }
    for (auto i : cnt) {
        if (i.second.size() > ans_cnt.size() || i.second.size() == ans_cnt.size() && i.second > ans_cnt) {
            ans_cnt = i.second;
            ans_index = i.first;
        }
    }
    cout << ans_index << '\n' << ans_cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
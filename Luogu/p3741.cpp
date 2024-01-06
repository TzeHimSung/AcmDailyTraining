#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    int cnt_vk = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            cnt_vk++;
            s[i] = s[i + 1] = ' ';
        }
    }
    for (int i = 0;i < n - 1;i++) {
        if (s[i] == s[i + 1] && s[i] != ' ') {
            cnt_vk++;
            break;
        }
    }
    cout << cnt_vk << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
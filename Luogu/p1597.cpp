#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    map<char, char>m;
    m['a'] = m['b'] = m['c'] = '0';
    for (int i = 0;i < s.size();i += 5) {
        if ('0' <= s[i + 3] && s[i + 3] <= '9')
            m[s[i]] = s[i + 3];
        else
            m[s[i]] = m[s[i + 3]];
    }
    cout << m['a'] << ' ' << m['b'] << ' ' << m['c'] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
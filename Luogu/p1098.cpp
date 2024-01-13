#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    string s; cin >> s;
    for (int i = 1;i < s.length() - 1;i++) {
        if (s[i] == '-' && (
            (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1]) ||
            (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
            )) {
            s.erase(i, 1);
            string spare = "";
            for (int k = s[i - 1] + 1;k <= s[i] - 1;k++) {
                char ch = (p1 == 3 ? '*' : k);
                if (p1 == 2) ch = toupper(ch);
                for (int j = 1;j <= p2;j++) {
                    spare.push_back(ch);
                }
            }
            if (p3 == 2) {
                reverse(spare.begin(), spare.end());
            }
            s.insert(i, spare);
        }
    }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
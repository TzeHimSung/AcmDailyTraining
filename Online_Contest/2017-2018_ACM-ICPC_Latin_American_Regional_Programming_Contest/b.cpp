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

string s;
vector<int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    pos.clear();
    for (int k = 0; k <= s.size(); k++) {
        char i = s[k];
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            pos.pb(k);
        }
    }
    if (pos.size() && pos[0]) {
        cout << '0' << endl;
        return 0;
    }
    if (!pos.size()) {
        cout << '1' << endl;
        return 0;
    }
    int p = pos[pos.size() / 2], ans = 0;
    if (pos.size() & 1) {
        for (int k = p + 1; k < s.size(); k++) {
            char i = s[k];
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
                break;
            ans++;
        }
    } else {
        for (int k = p - 1; k >= 0; k--) {
            char i = s[k];
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
                break;
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
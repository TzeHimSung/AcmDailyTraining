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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = s.size(), zero = 0, one = 0;
    for (auto i : s) {
        if (i == '0') zero++;
        else one++;
    }
    if (zero == one) {
        if (s[0] == '0') {
            cout << "1";
            for (int i = 0; i < n - 1; i++) cout << "0";
        } else {
            cout << "0";
            for (int i = 0; i < n - 1; i++) cout << "1";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (zero > one) {
                if (s[i] == '0') s[i] = '1';
            } else {
                if (s[i] == '1') s[i] = '0';
            }
        }
        cout << s << endl;
    }
    return 0;
}
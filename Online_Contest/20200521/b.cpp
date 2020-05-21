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

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (auto i : s) {
            if (i == '0') cnt0++; else cnt1++;
        }
        if (!cnt0) {
            cout << s << endl;
        } else if (!cnt1 || cnt1 * 2 + 2 < cnt0) {
            cout << "Impossible" << endl;
        } else if (cnt1 * 2 >= cnt0) {
            int remain = cnt1 - cnt0 / 2;
            if (cnt0 & 1) {
                for (int i = 1; i < remain; i++) cout << "1";
                for (int i = 1; i <= cnt0 / 2; i++) cout << "100";
                cout << "10" << endl;
            } else {
                for (int i = 1; i <= remain; i++) cout << "1";
                for (int i = 1; i <= cnt0 / 2; i++) cout << "100";
                cout << endl;
            }
        } else {
            for (int i = 1; i <= cnt1; i++) cout << "001";
            cnt0 -= cnt1 * 2;
            for (int i = 1; i <= cnt0; i++) cout << "0";
            cout << endl;
        }
    }
    return 0;
}
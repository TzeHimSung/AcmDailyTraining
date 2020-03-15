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

string s, ans = "";
int numC = 0, numS = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (auto ch : s) {
        if (ch == 'C' && numC <= 1) {
            numC++, numS = 0;
            ans += 'B';
        } else if (ch == 'S' && numS <= 1) {
            numS++, numC = 0;
            ans += 'D';
        } else if (ch == 'C') {
            numC = 0, ans += 'P';
        } else if (ch == 'S') {
            numS = 0, ans += 'T';
        }
    }
    cout << ans << endl;
    return 0;
}
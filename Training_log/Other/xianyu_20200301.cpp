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

int minDelete(string s) {
    int dp[500][500] = { 0 };
    int length = s.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0 ; j < length - i; j++) {
            if (j == j + i) {
                dp[j][j + i] = 0;
                continue;
            }
            if (s[j] == s[j + i])
                dp[j][j + i] = dp[j + 1][j + i - 1];
            else
                dp[j][j + i] = min(dp[j + 1][j + i], dp[j][j + i - 1]) + 1;

        }
    }
    return dp[0][length - 1];
}

int main() {
    string s;
    while (cin >> s) cout << minDelete(s) << endl;
    return 0;
}
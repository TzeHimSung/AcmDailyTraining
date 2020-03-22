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

string s, t, ans = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int len1 = s.size(), len2 = t.size();

    function<char(char, char)> convert = [&](char c, char x)->char{
        return (char)('A' + (c - x + 26) % 26);
    };

    for (int i = 0; i < min(len1, len2); i++) ans += convert(s[i], t[i]);
    for (int i = len2; i < len1; i++) ans += convert(s[i], ans[i - len2]);

    cout << ans << endl;
    return 0;
}
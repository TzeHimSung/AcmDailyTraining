#include<iostream>
#include<cstdio>
#include<vector>


using namespace std;
string s;
typedef long long ll;
const int maxn = 1e6;
int f[maxn][4];
int p[maxn];
int main() {
    cin >> s;
    int len = s.length();
    int suf = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (i == len - 1) {
            suf = s[i] - '0';
        } else {
            suf = suf * 10 + s[i] - '0';
        }
        suf %= 3;
        p[i] = suf;
    }
    f[0][p[1]] ++;
    for (int i = 0; i < len; i++) {
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][1];
        f[i][2] = f[i - 1][2];
        f[i][p[i]] ++;
    }
    ll tot = 0;
    ll ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ans++;
            if (i < len - 1 && s[i + 1] != '0') {
                tot = 1ll;
            } else {
                tot++;
            }
        }
        if (tot >= 2 && s[i] == '0' && i > 0 && s[i - 1] != '0') {
            ans += (tot - 1) * tot / 2;
            ans += (f[i][p[i]] - 1) * (tot - 1);
            tot = 0;
        }
    }
    if (tot >= 2) {
        ans += (tot - 1) * tot / 2;
        tot = 0;
    }
    cout << ans << endl;
    return 0;
}
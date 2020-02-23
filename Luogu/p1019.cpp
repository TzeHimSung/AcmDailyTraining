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

const int maxn = 20;
string str[20];
int n, vis[20], ans = 0;

int linkable(string s1, string s2) {
    for (int i = 1; i < min((int)s1.length(), (int)s2.length()); i++) {
        int flag = 1;
        for (int j = 0; j < i; j++)
            if (s1[s1.length() - i + j] != s2[j]) flag = 0;
        if (flag) return i;
    }
    return 0;
}

void solve(string curStr, int curLen) {
    ans = max(ans, curLen);
    for (int i = 0; i < n; i++) {
        if (vis[i] > 1) continue;
        int overlap = linkable(curStr, str[i]);
        if (overlap > 0) {
            vis[i]++;
            solve(str[i], curLen + str[i].length() - overlap);
            vis[i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> str[i];
        vis[i] = 0;
    }
    solve(" " + str[n], 1);
    cout << ans << endl;
    return 0;
}